#include "Cart.h"

int Cart::next_id = 0;

Cart::Cart()
{
    this->id = ++this->next_id;
    this->total = 0;
}

Cart::~Cart()
{
    //dtor
}

Cart::Cart(vector<Product> prods)
{
    this->id = ++this->next_id;
    this->total = 0;

    for (auto& prod : prods) {
        this->total += prod.getPret() * prod.getCantitate();
    }
}

void Cart::schimbaCantitate(Product &prod, int qty)
{
    prod.setCantitate(qty);
}
