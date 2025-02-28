#include "Tablet.h"

Tablet::Tablet(string id, string name, string brand,
                float price, int quantity, int screenSize, int battery)
{
    this->id = id;
    this->name =  name;
    this->brand = brand;
    this->price = price;
    this->quantity = quantity;
    this->screenSize = screenSize;
    this->battery = battery;
}
void Tablet::inputInfo()
{
    cout << "NHAP THONG TIN CHO MAY TINH BANG\n";
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
    cout << "Nhap kich co man hinh: ";
    cin >> screenSize;
    cout << "Nhap dung luong pin: ";
    cin >> battery;
    cin.ignore();
}
void Tablet::displayInfo()
{
    cout << "Product ID: " << id << endl
        << "Name: " << name << endl
        << "Brand: " << brand << endl
        << "Price: " << price << "$\n"
        << "Quantity: " << quantity << endl
        << "Screen size: " << screenSize << " inches\n"
        << "Battery: " << battery << "mAh\n";

}
float Tablet::calculateDiscountedPrice(float discountPercentage)
{
    return price*(discountPercentage/100);
}

