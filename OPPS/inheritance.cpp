#include<bits/stdc++.h>
using namespace std;

// public inheritance 

class Emp{

    protected: 
        string name;
        int id;
        double salary;
    
    public: 
        Emp(string n,int i, double s): name(n), id(i), salary(s){}  // constructor list initializer 


        void displayEmp() {
            cout<<"Name: "<< name<< endl;
            cout<<"ID: "<< id<<endl;
            cout<<"Salary: "<< salary<< endl;
        }

};

/* why public inheritance: because Manager IS-A Employee 
 Manager class objects can directly access the member functions of the Emp class because every manager is also a employee 
*/

class Manager : public Emp{

    private: 
        int teamSize;

    public:
        Manager(string n,int i, double s, int t) : Emp(n, i, s), teamSize(t) {}

        void displayMananger(){
            displayEmp();
            cout<<"Team Size: "<<teamSize<<endl;
        }

};

// <------------------------------------------------------------------------------------------------------------------------------------->

class Logger{
    protected:
    int totalLogs;

    public: 
        Logger(){
            totalLogs = 0;
        }

        void writeLog(string msg){
            totalLogs++;

            cout<< "[LOG] "
            <<msg<<endl;
        }

        int getLogCount() {
            return totalLogs;
        }
};

/* Protected Inheritance: Suppose we are building database system. 
user should not access logging functionality directly

Database USES Logger Database IS NOT Logger  --> thats why we are using protected Database object in main function can't directly access the 
the member functions of the logger class;
*/

class Database : protected Logger{
    private: 
        string dbName;

    
    public: 
        Database(string name){
            dbName = name;
        }

        void insertRecord(){

            writeLog("Insert Operation");

            cout<<"Record inserted into "<<dbName<<endl; 

        }

        void showStats() {

            cout<<"Total Logs = "<< getLogCount()<<endl;
        }
};

// <----------------------------------------------------->

class Counter{

    private: 
        int cnt;

    public: 
        Counter(){
            cnt = 0;
        }
    
        void increment(){
            cnt++;
        }

        void decrement(){
            cnt--;
        }

        int getCnt(){
            return cnt;
        }

};

/* Private inheritance: Download Mananger uses Counter DownloadManager is not a counter*/

class DownloadManager : private Counter{
    
    private: 
        string fileName;
    
    public:
        DownloadManager(string name){
            fileName = name;
        }
    
        void downloadChunck(){

            increment();
            cout<<"Downloaded Chunk of "<<fileName<<endl;
        }

        void showProgress(){
            cout<<"Chunks downloaded = "
            <<getCnt()<<endl;
        }
};

// if we make further class and inherit download manager we wont be able to use logger member functions because download manager inherited logger class privately





int main(){

    Manager m("Sam", 101,80900,8);

    m.displayMananger();
    m.displayEmp();

    Database db("EmpDB");

    db.insertRecord();
    db.insertRecord();
    db.insertRecord();

    db.showStats();

    // db.writeLog("test");  writeLog is of Logger class not db class 

    return 0;
}