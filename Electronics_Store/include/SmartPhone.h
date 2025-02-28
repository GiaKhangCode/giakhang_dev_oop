#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "Product.h"

class SmartPhone: public Product
{
    protected:
        int ram;
        int storage;
        int camera;
    public:
        SmartPhone(string id = "None", string name = "None", string brand = "None",
                    float price = 0, int quantity = 0, int ram = 0, int storage = 0, int camera = 0);
        void inputInfo();
        void displayInfo();
        float calculateDiscountedPrice(float discountPercentage);
};

#endif // SMARTPHONE_H
