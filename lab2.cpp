#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Shop
{
private:
    string shop_name;
    string shop_address;
    vector<string> list_of_products;
    int work_places;
    int occupied_posts;
    double shop_income;
    vector<pair<string, string>> shop_timeOfWork;
public:
    // Getters
    string getShopName() const { return shop_name; } // Added const for getter returning data
    string getShopAddress() const { return shop_address; }
    const vector<string>& getListOfProducts() const { return list_of_products; }
    int getWorkPlaces() const { return work_places; }
    int getOccupiedPosts() const { return occupied_posts; }
    double getShopIncome() const { return shop_income; }
    const vector<pair<string, string>>& getShopTimeOfWork() const { return shop_timeOfWork; }

    // Setters 
    void setShopName(const string& name) { shop_name = name; }
    void setShopAddress(const string& address) { shop_address = address; }
    void addProduct(const string& product) { list_of_products.push_back(product); } // Simplified product addition using push_back
    void setWorkPlaces(int workplaces) {
        if (workplaces < 0) {
            cout << "Number of work places cannot be negative." << endl;
        }
        else
        {
            work_places = workplaces;
        }
    }
    void setOccupiedPosts(int occupied) {
        if (occupied > work_places) {
            cout << "Occupied posts cannot exceed work places." << endl;
        }
        else {
            occupied_posts = occupied;
        }
    }
    void setShopIncome(const double& income) { shop_income = income; }
    void setShopTimeOfWork(string first_element, string second_element, int i)
    {
        shop_timeOfWork.resize(7);
        shop_timeOfWork[i].first = first_element;
        shop_timeOfWork[i].second = second_element;
    }

};

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

    while (i < 7) {
        cout << "Type a day: " << endl;
        cin >> day;

        cout << "Type time of work: " << endl;
        cin >> time;

        MyShop.setShopTimeOfWork(day, time, i);

        i++;
    }
}

void getTimeOfWork(Shop& MyShop) {
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
    vector<string> ListOfProducts = MyShop.getListOfProducts();
    for (auto el : ListOfProducts) {
        cout << el << endl;
    }

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