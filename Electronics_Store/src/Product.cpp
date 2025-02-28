#include "Product.h"

Product::Product(string id, string name, string brand, float price, int quantity)
{
    this->id = id;
    this->name =  name;
    this->brand = brand;
    this->price = price;
    this->quantity = quantity;
}

void Product::inputInfo()
{
    cout << "Nhap ID: ";
    getline(cin, id);
    cout << "Nhap ten san pham: ";
    getline(cin, name);
    cout << "Nhap nhan hang: ";
    getline(cin, brand);
    cout << "Nhap gia tien: ";
    cin >> price;
    cout << "Nhap so luong: ";
    cin >> quantity;
    cin.ignore();
}
void Product::displayInfo()
{
    return;
}
float Product::calculateDiscountedPrice(float discountPercentage)
{
    return 0;
}

string Product::getID()
{
    return id;
}

string Product::getName()
{
    return name;
}

bool Product::isSmartPhone()
{
    return (getID().substr(0,2) == "SM");
}
bool Product::isLaptop()
{
    return (getID().substr(0,2) == "LT");
}
bool Product::isTablet()
{
    return (getID().substr(0,2) == "TB");
}
