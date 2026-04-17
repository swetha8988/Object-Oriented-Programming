#include <iostream>
using namespace std;
long long factorial(int);
double power(double, int = 2);
bool isPrime(int);
bool isBuzz(int);
bool isPalindrome(int);
bool isDuck(int);
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
int hcf(int, int);
int lcm(int, int);
long long factorial(int n) {
 if (n < 0) return -1;
 if (n == 0 || n == 1) return 1;
 return n * factorial(n - 1);
}
double power(double base, int exp) {
 double result = 1;
 for (int i = 0; i < exp; i++) result *= base;
return result;
}
bool isPrime(int n) {
 if (n <= 1) return false;
 for (int i = 2; i * i <= n; i++)
 if (n % i == 0) return false;
 return true;
}
bool isBuzz(int n) {
 return (n % 7 == 0) || (n % 10 == 7);
}
bool isPalindrome(int n) {
 int rev = 0, temp = n;
 while (temp != 0) {
 rev = rev * 10 + temp % 10;
 temp /= 10;
 }
 return rev == n;
}
bool isDuck(int n) {
 int temp = n;
 while (temp != 0) {
 int digit = temp % 10;
 if (digit == 0) return true;
 temp /= 10;
 }
return false;
}
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
 if (b == 0) {
 cout << "Division by zero not allowed.\n";
 return 0;
 }
 return a / b;
}
int hcf(int a, int b) {
 while (b != 0) { int temp = b; b = a % b; a = temp; }
 return a;
}
int lcm(int a, int b) {
 return (a * b) / hcf(a, b);
}
int main() {
 int choice;
 do {
 cout << "\n=================================\n";
 cout << " MATH TOOLKIT LIBRARY\n";
 cout << "=================================\n";
cout << "1. Addition\n";
cout << "2. Subtraction\n";
 cout << "3. Multiplication\n";
 cout << "4. Division\n";
 cout << "5. Factorial\n";
 cout << "6. Power\n";
 cout << "7. HCF\n";
 cout << "8. LCM\n";
 cout << "9. Number Properties\n";
 cout << "0. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 double a, b;
 int n, x, y;
 switch (choice) {
 case 1:
cout << "Enter two numbers: "; cin >> a >> b;
 cout << "Result = " << add(a, b) << endl;
 break;
 case 2:
 cout << "Enter two numbers: "; cin >> a >> b;
 cout << "Result = " << subtract(a, b) << endl;
 break;
 case 3:
 cout << "Enter two numbers: "; cin >> a >> b;
 cout << "Result = " << multiply(a, b) << endl;
break;
case 4:
 cout << "Enter two numbers: "; cin >> a >> b;
 cout << "Result = " << divide(a, b) << endl;
 break;
 case 5:
 cout << "Enter number: "; cin >> n;
 cout << "Factorial = " << factorial(n) << endl;
 break;
 case 6:
 cout << "Enter base and exponent: "; cin >> a >> n;
 cout << "Result = " << power(a, n) << endl;
 break;
 case 7:
 cout << "Enter two numbers: "; cin >> x >> y;
 cout << "HCF = " << hcf(x, y) << endl;
 break;
 case 8:
 cout << "Enter two numbers: "; cin >> x >> y;
 cout << "LCM = " << lcm(x, y) << endl;
 break;
 case 9: {
 int subChoice;
 cout << "\n--- Number Properties ---\n";
 cout << "1. Prime Check\n";
 cout << "2. Buzz Number\n";
 cout << "3. Palindrome Number\n";
cout << "4. Duck Number\n";
 cout << "Enter choice: "; cin >> subChoice;
 cout << "Enter number: "; cin >> n;
 switch (subChoice) {
 case 1: cout << (isPrime(n) ? "Prime Number\n" : "Not Prime\n"); break;
 case 2:
 if (isBuzz(n)) {
 cout << "Buzz Number (";
 if (n % 7 == 0) cout << "Divisible by 7";
 if (n % 7 == 0 && n % 10 == 7) cout << " & ";
 if (n % 10 == 7) cout << "Ends with 7";
 cout << ")\n";
 } else {
 cout << "Not a Buzz Number\n";
 }
 break;
 case 3: cout << (isPalindrome(n) ? "Palindrome Number\n" : "Not Palindrome\n"); break;
 case 4: cout << (isDuck(n) ? "Duck Number\n" : "Not Duck\n"); break;
 default: cout << "Invalid choice\n";
 }
 break;
 }
 case 0:
 cout << "Exiting Program...\n"; break;
 default:
 cout << "Invalid choice!\n";
}
 } while (choice != 0);
 return 0;
}
