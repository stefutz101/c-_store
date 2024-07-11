#include "Category.h"
#include <iostream>
#include <algorithm>

using namespace std;

Category::Category()
{
    //ctor
}

Category::~Category()
{
    //dtor
}

Category::Category(int id, string titlu, vector<Product> products)
{
    this->id = id;
    this->titlu = titlu;
    this->products = products;

    this->count = this->products.size();
}

int Category::getId()
{
    return this->id;
}

string Category::getTitlu()
{
    return this->titlu;
}

int Category::getCount() {
    return this->count;
}

vector<Product> Category::getProducts() {
    vector<Product> prods;

    for (auto &prod : this->products) {
        prods.push_back(prod);
    }

    return prods;
}

bool Category::hasProdID(int id)
{
    for (auto &prod : this->products) {
        if (prod.hasID(id)) {
            return true;
        }
    }

    return false;
}

void Category::afisare() {
    cout << this->id << ". " << this->titlu << ", PRODS: " << this->count << endl;
}

void Category::schimbaTitlu(string titlu_nou) {
    this->titlu = titlu_nou;
}

void Category::adaugaProdus(Product const &prod) {
    this->products.push_back(prod);
    this->count++;
}

void Category::stergeProdus(int id) {
    this->products.erase(remove_if(this->products.begin(), this->products.end(),
        [&id, this](Product &prod)->bool {
            return prod.getId() == id && this->count--;
        }), this->products.end());
}
