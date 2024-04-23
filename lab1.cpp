#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAXLEN = 255;
const string FILE_NAME = "myFile.txt";

struct TourRoute
{
    char name[MAXLEN];
    double length;
    char difficulty[MAXLEN];
    char date[MAXLEN];
    int index;

    void print()
    {
        cout << "Index: " << index << ". ";
        cout << "Name: " << name << " ";
        cout << "Length: " << length << " ";
        cout << "Difficulty: " << difficulty << " ";
        cout << "Date: " << date << endl;
    }
};


void addRoute(const TourRoute& route)
{
    ofstream fin;
    fin.open(FILE_NAME, ios::binary | ios::app);

    if (!fin.is_open())
    {
        cout << "Failed to open file for writing." << endl;
        return;
    }
    else
    {
        fin.write((char*)&route, sizeof(TourRoute));
        fin.close();
    }
}


void readFile(vector<TourRoute>& routes)
{

    ifstream file_in(FILE_NAME, ios::binary);

    if (file_in.is_open())
    {
        TourRoute temp;

        while (file_in.read((char*)&temp, sizeof(TourRoute)))
        {
            routes.push_back(temp);
        }
        file_in.close();
    }
    else
    {
        cout << "Cant open the file." << endl;
    }
}


void writeInFile(vector<TourRoute>& routes)
{
    ofstream fout(FILE_NAME, ios::binary);
    if (!fout.is_open())
    {
        cout << "Failed to open file for writing." << endl;
        return;
    }
    else 
    {
        for (const auto& route : routes)
        {
            fout.write((char*)&route, sizeof(TourRoute));
        }
        fout.close();
    }
}


void printAllRoutes()
{
    ifstream fon;
    fon.open(FILE_NAME);
    if (!fon.is_open())
    {
        cout << "Cant open the file, mb u need add the route!" << endl;
    }
    else
    {
        TourRoute temp;

        while (fon.read((char*)&temp, sizeof(TourRoute)))
        {
            temp.print();
        }
        fon.close();
    }
}


bool compareByLength(const TourRoute& route1, const TourRoute& route2)
{
    return route1.length < route2.length;
}


void sortRoutesByLength(vector<TourRoute>& routes)
{
    sort(routes.begin(), routes.end(), compareByLength);

    writeInFile(routes);
}


int getNextIndex(const vector<TourRoute>& routes)
{
    int maxIndex = 0;
    for (const auto& route : routes)
    {
        if (route.index > maxIndex)
        {
            maxIndex = route.index;
        }
    }
    return maxIndex;
}


void deleteRoute(int indexToDelete)
{
    vector<TourRoute> routes;
    readFile(routes);

    auto it = remove_if(routes.begin(), routes.end(), [indexToDelete](const TourRoute& route) {
        return route.index == indexToDelete;
        });

    if (it == routes.end())
    {
        cout << "Route with index " << indexToDelete << " not found." << endl;
        return;
    }

    routes.erase(it, routes.end());

    writeInFile(routes);
    cout << "Route deleted successfully." << endl;
}


int menu()
{
    cout << "\n";
    int choice;
    cout << " 1. Add Route\n"
        " 2.Delete Route\n "
        " 3. Print All Routes\n"
        " 4. Sort Routes by Length\n "
        " 5. Exit\n"
        " Enter your choice : " << endl;
    cin >> choice;
    return choice;
}


void fillTheStructure(TourRoute& newRoute)
{
    cout << "Enter route name: " << endl;
    cin >> newRoute.name;
    cout << "Enter route length: ";
    cin >> newRoute.length;
    cout << "Enter route difficulty: ";
    cin >> newRoute.difficulty;
    cout << "Enter route date: ";
    cin >> newRoute.date;
    newRoute.index = getNextIndex(routes) + 1;
}


int main()
{

    vector<TourRoute> routes;
    readFile(routes);

    while (true)
    {
        switch (menu())
        {
        case 1: {
            TourRoute newRoute;
            fillTheStructure(newRoute);
            addRoute(newRoute);
            routes.push_back(newRoute);
            break;
        }
        case 2: {
            int index;
            cout << "Enter index of route to delete: ";
            cin >> index;
            deleteRoute(index);
            break;
        }
        case 3: {
            printAllRoutes();
            break;
        }
        case 4: {
            sortRoutesByLength(routes);
            break;
        }
        case 5: {
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
