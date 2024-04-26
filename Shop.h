#ifndef SHOP_H 
#define SHOP_H
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
    vector<pair<string, string>> shop_time_of_work;

public:
    // Getters
    string getShopName();
    string getShopAddress();
    const vector<string>& getListOfProducts();
    int getWorkPlaces();
    int getOccupiedPosts();
    double getShopIncome();
    const vector<pair<string, string>>& getShopTimeOfWork();

    
    void setShopName(const string& name);
    void setShopAddress(const string& address);
    void addProduct(const string& product);
    void setWorkPlaces(const int& workplaces);
    void setOccupiedPosts(const int& occupied);
    void setShopIncome(const double& income);
    void setShopTimeOfWork(const string& first_element, const string& second_element, int i);

};

#endif
