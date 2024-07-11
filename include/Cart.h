#ifndef CART_H
#define CART_H

#include <vector>
#include <Product.h>

using namespace std;

class Cart
{
    static int next_id;

    int id;
    int total;
    vector<Product> products;

    public:
        Cart();
        ~Cart();

        Cart(vector<Product>);
        void schimbaCantitate(Product &, int);
};

#endif // CART_H
