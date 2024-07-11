#include "Order.h"
#include <iostream>
#include <algorithm>

using namespace std;

Order::Order()
{
    //ctor
}

Order::~Order()
{
    //dtor
}

Order::Order(int id, string status, vector<Product> products)
{
    this->id = id;
    this->status = status;
    this->products = products;
    this->count = this->products.size();

    for (auto &prod : this->products) {
        this->total += (prod.getPretIntreg() == 0 ? prod.getPret() : prod.getPretIntreg());
    }
}

int Order::getId()
{
    return this->id;
}

string Order::getStatus() {
    return this->status;
}

vector<Product> Order::getProducts() {
    vector<Product> prods;

    for (auto &prod : this->products) {
        prods.push_back(prod);
    }

    return prods;
}

void Order::afisare()
{
    cout << this->id << ". " << this->status << ", TOTAL: " << this->total << ", PRODS: " << this->count << endl;
}

void Order::changeStatus(string status)
{
    this->status = status;
}

void Order::adaugaProdus(Product const &prod) {
    this->products.push_back(prod);
    this->count++;
}

void Order::stergeProdus(int id) {
    this->products.erase(remove_if(this->products.begin(), this->products.end(),
        [&id, this](Product &prod)->bool {
            return prod.getId() == id && this->count--;
        }), this->products.end());
}
