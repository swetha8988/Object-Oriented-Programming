#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
 int n;
 cout << setfill('=') << setw(70) << "" << endl;
 cout << setfill(' ') << setw(42) << "SMART BILLING APP" << endl;
 cout << setfill('=') << setw(70) << "" << endl << endl;
 cout << "Enter number of items: ";
 cin >> n;
 string item[n];
 int qty[n];
 double price[n], total[n];
double subTotal = 0, discount = 0, gst = 0, grandTotal = 0;
 const double GST_RATE = 0.05; 
 string currency = "Rs. ";
 int billNo;
 string date, mobile, paymentMethod;
 cout << endl;
 cout << "Enter Bill Number: ";
cin >> billNo;
 cout << "Enter Date (DD/MM/YYYY): ";
 cin >> date;
 cout << "Enter Customer Mobile Number: ";
 cin >> mobile;
 cout << "Enter Payment Method (Cash/Card/UPI): ";
 cin >> paymentMethod;
 cout << endl;
 for(int i = 0; i < n; i++)
 {
 cin >> item[i];
cout << "Enter Quantity: ";
 cin >> qty[i];
 cout << "Enter Price: ";
 cin >> price[i];
 total[i] = qty[i] * price[i];
 subTotal += total[i];
 cout << endl;
 }
int totalQty = 0; cout << "Enter Item " << i+1 << " Name: ";
 for(int i = 0; i < n; i++)
 {
 totalQty += qty[i];
 }
 if(subTotal >= 2000)
discount = subTotal * 0.10;
 double afterDiscount = subTotal - discount;
 gst = afterDiscount * GST_RATE;
 grandTotal = afterDiscount + gst;
 cout << fixed << setprecision(2);
 cout << "\nBill No : " << billNo << endl;
 cout << "Date : " << date << endl;
 cout << "Mobile : " << mobile << endl;
 cout << "Payment : " << paymentMethod << endl << endl;
 cout << setw(20) << left << "Item"
 << setw(8) << "Qty"
 << setw(12) << "Price"
 << setw(12) << "Total" << endl;
 cout << setfill('-') << setw(55) << "" << endl;
 cout << setfill(' ');
 for(int i = 0; i < n; i++)
 {
 cout << setw(20) << left << item[i]
 << setw(8) << qty[i]
 << setw(12) << currency + to_string(price[i])
 << setw(12) << currency + to_string(total[i]) << endl;
 }
 cout << endl;
 cout << "Total Items Purchased: " << totalQty << endl << endl;
cout << setw(45) << right << "Sub Total: " << currency << subTotal << endl;
 cout << setw(45) << right << "Discount : "<< currency << discount << endl;
cout << setw(45) << right << "GST : " << currency << gst << endl;
cout << setw(45) << right << "Grand Total: " << currency << grandTotal << endl;
 cout << endl;
 cout << setfill('=') << setw(70) << "" << endl;
 cout << setfill(' ') << setw(45) << "Thank You! Visit Again." << endl;
 cout << setfill('=') << setw(70) << "" << endl;
return 0;
}
