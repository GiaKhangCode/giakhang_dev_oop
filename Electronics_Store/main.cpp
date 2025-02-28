#include "Product.h"
#include "SmartPhone.h"
#include "Laptop.h"
#include "Tablet.h"
#include "Store.h"
using namespace std;

int main()
{
    Store CellPhoneS;
    CellPhoneS.inputProduct();
    CellPhoneS.displayAllProduct();
    CellPhoneS.displayAllSmartPhone();
    CellPhoneS.displayAllLaptop();
    CellPhoneS.displayAllTablet();
    cout << "Tong gia tri cua cua hang: " << CellPhoneS.sumValueOfAllProduct();
    return 0;
}
