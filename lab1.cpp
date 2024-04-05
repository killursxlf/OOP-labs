#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const string path = "myFile.txt";
const int maxlen = 255;

struct TourRoute
{
    char name[maxlen];
    double length;
    char difficulty[maxlen];
    char date[maxlen];
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
    fin.open(path, ios::binary | ios::app);
    fin.write((char*)&route, sizeof(TourRoute));
    fin.close();
}



void printAllRoutes()
{
    ifstream fon;
    fon.open(path);
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

    ofstream fout(path, ios::binary);
    if (!fout.is_open())
    {
        cout << "Failed to open file for writing." << endl;
        return;
    }

    for (const auto& route : routes)
    {
        fout.write((char*)&route, sizeof(TourRoute));
    }

    fout.close();
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

    ifstream fin(path);
    if (!fin.is_open())
    {
        cout << "Failed to open file for reading." << endl;
        return;
    }

    TourRoute temp;
    while (fin.read((char*)&temp, sizeof(TourRoute)))
    {
        routes.push_back(temp);
    }
    fin.close();


    auto it = remove_if(routes.begin(), routes.end(), [indexToDelete](const TourRoute& route) {
        return route.index == indexToDelete;
        });


    if (it == routes.end())
    {
        cout << "Route with index " << indexToDelete << " not found." << endl;
        return;
    }


    routes.erase(it, routes.end());


    ofstream fout(path, ios::binary);
    if (!fout.is_open())
    {
        cout << "Failed to open file for writing." << endl;
        return;
    }

    for (const auto& route : routes)
    {
        fout.write((char*)&route, sizeof(TourRoute));
        cout << "Route deleted successfully." << endl;
    }
    fout.close();
}


int menu()
{
    cout << "\n";
    int choice;
    cout << "1. Add Route\n";
    cout << "2. Delete Route\n";
    cout << "3. Print All Routes\n";
    cout << "4. Sort Routes by Length\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}


int main()
{

    vector<TourRoute> routes;

    ifstream file_in(path, ios::binary);
    if (file_in.is_open())
    {
        TourRoute temp;
        while (file_in.read((char*)&temp, sizeof(TourRoute)))
        {
            routes.push_back(temp);
        }
        file_in.close();
    }

    while (true)
    {

        switch (menu())
        {
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
            newRoute.index = getNextIndex(routes) + 1;
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
