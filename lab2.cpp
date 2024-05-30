#include"Shop.h"

using namespace std;

const int SIZE = 7;

void addSomeProduct(Shop& MyShop)
{
    string product;

    cout << "Enter a product to add (or 'q' to quit): " << endl;

    while (true) {
        cin >> product;

        if (product == "q")
        {
            break;
        }

        MyShop.addProduct(product);
    }
}

void addTimeOfWork(Shop& MyShop)
{
    string day;
    string time;
    int i = 0;

    MyShop.shop_time_of_work.resize(SIZE);

    while (i < 7) {
        cout << "Type a day: " << endl;
        cin >> day;

        cout << "Type time of work: " << endl;
        cin >> time;

        MyShop.setShopTimeOfWork(day, time, i);

        i++;
    }
}

void getListOfProducts(const Shop& MyShop)
{
    vector<string> ListOfProducts = MyShop.getListOfProducts();
    for (auto el : ListOfProducts) {
        cout << el << endl;
    }
}

void getTimeOfWork(const Shop& MyShop)
{
    vector<pair<string, string>> timesOfWork;
    timesOfWork = MyShop.getShopTimeOfWork();
    for (auto el : timesOfWork) {
        cout << "Day : " << el.first << " Time: " << el.second << endl;
    }
}

int main()
{
    Shop MyShop;
    string Name;
    string address;
    int workPlaces;
    int occupiedPosts;
    double income;

    cout << "Type a name of Shop: " << endl;
    getline(cin, Name);
    MyShop.setShopName(Name);
    string shopname = MyShop.getShopName();
    cout << shopname << endl;

    cout << "Type a address of Shop: " << endl;
    cin.ignore();
    getline(cin, address);
    MyShop.setShopAddress(address);
    string shop_address = MyShop.getShopAddress();
    cout << shop_address << endl;

    addSomeProduct(MyShop);
    getListOfProducts(MyShop);

    cout << "Type a number of work places: " << endl;
    cin >> workPlaces;
    MyShop.setWorkPlaces(workPlaces);
    int Shop_workPlaces = MyShop.getWorkPlaces();
    cout << Shop_workPlaces << endl;

    cout << "Type a number of occupied Posts: " << endl;
    cin >> occupiedPosts;
    MyShop.setOccupiedPosts(occupiedPosts);
    int occupied_Posts = MyShop.getOccupiedPosts();
    cout << occupied_Posts << endl;

    cout << "Type shop income: " << endl;
    cin >> income;
    MyShop.setShopIncome(income);
    double shop_income = MyShop.getShopIncome();
    cout << shop_income << endl;

    addTimeOfWork(MyShop);
    getTimeOfWork(MyShop);

    return 0;
}