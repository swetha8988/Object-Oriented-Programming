#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;
class Employee {
protected:
    string name;
    int id;
    double baseSalary;
    string department;
public:
    Employee(string n, int i, double salary, string dept)
        : name(n), id(i), baseSalary(salary), department(dept) {}
    virtual double getSalary() const { return baseSalary; }
    virtual string getRole() const { return "Employee"; }
    string getDept() const { return department; }
    virtual void display() const {
        cout << left << setw(20) << name
             << setw(10) << id
             << setw(15) << getRole()
             << setw(15) << department
             << right << setw(12) << fixed << setprecision(2) << getSalary() << endl;
    }

    virtual ~Employee() {}
};
class Coordinator : public Employee {
    double allowance;
public:
    Coordinator(string n,int i,double salary,double al,string dept)
        : Employee(n,i,salary,dept), allowance(al) {}
    double getSalary() const override { return baseSalary + allowance; }
    string getRole() const override { return "Coordinator"; }
};
class Analyst : public Employee {
    double projectBonus;
public:
    Analyst(string n,int i,double salary,double bonus,string dept)
        : Employee(n,i,salary,dept), projectBonus(bonus) {}
    double getSalary() const override { return baseSalary + projectBonus; }
    string getRole() const override { return "Analyst"; }
};
class Assistant : public Employee {
    double stipend;
public:
    Assistant(string n,int i,double s,string dept)
        : Employee(n,i,0,dept), stipend(s) {}
    double getSalary() const override { return stipend; }
    string getRole() const override { return "Assistant"; }
};
class TeamLead : public Employee {
    double bonus;
    double leadershipAllowance;
public:
    TeamLead(string n,int i,double salary,double b,double la,string dept)
        : Employee(n,i,salary,dept), bonus(b), leadershipAllowance(la) {}
    double getSalary() const override { return baseSalary + bonus + leadershipAllowance; }
    string getRole() const override { return "Team Lead"; }
};
class Support : public Employee {
    double extraPay;
public:
    Support(string n,int i,double salary,double ep,string dept)
        : Employee(n,i,salary,dept), extraPay(ep) {}
    double getSalary() const override { return baseSalary + extraPay; }
    string getRole() const override { return "Support Staff"; }
};
void printHeader() {
    cout << left << setw(20) << "Name"
         << setw(10) << "ID"
         << setw(15) << "Role"
         << setw(15) << "Department"
         << right << setw(12) << "Salary" << endl;
    cout << string(72,'-') << endl;
}
double applyBonus(double salary) {
    if (salary > 50000) return salary * 1.10;
    if (salary >= 30000) return salary * 1.05;
    return salary;
}
int main() {
    vector<Employee*> team;
    int choice;
    while(true) {
        cout << "\n====== Payroll System Menu ======\n";
        cout << "1. Add Employee\n2. Display Payroll\n3. Show Total & Average Salary\n";
        cout << "4. Show Highest Paid Employee\n5. Show Employee Count by Role\n6. Exit\nChoice: ";
        cin >> choice;
        if(choice == 1) {
            cout << "\nSelect Role:\n1. Coordinator\n2. Analyst\n3. Assistant\n4. Team Lead\n5. Support Staff\nChoice: ";
            int role;
            cin >> role;
            cin.ignore();
            string name, dept;
            int id;
            double base, extra1=0, extra2=0;
            cout << "Enter full name: ";
            getline(cin, name);
            cout << "Enter employee ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter department: ";
            getline(cin, dept);
            switch(role) {
                case 1:
                    cout << "Enter base salary: ";
                    cin >> base;
                    cout << "Enter allowance: ";
                    cin >> extra1;
                    team.push_back(new Coordinator(name,id,base,extra1,dept));
                    break;
                case 2:
                    cout << "Enter base salary: ";
                    cin >> base;
                    cout << "Enter project bonus: ";
                    cin >> extra1;
                    team.push_back(new Analyst(name,id,base,extra1,dept));
                    break;
                case 3:
                    cout << "Enter stipend: ";
                    cin >> extra1;
                    team.push_back(new Assistant(name,id,extra1,dept));
                    break;
                case 4:
                    cout << "Enter base salary: ";
                    cin >> base;
                    cout << "Enter bonus: ";
                    cin >> extra1;
                    cout << "Enter leadership allowance: ";
                    cin >> extra2;
                    team.push_back(new TeamLead(name,id,base,extra1,extra2,dept));
                    break;
                case 5:
                    cout << "Enter base salary: ";
                    cin >> base;
                    cout << "Enter extra pay: ";
                    cin >> extra1;
                    team.push_back(new Support(name,id,base,extra1,dept));
                    break;
                default:
                    cout << "Invalid role selection.\n";
            }
        }
        else if(choice == 2) {
            if(team.empty()) { cout << "No employees added yet.\n"; continue; }
            sort(team.begin(), team.end(), [](Employee* a, Employee* b){
                return a->getSalary() > b->getSalary();
            });
            cout << "\n========== Payroll Report ==========\n";
            printHeader();
            for(auto emp : team) emp->display();
        }
        else if(choice == 3) {
            if(team.empty()) { cout << "No employees added yet.\n"; continue; }
            double total=0;
            for(auto emp : team) total += emp->getSalary();
            cout << "\nTotal Payroll: " << total << endl;
            cout << "Average Salary: " << total/team.size() << endl;
        }
        else if(choice == 4) {
            if(team.empty()) { cout << "No employees added yet.\n"; continue; }
            Employee* highest = team[0];
            for(auto emp : team) {
                if(emp->getSalary() > highest->getSalary()) highest = emp;
            }
            cout << "\nHighest Paid Employee:\n";
            highest->display();
            cout << "Congratulations " << highest->getRole() << " " << highest->getRole() << "! Keep up the good work!\n";
        }
        else if(choice == 5) {
            map<string,int> roleCount;
            for(auto emp : team) roleCount[emp->getRole()]++;
            cout << "\nEmployee Count by Role:\n";
            for(auto &p : roleCount)
                cout << p.first << ": " << p.second << endl;
        }
        else if(choice == 6) break;
        else cout << "Invalid choice, try again.\n";
    }
    for(auto emp : team) delete emp;
    return 0;
}
