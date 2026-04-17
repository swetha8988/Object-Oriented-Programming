#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point
{
 float x, y;
public:
 Point(float a = 0, float b = 0)
 {
 x = a;
 y = b;
 }
 void input()
 {
 cout << "Enter X coordinate: ";
 cin >> x;
 cout << "Enter Y coordinate: ";
 cin >> y;
 }
 void display() const
 {
 cout << "(" << fixed << setprecision(2) << x << "," << y << ")";
 }
 Point operator + (const Point &p)
 {
 return Point(x + p.x, y + p.y);
 }
 Point operator - (const Point &p)
 {
 return Point(x - p.x, y - p.y);
}
 Point operator * (int k)
 {
 return Point(x * k, y * k);
 }
 Point operator / (const Point &p)
 {
 return Point((x + p.x)/2 , (y + p.y)/2);
 }
 bool operator == (const Point &p)
 {
 return (x == p.x && y == p.y);
 }
 float distance(Point p)
 {
 return sqrt(pow(x - p.x,2) + pow(y - p.y,2));
 }
 operator float()
 {
 return sqrt(x*x + y*y);
 }
 Point reflectX()
 {
 return Point(x , -y);
 }
 Point reflectY()
 {
 return Point(-x , y);
 }
 Point rotate(float angle)
 {
 float rad = angle * 3.14159 / 180;
 float newX = x * cos(rad) - y * sin(rad);
 float newY = x * sin(rad) + y * cos(rad);
 return Point(newX , newY);
 }
 void lineEquation(Point p)
{
 if(p.x == x)
 {
 cout << "Vertical Line: x = " << x;
 }
 else
 {
 float m = (p.y - y) / (p.x - x);
 cout << "Line Equation: ";
 cout << "y - " << y << " = "
 << m << "(x - " << x << ")";
 }
 }
};
int main()
{
 Point p1, p2, result;
 int choice, k;
 float angle;
 char repeat, same;
 cout << setfill('=') << setw(55) << "" << endl;
 cout << setw(35) << "2D GEOMETRY TOOLKIT" << endl;
 cout << setfill('=') << setw(55) << "" << endl;
 do
 {
 cout << "\nEnter Point 1\n";
 p1.input();
 cout << "\nEnter Point 2\n";
 p2.input();
 do
 {
 cout << "\n";
 cout << "============== MENU ==============\n";
 cout << "1. Add Points\n";
 cout << "2. Subtract Points\n";
 cout << "3. Midpoint\n";
 cout << "4. Distance Between Points\n";
cout << "5. Scalar Multiplication\n";
 cout << "6. Distance from Origin\n";
 cout << "7. Compare Points\n";
 cout << "8. Reflect Point1 across X-axis\n";
 cout << "9. Reflect Point1 across Y-axis\n";
 cout << "10. Rotate Point1\n";
 cout << "11. Line Equation\n";
 cout << "==================================\n";
 cout << "Enter choice: ";
 cin >> choice;
 switch(choice)
 {
 case 1:
 result = p1 + p2;
 cout << "Result = ";
 result.display();
 break;
 case 2:
 result = p1 - p2;
 cout << "Result = ";
 result.display();
 break;
 case 3:
 result = p1 / p2;
 cout << "Midpoint = ";
 result.display();
 break;
 case 4:
 cout << "Distance = "
 << fixed << setprecision(2)
 << p1.distance(p2);
 break;
 case 5:
 cout << "Enter scalar value: ";
 cin >> k;
 result = p1 * k;
cout << "Result = ";
 result.display();
 break;
 case 6:
 {
 float d = p1;
 cout << "Distance from Origin = "
 << fixed << setprecision(2) << d;
 break;
 }
 case 7:
 if(p1 == p2)
 cout << "Points are Equal";
 else
 cout << "Points are Different";
 break;
 case 8:
 result = p1.reflectX();
 cout << "Reflection across X-axis = ";
 result.display();
 break;
 case 9:
 result = p1.reflectY();
 cout << "Reflection across Y-axis = ";
 result.display();
 break;
 case 10:
 cout << "Enter rotation angle: ";
 cin >> angle;
 result = p1.rotate(angle);
 cout << "Rotated Point = ";
 result.display();
 break;
 case 11:
 p1.lineEquation(p2);
 break;
 default:
cout << "Invalid Choice";
 }
 cout << "\n\nPerform another operation on SAME numbers? (y/n): ";
 cin >> same;
 } while(same == 'y' || same == 'Y');
 cout << "\nDo you want to enter NEW numbers? (y/n): ";
 cin >> repeat;
 } while(repeat == 'y' || repeat == 'Y');
 cout << endl;
 cout << setfill('-') << setw(55) << "" << endl;
 cout << setw(35) << "Program Ended" << endl;
 cout << setfill('-') << setw(55) << "" << endl;
 return 0;
}
