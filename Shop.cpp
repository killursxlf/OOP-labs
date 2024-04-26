#include"Shop.h"

using namespace std;

string Shop::getShopName() const { return shop_name; }
string Shop::getShopAddress() const { return shop_address; }
vector<string> Shop::getListOfProducts() const { return list_of_products; }
int Shop::getWorkPlaces() const { return work_places; }
int Shop::getOccupiedPosts() const { return occupied_posts; }
double Shop::getShopIncome() const { return shop_income; }
vector<pair<string, string>> Shop::getShopTimeOfWork() const { return shop_time_of_work; }


void Shop::setShopName(const string& name) { shop_name = name; }
void Shop::setShopAddress(const string& address) { shop_address = address; }
void Shop::addProduct(const string& product) { list_of_products.push_back(product); }
void Shop::setWorkPlaces(const int& workplaces)
{
    if (workplaces < 0)
    {
        cout << "Number of work places cannot be negative." << endl;
    }
    else
    {
        work_places = workplaces;
    }
}
void Shop::setOccupiedPosts(const int& occupied)
{
    if (occupied > work_places)
        cout << "Occupied posts cannot exceed work places." << endl;
    else
        occupied_posts = occupied;
}
void Shop::setShopIncome(const double& income) { shop_income = income; }
void Shop::setShopTimeOfWork(const string& first_element, const string& second_element, int i)
{
 
    shop_time_of_work[i].first = first_element;
    shop_time_of_work[i].second = second_element;
}
