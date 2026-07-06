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

class Logger{

    ofstream logfile;
    mutex writemtx;
    severity minSeverity;
    logSaveChoice logChoice;
    public:
        Logger(const string& AppName, severity mini,logSaveChoice c): logfile(AppName + ".log", std::ios::app), minSeverity(mini), logChoice(c){

            if (!logfile) {
                throw runtime_error("Failed to open log file");
            }
            // log("application started", level);
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

        auto getTime(){
            auto now = chrono::system_clock::now();

            time_t currentTime = chrono::system_clock::to_time_t(now);
            
        
            return put_time(localtime(&currentTime),
                        "%Y-%m-%d %H:%M:%S");
        }

        void log(string msg, severity level){

            if(static_cast<int>(level) < static_cast<int>(minSeverity)) return;

            auto t = getTime();
            string lev = toString(level);

            lock_guard<mutex> lock(writemtx);
            if(logChoice == logSaveChoice::LOGFILE){
             logfile<<t<<": ["<<lev<<"]"<<": "<<msg<<"\n";  
             // this whole line is atomic event
            }
            else if(logChoice == logSaveChoice::CONSOLE){
                          
                cout<<t<<": ["<<lev<<"]"<<": "<<msg<<"\n";  // this line is atomic 
            }
            else{
                logfile<<t<<": ["<<lev<<"]"<<": "<<msg<<"\n";   // this whole block is atomic 
                cout<<t<<": ["<<lev<<"]"<<": "<<msg<<"\n";
            }
            
            
            
            
        }

};