#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;
int choice, query, result = 1, qty;
int i, j, k;
float thisClientSubtotal, thisClientTotal, shopRevenue;
string delim = string(19, '-');
string new_descr;
int new_qty;
float new_price;

char to_upper0(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 32;
    }
    return ch;
}
string to_upper(string s) {
    for (char& ch : s) {
        ch = to_upper0(ch);
    }
    return s;
}

class Item {
public:
    int id;
    string descr;
    int qty;
    float price;
    Item(int a, string b, int c, float d) {
        id = a;
        descr = b;
        qty = c;
        price = d;
    }
    /*Item(string b, int c, float d) {
        descr = b;
        qty = c;
        price = d;
    }*/
    int thisSubTotal(int x) {
        return price * x;
    }
    string descrUpperCase() {
        return to_upper(descr);
    }
};
/*
Item items[] = {
Item(1, "doll", 11, 100.50),
Item(2, "car", 10, 85.55),
};
*/
vector <Item> items = {
Item(1, "doll", 11, 100.50),
Item(2, "car", 10, 85.55),
};

void itemSelection() {
    system("CLS");
    cout << "Enter the item code (0 to " << size(items) << ")" << endl;
    cout << "The code to exit:  0" << endl;
    for (i = 0; i < size(items); i++) {
        cout << "The code for " << items[i].descr << ": " << items[i].id << endl;
    }
    cout << delim << endl;
}

void itemAdd() {
    system("CLS");
    cout << "Enter new item description: ";
    cin >> new_descr;
    cout << "Enter new item quantity: ";
    cin >> new_qty;
    cout << "Enter new item price: ";
    cin >> new_price;
    //items.push_back(Item(size(items) + 1, new_descr, new_qty, new_price));
    items.emplace_back(size(items) + 1, new_descr, new_qty, new_price);


    
}

void jobStart() {
    cout << "What do you want to do?\nTo exit, enter 0.\nTo add an item, enter 1.\nTo sale, enter 2.\n";
    cin >> choice;
    switch (choice) {
        case 1: {
            itemAdd();
            break;
        }
        case 2: {
            itemSelection();
            break;
        }
    }
}



int main() {
    while(true) {
        jobStart();
    }

    


 //   cout << delim << endl; 
 //   cout << size(items) << endl;
   
    //itemSelection();
    //size(items) + 1
    /*
    char  arr[] = { '1','2','3' };
    for (char z : arr) {
        cout << z;
    }
    */
    /*
    thisClientSubtotal = 0;
    thisClientTotal = 0;
    itemSelection();
    cin >> query;
    cout << delim << endl;
    cout << "Your choice is " << to_upper(items[query - 1].descr) << endl;
    cout << "Available qty: " << items[query - 1].qty << endl;
    cout << delim << endl;
    cout << "Enter the qty: " << endl;
    cout << delim << endl;
    cin >> qty;
    cout << delim << endl;
    thisClientSubtotal += items[query - 1].thisSubTotal(float(qty));
    cout << "Subtotal: " << thisClientSubtotal << endl;
    items[query - 1].qty -= qty;
    cout << "Remaining qty: of " << to_upper(items[query - 1].descr) << "s: " << items[query - 1].qty << endl;
    cout << delim << endl;
    cout << "Do you \v want to continue?" << endl;
    */
}
