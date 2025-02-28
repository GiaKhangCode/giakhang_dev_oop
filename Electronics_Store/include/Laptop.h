#ifndef LAPTOP_H
#define LAPTOP_H
#include "Product.h"

class Laptop: public Product
{
    protected:
        string cpu;
        int ram;
        int storage;
        string gpu;
    public:
        Laptop(string id = "None", string name = "None", string brand = "None",
                    float price = 0, int quantity = 0, string cpu = "None",
                     int ram = 0, int storage = 0, string gpu = "None");
        void inputInfo();
        void displayInfo();
        float calculateDiscountedPrice(float discountPercentage);
};

#endif // LAPTOP_H
