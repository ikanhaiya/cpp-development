// #include<bits/stdc++.h>
#include "../src/Logger.cpp"
using namespace std;

// this test code, tests against the safety of the logger, can any thread interrupt or corrupt message of other thread

void worker(Logger& logger, int threadId)
{
    vector<string> messages = {
        "Application Started",
        "User Logged In",
        "Payment Successful",
        "Database Connected",
        "Transaction Failed",
        "Server Shutdown",
        "Database Disconnected",
        "User Logged Out",
        "Server unexpectedly Disconnected",
        "User Credential Failed"
    };

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> msgDist(0, messages.size() - 1);

    int n = static_cast<int>(severity::Count);
    uniform_int_distribution<> levelDist(0, n - 1);

    for (int i = 0; i < 1000; i++)
    {
        string msg = "Thread " + to_string(threadId) + " : " +
                     messages[msgDist(gen)];

        severity level = static_cast<severity>(levelDist(gen));

        logger.log(msg, level);
    }
}

int main(){

 Logger logger2("test");

 vector<thread> threadPool;

    for (int i = 0; i < 1000; i++)
    {
        threadPool.emplace_back(worker, ref(logger2), i + 1); // emplace back created thread inside vector itself no extra copy created 
    }

    for (auto& t : threadPool)
    {
        t.join();
    }

    return 0;
}