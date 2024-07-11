#include "Product.h"
#include <iostream>

using namespace std;

Product::Product()
{
    //ctor
}

Product::~Product()
{
    //dtor
}

Product::Product(int id, string titlu, string vendor, int stock, double pret, double pret_intreg = 0)
{
    this->id = id;
    this->titlu = titlu;
    this->vendor = vendor;
    this->stock = stock;
    this->pret = pret;
    this->pret_intreg = pret_intreg;
}

int Product::getId()
{
    return this->id;
}

string Product::getTitlu()
{
    return this->titlu;
}

string Product::getVendor()
{
    return this->vendor;
}

int Product::getStock()
{
    return this->cantitate;
}

void Product::setStock(int qty)
{
    this->cantitate = qty;
}

double Product::getPret()
{
    return this->pret;
}

double Product::getPretIntreg()
{
    return this->pret_intreg;
}

bool Product::hasID(int id)
{
    return this->getId() == id;
}

void Product::afisare()
{
    cout << this->id << ". " << this->titlu << " - " << this->pret << "/" << this->pret_intreg << ", " << this->stock << endl;
}

void Product::adaugaOferta(double pret_nou)
{
    this->pret_intreg = this->pret;
    this->pret = pret_nou;
}

void Product::modificaOferta(double pret_nou)
{
    this->pret = pret_nou;
}

void Product::stergeOferta()
{
    this->pret = this->pret_intreg;
    this->pret_intreg = 0;
}
