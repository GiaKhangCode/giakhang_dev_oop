#include "SmartPhone.h"

SmartPhone::SmartPhone(string id, string name, string brand,
                    float price, int quantity, int ram, int storage, int camera)
{
    this->id = id;
    this->name =  name;
    this->brand = brand;
    this->price = price;
    this->quantity = quantity;
    this->ram = ram;
    this->storage = storage;
    this->camera = camera;
}

void SmartPhone::inputInfo()
{
    cout << "NHAP THONG TIN CHO DIEN THOAI\n";
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
    cout << "Nhap dung luong RAM: ";
    cin >> ram;
    cout << "Nhap dung luong bo nho: ";
    cin >> storage;
    cout << "Nhap do phan giai camera: ";
    cin >> camera;
    cin.ignore();
}

void SmartPhone::displayInfo()
{
    cout << "Product ID: " << id << endl
        << "Name: " << name << endl
        << "Brand: " << brand << endl
        << "Price: " << price << "$\n"
        << "Quantity: " << quantity << endl
        << "Ram: " << ram << "GB\n"
        << "Storage: " << storage << "GB\n"
        << "Camera: " << camera << "MP\n";
}
float SmartPhone::calculateDiscountedPrice(float discountPercentage)
{
    return price*(discountPercentage/100);
}
