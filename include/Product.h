#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product
{
    int id;
    string titlu;
    string vendor;
    int stock;
    double pret;
    double pret_intreg = 0;
    int cantitate = 0;

    public:
        Product();
        ~Product();

        Product(int, string, string, int, double, double);
        int getId();
        string getTitlu();
        string getVendor();
        int getStock();
        void setStock(int);
        double getPret();
        double getPretIntreg();

        bool hasID(int);

        void afisare();
        void adaugaOferta(double pret_nou);
        void modificaOferta(double pret_nou);
        void stergeOferta();
};

#endif // PRODUCT_H
