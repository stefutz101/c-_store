#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#include <algorithm>

using namespace std;

void stergeCategorie(int id) {
    all_categories.erase(remove_if(all_categories.begin(), all_categories.end(),
        [&id](Category &cat)->bool {
            return cat.getId() == id;
        }), all_categories.end());
}

Category &getCategoryByID(int id) {
    for (auto &cat : all_categories) {
        if (id == cat.getId())
            return cat;
    }
}

Product &getProductByID(int id) {
    for (auto &prod : all_products) {
        if (id == prod.getId())
            return prod;
    }
}

Order &getOrderByID(int id) {
    for (auto &order : all_orders) {
        if (id == order.getId())
            return order;
    }
}

#endif // FUNCTIONS_HPP_INCLUDED
