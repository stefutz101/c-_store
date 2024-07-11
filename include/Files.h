#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

vector<Product> all_products;
vector<Category> all_categories;
vector<Order> all_orders;

void read_products() {
    ifstream products("products.txt");

    if (products.is_open()) {
        string line;

        while (getline(products, line)) {
            //printf("%s", line.c_str());

            stringstream ss( line.c_str() );
            vector<string> res;

            while(ss.good()) {
                string substr;
                getline(ss, substr, ',');
                res.push_back(substr);
            }

            Product p(stoi(res[0]), res[1], res[2], stoi(res[3]), stod(res[4]), stod(res[5]));
            all_products.push_back(p);
        }

        products.close();
    }
}

void write_products() {
    ofstream products("products.txt");

    if (products.is_open()) {
        for (auto &product : all_products) {
            products << product.getId() << "," << product.getTitlu() << "," << product.getVendor() << "," << product.getStock() << "," << product.getPret() << "," << product.getPretIntreg() << endl;
        }

        products.close();
    }
}

void read_categories() {
    ifstream categories("categories.txt");

    if (categories.is_open()) {
        string line;

        while (getline(categories, line)) {
            stringstream ss( line.c_str() );
            vector<string> res;

            int length = 0;
            while(ss.good()) {
                string substr;
                getline(ss, substr, ',');
                res.push_back(substr);
                length++;
            }

            vector<Product> prods;
            for (int i=2; i<length; i++) {
                for (auto &product : all_products) {
                    if ( stod(res[i]) != 0 && product.hasID(stod(res[i])) ) {
                        prods.push_back(product);
                    }
                }
            }
            Category c(stoi(res[0]), res[1], prods);

            all_categories.push_back(c);
        }

        categories.close();
    }
}

void write_categories() {
    ofstream categories("categories.txt");

    if (categories.is_open()) {
        for (auto &category : all_categories) {
            string prods;

            for (auto &product : category.getProducts()) {
                prods += to_string(product.getId()) + ",";
            }

            if (!prods.empty()) {
                prods.pop_back();
            } else {
                prods = "0";
            }

            categories << category.getId() << "," << category.getTitlu() << "," << prods << endl;
        }

        categories.close();
    }
}

void read_orders() {
    ifstream orders("orders.txt");

    if (orders.is_open()) {
        string line;

        while (getline(orders, line)) {
            //printf("%s", line.c_str());

            stringstream ss( line.c_str() );
            vector<string> res;

            int length = 0;
            while(ss.good()) {
                string substr;
                getline(ss, substr, ',');
                res.push_back(substr);
                length++;
            }

            vector<Product> prods;
            for (int i=2; i<length; i++) {
                for (auto &product : all_products) {
                    if ( stod(res[i]) != 0 && product.hasID(stod(res[i])) ) {
                        prods.push_back(product);
                    }
                }
            }
            Order o(stoi(res[0]), res[1], prods);
            all_orders.push_back(o);
        }

        orders.close();
    }
}

void write_orders() {
    ofstream orders("orders.txt");

    if (orders.is_open()) {
        for (auto &order : all_orders) {
            string prods;

            for (auto &product : order.getProducts()) {
                prods += to_string(product.getId()) + ",";
            }

            if (!prods.empty()) {
                prods.pop_back();
            } else {
                prods = "0";
            }

            orders << order.getId() << "," << order.getStatus() << "," << prods << endl;
        }

        orders.close();
    }
}

#endif // FILES_H_INCLUDED
