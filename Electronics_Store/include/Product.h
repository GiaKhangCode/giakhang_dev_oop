#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>

using namespace std;

class Product
{
    protected:
        string id;
        string name;
        string brand;
        float price;
        int quantity;
    public:
        Product(string id = "None", string name = "None", string brand = "None", float price = 0, int quantity = 0);
        virtual void inputInfo();
        virtual void displayInfo();
        virtual float calculateDiscountedPrice(float discountPercentage);
        string getID();
        string getName();
        bool isSmartPhone();
        bool isLaptop();
        bool isTablet();
};

#endif // PRODUCT_H
