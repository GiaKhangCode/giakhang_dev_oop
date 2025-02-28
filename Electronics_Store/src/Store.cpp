#include "Store.h"

void Store::inputProduct()
{
    int choice;
    do
    {
        cout << "NHAP THONG TIN CAC SAN PHAM\nNHAP SMARTPHONE: 1\tNHAP LAPTOP: 2\t NHAP TABLET: 3\t NGUNG NHAP: 4\n";
        Product* temp;
        cin >> choice; cin.ignore();
        switch(choice)
        {
            case 1:
                temp = new SmartPhone;
                break;
            case 2:
                temp = new Laptop;
                break;
            case 3:
                temp = new Tablet;
                break;
            case 4:
                cout << "NHAP DU LIEU HOAN THANH\n";
                return;
        }
        temp->inputInfo();
        List.push_back(temp);
    } while (1);
}

void Store::addProduct(Product* product)
{
    List.push_back(product);
}

void Store::searchProductByName(string name)
{
    for (Product* product : List)
        if (product->getName() == name)
            product->displayInfo();
}

void Store::removeProductByID(string id)
{
    for (int i=0; i<List.size(); i++)
    {
        if (List[i]->getID() == id)
            List.erase(List.begin() + i);
    }
}

void Store::displayAllProduct()
{
    int count = 1;
    cout << "===LIST OF PRODUCTS===\n";
    for (Product* product : List)
    {
        cout << "\nNumber " << count++ << endl;
        product->displayInfo();
    }
}

void Store::displayAllSmartPhone()
{
    int count = 1;
    cout << "\n===LIST OF SMARTPHONE===";
    for (Product* product : List)
        if (product->isSmartPhone())
        {
            cout << "\nNumber " << count++ << endl;
            product->displayInfo();
        }
}

void Store::displayAllLaptop()
{
    int count = 1;
    cout << "\n===LIST OF LAPTOP===";
    for (Product* product : List)
        if (product->isLaptop())
        {
            cout << "\nNumber " << count++ << endl;
            product->displayInfo();
        }
}

void Store::displayAllTablet()
{
    int count = 1;
    cout << "\n===LIST OF TABLET===";
    for (Product* product : List)
        if (product->isTablet())
        {
            cout << "\nNumber " << count++ << endl;
            product->displayInfo();
        }
}

float Store::sumValueOfAllProduct()
{
    float sum = 0;
    for (Product* product : List)
    {
        sum += product->calculateDiscountedPrice(100);
    }

    return sum;
}
