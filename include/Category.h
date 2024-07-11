#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>
#include <Product.h>

using namespace std;

class Category
{
    int id;
    int count=0;
    string titlu;
    vector<Product> products;

    public:
        Category();
        ~Category();

        Category(int, string, vector<Product>);
        int getId();
        string getTitlu();
        int getCount();

        vector<Product> getProducts();
        bool hasProdID(int);

        void afisare();
        void schimbaTitlu(string);

        void afisareProduse();
        void adaugaProdus(Product const&);
        void stergeProdus(int);
};

#endif // CATEGORY_H
