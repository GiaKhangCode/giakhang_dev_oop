#include "Laptop.h"

Laptop::Laptop(string id, string name, string brand,
                float price, int quantity, string cpu,
                    int ram, int storage, string gpu)
{
    this->id = id;
    this->name =  name;
    this->brand = brand;
    this->price = price;
    this->quantity = quantity;
    this->cpu = cpu;
    this->ram = ram;
    this->storage = storage;
    this->gpu = gpu;
}
void Laptop::inputInfo()
{
    cout << "NHAP THONG TIN CHO LAPTOP\n";
    cout << "Nhap ID: ";
    getline(cin, id);
    cout << "Nhap ten san pham: ";
    getline(cin, name);
    cout << "Nhap nhan hang: ";
    getline(cin, brand);
    cout << "Nhap gia tien: ";
    cin >> price;
    cout << "Nhap so luong: ";
    cin >> quantity; cin.ignore();
    cout << "Nhap loai CPU: ";
    getline(cin, cpu);
    cout << "Nhap dung luong RAM: ";
    cin >> ram;
    cout << "Nhap dung luong bo nho: ";
    cin >> storage; cin.ignore();
    cout << "Nhap loai GPU: ";
    getline(cin, gpu);
}
void Laptop::displayInfo()
{
    cout << "Product ID: " << id << endl
        << "Name: " << name << endl
        << "Brand: " << brand << endl
        << "Price: " << price << "$\n"
        << "Quantity: " << quantity << endl
        << "CPU: " << cpu << endl
        << "Ram: " << ram << "GB\n"
        << "Storage: " << storage << "GB\n"
        << "GPU: " << gpu << endl;
}
float Laptop::calculateDiscountedPrice(float discountPercentage)
{
    return price*(discountPercentage/100);
}
