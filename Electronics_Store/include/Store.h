#ifndef STORE_H
#define STORE_H
#include "Product.h"
#include "SmartPhone.h"
#include "Laptop.h"
#include "Tablet.h"
#include <vector>

class Store
{
    private:
        vector<Product*> List;
    public:
        void inputProduct();
        void removeProductByID(string id);
        void addProduct(Product*);
        void searchProductByName(string name);
        void displayAllProduct();
        void displayAllSmartPhone();
        void displayAllLaptop();
        void displayAllTablet();
        float sumValueOfAllProduct();
};

#endif // STORE_H
