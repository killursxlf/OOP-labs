#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct TourRoute {
    string name;
    double length;
    string difficulty;
    string date;

    void print() const {
        cout << "Name: " << name << " ";
        cout << "Length: " << length << " ";
        cout << "Difficulty: " << difficulty << " ";
        cout << "Date: " << date << endl;
    }
};

struct TourManager {
    vector<TourRoute> routes;
    ofstream logFile;

    TourManager() {
        logFile.open("log.txt", ios::out | ios::binary);
        if (!logFile.is_open()) {
            cerr << "Error opening log file." << endl;
        }
    }

    ~TourManager() {
        logFile.close();
    }

    void addRoute(const TourRoute& route) {
        routes.push_back(route);
        logFile << "Added route: " << route.name << endl;
    }

    void deleteRoute(int index) {
        if (index >= 0 && index < routes.size()) {
            logFile << "Deleted route: " << routes[index].name << endl;
            routes.erase(routes.begin() + index);
        }
        else {
            cerr << "Invalid index." << endl;
        }
    }

    void printAllRoutes() const {
        for (const auto& route : routes) {
            route.print();
        }
    }

    void sortRoutesByLength() {
        sort(routes.begin(), routes.end(), [](const TourRoute& a, const TourRoute& b) {
            return a.length < b.length;
            });
        logFile << "Sorted routes by length." << endl;
    }
};

int main() {
    TourManager manager;

    int choice;
    while (true) {
        cout << "1. Add Route\n"
            "2. Delete Route\n"
            "3. Print All Routes\n"
            "4. Sort Routes by Length\n"
            "5. Exit\n"
            "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            TourRoute newRoute;
            cout << "Enter route name: " << endl;
            cin >> newRoute.name;
            cout << "Enter route length: ";
            cin >> newRoute.length;
            cout << "Enter route difficulty: ";
            cin >> newRoute.difficulty;
            cout << "Enter route date: ";
            cin >> newRoute.date;
            manager.addRoute(newRoute);
            break;
        }
        case 2: {
            int index;
            cout << "Enter index of route to delete: ";
            cin >> index;
            manager.deleteRoute(index);
            break;
        }
        case 3: {
            manager.printAllRoutes();
            break;
        }
        case 4: {
            manager.sortRoutesByLength();
            break;
        }
        case 5: {
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

