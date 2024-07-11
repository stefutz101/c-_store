#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <Product.h>

using namespace std;

class Order
{
    int id;
    string status="pending";
    vector<Product> products;
    int count=0;
    double total=0;

    public:
        Order();
        ~Order();

        Order(int, string, vector<Product>);
        int getId();
        string getStatus();

        vector<Product> getProducts();

        void afisare();
        void changeStatus(string);

        void adaugaProdus(Product const&);
        void stergeProdus(int);
};

#endif // ORDER_H
