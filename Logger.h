#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

class Logger {
private:
    static Logger* instance;
    string log;
    string fileName;

    Logger()
    {
        fileName = "log.txt";
    }

    ~Logger() 
    {

    }

public:
    static Logger* getInstance() 
    {
        if (!instance) 
        {
            instance = new Logger();
        }
        return instance;
    }

    void addRecord(const string& objectName, const string& fieldName, const string& fieldValue) 
    {
        log += objectName + ": " + fieldName + " " + fieldValue + "\n";
    }

    void saveLog() 
    {
        ofstream file(fileName);
        if (file.is_open()) 
        {
            file << log;
            string time;
            time = "time: " + getCurrentDateTime();
            file << time;
            log.clear();
            time.clear();
            file.close();
            cout << "Log saved to " << fileName << endl;
        }
        else 
        {
            cerr << "Error saving log to file: " << fileName << endl;
        }
    }

private:
    string getCurrentDateTime()
    {
        SYSTEMTIME st;
        GetLocalTime(&st);
        string datalog;
        datalog += to_string(st.wDay) + ":";
        datalog += to_string(st.wMonth) + ":";
        datalog += to_string(st.wYear) + " ";
        datalog += to_string(st.wHour) + ":";
        datalog += to_string(st.wMinute) + ":";
        datalog += to_string(st.wSecond);
        return datalog;
    }
};
