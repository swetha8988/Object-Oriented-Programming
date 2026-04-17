#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Product {
    int id;
    char name[30];
    int qty;
    float price;
public:
    void input() {
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Quantity: "; cin >> qty;
        cout << "Enter Price: "; cin >> price;
    }
    void display() {
        cout << left << setw(10) << id
             << setw(15) << name
             << setw(10) << qty
             << fixed << setprecision(2)
             << setw(10) << price << endl;
    }
    int getId() { return id; }
    int getQty() { return qty; }

    void update() {
        cout << "New Quantity: ";
        cin >> qty;
        cout << "New Price: ";
        cin >> price;
    }
};
void addProduct() {
    Product p;
    ofstream file("inventory.dat", ios::binary | ios::app);
    if(!file) {
        cout << "File error!\n";
        return;
    }
    p.input();
    file.write((char*)&p, sizeof(p));
    file.close();
    cout << "Product added!\n";
}
void displayProducts() {
    Product p;
    ifstream file("inventory.dat", ios::binary);
    if(!file) {
        cout << "No records found!\n";
        return;
    }
    cout << "\n--- PRODUCT LIST ---\n";
    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Qty"
         << setw(10) << "Price" << endl;
    while(file.read((char*)&p, sizeof(p))) {
        p.display();
    }
    file.close();
}
void updateProduct() {
    fstream file("inventory.dat", ios::binary | ios::in | ios::out);
    Product p;
    int id, found = 0;
    if(!file) {
        cout << "File error!\n";
        return;
    }
    cout << "Enter ID to update: ";
    cin >> id;
    while(file.read((char*)&p, sizeof(p))) {
        if(p.getId() == id) {
            p.update();
            int pos = file.tellg() - sizeof(p);
            file.seekp(pos);
            file.write((char*)&p, sizeof(p));
            cout << "Updated!\n";
            found = 1;
            break;
        }
    }
    if(!found) cout << "Product not found!\n";
    file.close();
}
void deleteProduct() {
    ifstream in("inventory.dat", ios::binary);
    ofstream out("temp.dat", ios::binary);
    Product p;
    int id;
    if(!in || !out) {
        cout << "File error!\n";
        return;
    }
    cout << "Enter ID to delete: ";
    cin >> id;
    while(in.read((char*)&p, sizeof(p))) {
        if(p.getId() != id) {
            out.write((char*)&p, sizeof(p));
        }
    }
    in.close();
    out.close();
    remove("inventory.dat");
    rename("temp.dat", "inventory.dat");
    cout << "Deleted!\n";
}


void lowStock() {
    ifstream file("inventory.dat", ios::binary);
    Product p;
    if(!file) {
        cout << "File error!\n";
        return;
    }
    cout << "\n*** LOW STOCK (Qty < 5) ***\n";
    while(file.read((char*)&p, sizeof(p))) {
        if(p.getQty() < 5) {
            p.display();
        }
    }
    file.close();
}
int main() {
    int choice;
    do {
        cout << "\n===== INVENTORY MENU =====\n";
        cout << "1. Add\n2. Display\n3. Update\n4. Delete\n5. Low Stock\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: lowStock(); break;
        }
    } while(choice != 0);
    return 0;
}
