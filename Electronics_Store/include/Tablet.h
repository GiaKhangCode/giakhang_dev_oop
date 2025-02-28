#ifndef TABLET_H
#define TABLET_H
#include "Product.h"

class Tablet: public Product
{
    protected:
        int screenSize;
        int battery;
    public:
        Tablet(string id = "None", string name = "None", string brand = "None",
                    float price = 0, int quantity = 0, int screenSize = 0, int battery = 0);
        void inputInfo();
        void displayInfo();
        float calculateDiscountedPrice(float discountPercentage);
};

#endif // TABLET_H
