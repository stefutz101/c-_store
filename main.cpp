#include <iostream>
#include <Product.h>
#include <Category.h>
#include <Order.h>
#include <Files.h>
#include <Functions.hpp>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);

    read_products();
    read_categories();
    read_orders();

    int s = 0;

    while(1 != 0) {
        switch(s) {
            case 0:
                SetConsoleTextAttribute(hConsole, 12);
                cout << "[*** MENIU PRINCIPAL ***]" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "1. Administrare categorii" << endl;
                cout << "2. Administrare produse din categorii" << endl;
                cout << "3. Administrare oferte produse" << endl;
                cout << "4. Administrare comenzi" << endl;
                cout << "5. Iesire aplicatie" << endl;

                cout << "Introdu optiunea dorita: ";
                cin >> s;

                break;
            case 1:
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "[*** Administrare categorii ***]" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "0. Meniu principal" << endl;
                    cout << "(M)odificare categorie" << endl;
                    cout << "(A)daugare categorie" << endl;
                    cout << "(S)tergere categorie" << endl;

                    char c;
                    cout << "Introdu optiunea dorita: ";
                    cin >> c;

                    system("cls");

                    while(s != 0) {
                        switch(c) {
                            case 'm':
                            case 'M':
                                {
                                    cout << "[*** Modificare categorie ***]" << endl;
                                    for (auto &cat : all_categories) {
                                        cat.afisare();
                                    }

                                    int id=0;
                                    cout << "Introdu optiunea dorita: ";
                                    cin >> id;

                                    system("cls");

                                    cout << "[*** Modificare categorie ***]" << endl;

                                    for (auto &cat : all_categories) {
                                        if (id == cat.getId()) {
                                            cat.afisare();

                                            string titlu;
                                            cout << "Introdu noul titlu: ";
                                            cin.ignore();
                                            getline(cin, titlu);

                                            cat.schimbaTitlu(titlu);

                                            break;
                                        }
                                    }

                                    write_categories();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            case 'a':
                            case 'A':
                                {
                                    cout << "[*** Adauga o categorie ***]" << endl;

                                    int id=0;
                                    cout << "Introdu idul categoriei: ";
                                    cin >> id;

                                    string titlu;
                                    cout << "Introdu titlul categoriei: ";
                                    cin.ignore();
                                    getline(cin, titlu);

                                    vector<Product> prods;
                                    Category cat(id, titlu, prods);
                                    all_categories.push_back(cat);

                                    write_categories();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            case 's':
                            case 'S':
                                {
                                    cout << "[*** Stergere categorie ***]" << endl;
                                    for (auto &cat : all_categories) {
                                        cat.afisare();
                                    }

                                    int id=0;
                                    cout << "Introdu optiunea dorita: ";
                                    cin >> id;
                                    stergeCategorie(id);

                                    write_categories();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            default:
                                s=0;
                        }
                    }

                    break;
                }
            case 2:
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "[*** Administrare produse din categorii ***]" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "0. Meniu principal" << endl;
                    cout << "(A)daugare produse in o categorie" << endl;
                    cout << "(S)tergere produse din o categorie" << endl;

                    char c;
                    cout << "Introdu optiunea dorita: ";
                    cin >> c;

                    system("cls");

                    while(s != 0) {
                        switch(c) {
                            case 'a':
                            case 'A':
                                {
                                    cout << "[*** Adauga produse in o categorie ***]" << endl;
                                    for (auto &cat : all_categories) {
                                        cat.afisare();
                                    }

                                    int id=0;
                                    cout << "Introdu categoria in care vrei sa adaugi produse: ";
                                    cin >> id;

                                    Category &category = getCategoryByID(id);

                                    for (auto &prod : all_products) {
                                        prod.afisare();
                                    }

                                    while (1 != 0) {
                                        cout << "Id-ul produsului pe care vrei sa-l adaugi in '" << category.getTitlu() << "': ";
                                        cin >> id;

                                        if (id == 0) break;

                                        Product product = getProductByID(id);
                                        category.adaugaProdus(product);
                                    }

                                    write_categories();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            case 's':
                            case 'S':
                                {
                                    cout << "[*** Stergere produse din o categorie ***]" << endl;
                                    for (auto &cat : all_categories) {
                                        cat.afisare();
                                    }

                                    int id=0;
                                    cout << "Introdu categoria din care vrei sa stergi produse: ";
                                    cin >> id;

                                    Category &category = getCategoryByID(id);

                                    while (1 != 0) {
                                        for (auto &prod : category.getProducts()) {
                                            prod.afisare();
                                        }

                                        cout << "Id-ul produsului pe care vrei sa-l stergi din '" << category.getTitlu() << "': ";
                                        cin >> id;

                                        if (id == 0) break;

                                        category.stergeProdus(id);
                                    }

                                    write_categories();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            default:
                                s=0;
                        }
                    }

                    break;
                }
            case 3:
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "[*** Administrare oferte produse ***]" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "0. Meniu principal" << endl;
                    cout << "(M)odificare oferta" << endl;
                    cout << "(A)daugare oferta" << endl;
                    cout << "(S)tergere oferta" << endl;

                    char c;
                    cout << "Introdu optiunea dorita: ";
                    cin >> c;

                    system("cls");

                    while(s != 0) {
                        switch(c) {
                            case 'm':
                            case 'M':
                                {
                                    cout << "[*** Modifica oferta ***]" << endl;
                                    for (auto &prod : all_products) {
                                        if (prod.getPretIntreg() != 0)
                                            prod.afisare();
                                    }

                                    int id=0;
                                    while (1 != 0) {
                                        cout << "ID-ul produs: ";
                                        cin >> id;

                                        if (id == 0) break;


                                        Product &product = getProductByID(id);

                                        double pret = 0;
                                        cout << "Introdu noua oferta pt. '" << product.getTitlu() << "': ";
                                        cin >> pret;

                                        product.modificaOferta(pret);
                                        product.afisare();
                                    }

                                    write_products();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            case 'a':
                            case 'A':
                                {
                                    cout << "[*** Adaugare oferta ***]" << endl;
                                    for (auto &prod : all_products) {
                                        if (prod.getPretIntreg() == 0)
                                            prod.afisare();
                                    }

                                    int id=0;
                                    while (1 != 0) {
                                        cout << "ID-ul produs: ";
                                        cin >> id;

                                        if (id == 0) break;

                                        Product &product = getProductByID(id);

                                        double pret = 0;
                                        cout << "Introdu oferta pt. '" << product.getTitlu() << "': ";
                                        cin >> pret;

                                        product.adaugaOferta(pret);
                                        product.afisare();
                                    }

                                    write_products();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            case 's':
                            case 'S':
                                {
                                    cout << "[*** Stergere oferta ***]" << endl;
                                    for (auto &prod : all_products) {
                                        if (prod.getPretIntreg() != 0)
                                            prod.afisare();
                                    }

                                    int id=0;
                                    while (1 != 0) {
                                        cout << "ID-ul produs: ";
                                        cin >> id;

                                        if (id == 0) break;

                                        Product &product = getProductByID(id);
                                        product.stergeOferta();
                                        product.afisare();
                                    }

                                    write_products();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            default:
                                s=0;
                        }
                    }

                    break;
                }
            case 4:
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "[*** Administrare comenzi ***]" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "0. Meniu principal" << endl;
                    cout << "(S)chimba status comanda" << endl;
                    cout << "S(T)erge produse din comanda" << endl;

                    char c;
                    cout << "Introdu optiunea dorita: ";
                    cin >> c;

                    system("cls");

                    while(s != 0) {
                        switch(c) {
                            case 's':
                            case 'S':
                                {
                                    cout << "[*** Schimba status comanda ***]" << endl;
                                    for (auto &order : all_orders) {
                                        order.afisare();
                                    }

                                    int id=0;
                                    while (1 != 0) {
                                        cout << "Introdu idul comenzii: ";
                                        cin >> id;

                                        if (id == 0) break;

                                        Order &order = getOrderByID(id);

                                        for (auto &prod : order.getProducts()) {
                                            prod.afisare();
                                        }

                                        string status;
                                        cout << "Introdu noul status al comenzii: ";
                                        cin.ignore();
                                        getline(cin, status);

                                        order.changeStatus(status);
                                        order.afisare();
                                    }

                                    write_orders();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            case 't':
                            case 'T':
                                {
                                    cout << "[*** Sterge produse din comanda ***]" << endl;
                                    for (auto &order : all_orders) {
                                        order.afisare();
                                    }

                                    int id=0;
                                    cout << "Introdu idul comenzii: ";
                                    cin >> id;

                                    Order &order = getOrderByID(id);
                                    while (1 != 0) {
                                        for (auto &prod : order.getProducts()) {
                                            prod.afisare();
                                        }

                                        cout << "Introdu idul produsului pe care doresti sa il stergi: ";
                                        cin >> id;

                                        if (id == 0) break;

                                        order.stergeProdus(id);
                                    }

                                    write_orders();
                                    c = '0';
                                    system("cls");

                                    break;
                                }
                            default:
                                s=0;
                        }
                    }

                    break;
                }
            case 5:
                write_products();
                write_categories();
                write_orders();

                exit(0);
                break;
        }
        system("cls");
    }

    return 0;
}
