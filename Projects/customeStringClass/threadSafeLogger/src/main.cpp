#include<bits/stdc++.h>
using namespace std;

enum class severity{
    TRACE,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    FATAL,
    Count
};


enum class logSaveChoice{   // tells where to output log in logfile, in console or in both, 
    LOGFILE,
    CONSOLE,
    BOTH
};


struct LogEntry {
    chrono::system_clock::time_point timestamp;
    severity level;
    string message;
};


class Logger{

    ofstream logfile;       
    mutex writemtx;    
    mutex Qmtx;
    severity minSeverity;
    logSaveChoice logChoice;
    queue<LogEntry> logQ;             // waiting queue 
    condition_variable cv;

    thread workerThread;
    bool stopReq = false;



    public:
        Logger(const string& AppName, severity mini,logSaveChoice c): logfile(AppName + ".log", std::ios::app), minSeverity(mini), logChoice(c){

            if (!logfile) {
                throw runtime_error("Failed to open log file");
            }

            workerThread = thread(&Logger::processLog, this);
            
        }

        ~Logger(){

            {
                lock_guard<mutex> lock(Qmtx);  
                stopReq = true;                 // this is to tell the worker thread that write remaining logs (no new data will come) and then exit

            }

            workerThread.join();                // waiting for worker thread to finish.  
        }

        string toString(const severity& level){
            switch(level){
                case severity::TRACE: return "TRACE";
                case severity::CRITICAL: return "CRITICAL";
                case severity::DEBUG: return "DEBUG";
                case severity::ERROR: return "ERROR";
                case severity::FATAL: return "FATAL";
                case severity::WARNING: return "WARNING";
                case severity::INFO: return "INFO";
            }

            return "UNKNOWN";
        }

        auto getTime(chrono::system_clock::time_point timestamp){

            time_t currentTime = chrono::system_clock::to_time_t(timestamp);
            
        
            return put_time(localtime(&currentTime),
                        "%Y-%m-%d %H:%M:%S");
        }


        void log(string msg, severity level){                    // log is producer

            if(static_cast<int>(level) < static_cast<int>(minSeverity)) return;  // if severity is less then minimum severity then do not put it in waiting queue, hence not in logfile 

            LogEntry entry;                                          
            entry.level=level;                                                                                       
            entry.message = msg;                                      // here we are getting all the log information which is to be pushed in waiting queue(logQ);
            entry.timestamp =  chrono::system_clock::now();             
            
            lock_guard<mutex> lock(Qmtx);              // locking the mutex of queue
            logQ.push(move(entry));                   //entry wont be used further so move it inside logQ 
            
        }

    private: 
        void processLog(){                 // process log is consumer. 

            while(true){         // this will keep running once the logger object is created. 
                LogEntry entry;
                {
                lock_guard<mutex> lock(Qmtx);   // lock the Qmtx we are going to fetch the data from waiting to put it inside Logfile.

                    if(stopReq && logQ.empty()){ 
                        break;                            // this is when main thread reaches the destructor and not data will come so if log is not empty put all data in logfile then exit from worker thread. 
                    }
                    
                    if(logQ.empty()){
                    continue;                        // if Q is empty wait log data may come in future(its busy waiting);
                    }
                    entry = logQ.front();           // getting data from Q;
                    logQ.pop();                  
                    
                }
                

            auto t = getTime(entry.timestamp);
            string lev = toString(entry.level);



            lock_guard<mutex> lock(writemtx);                           // writing the data in Logfile and terminal so making the write process thread safe.
            if(logChoice == logSaveChoice::LOGFILE){
             logfile<<t<<": ["<<lev<<"]"<<": "<<entry.message<<"\n";  
             // this 
            }
            else if(logChoice == logSaveChoice::CONSOLE){
                          
                cout<<t<<": ["<<lev<<"]"<<": "<<entry.message<<"\n";  
            }
            else{
                logfile<<t<<": ["<<lev<<"]"<<": "<<entry.message<<"\n";  
                cout<<t<<": ["<<lev<<"]"<<": "<<entry.message<<"\n";
            } 

            }
        
        }

};


int main(){

    Logger logger("BankingApp", severity::WARNING,logSaveChoice::BOTH);
    logger.log("Application Started", severity::FATAL);

    return 0;
}