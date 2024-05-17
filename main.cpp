#include <iostream>
#include "Airplane.h"
#include "Logger.h"

int main() {

    Logger* logger = Logger::getInstance();

    Airplane airplane1("Boeing 737", 800, 10000);
    airplane1.printInfo();

    logger->addRecord(airplane1.objectName, "name", airplane1.getName());
    logger->addRecord(airplane1.objectName, "speed", to_string(airplane1.getSpeed()));
    logger->addRecord(airplane1.objectName, "height", to_string(airplane1.getHeight()));

    Airplane airplane2("Airbus A320", 750, 9000);
    airplane2.printInfo();
    cout << "Count of airplanes: " << airplane1.getCount() << endl;

    logger->addRecord(airplane2.objectName, "name", airplane2.getName());
    logger->addRecord(airplane2.objectName, "speed", to_string(airplane2.getSpeed()));
    logger->addRecord(airplane2.objectName, "height", to_string(airplane2.getHeight()));

    logger->saveLog();

    return 0;
}
