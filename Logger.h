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

    void addRecord(const string& objectName, const string& fieldName, const string& fieldValue);
    void saveLog();

private:
    string getCurrentDateTime();
};
