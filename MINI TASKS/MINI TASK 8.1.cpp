#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
class Error {
public:
    void show() {
        cout << "Invalid Input!\n";
    }
};
template <typename T>
T processValue(T value, int type) {
    if(value < 0)
        throw Error();
    if(type == 1)
        return value * value;       // square
    else if(type == 2)
        return value * value * value; // cube
    else
        throw Error();
}
template <typename T>
class DataProcessor {
    vector<T> data;
public:
    void add(T value, int type) {
        try {
            T result = processValue(value, type);
            data.push_back(result);
            cout << "Stored: " << result << endl;
        }
        catch(Error e) {
            e.show();
        }
    }
    void display() {
        if(data.empty()) {
            cout << "No data!\n";
            return;
        }
        cout << "\n===== DATA =====\n";
        cout << left << setw(10) << "Index"
             << setw(15) << "Value" << endl;
        for(int i = 0; i < data.size(); i++) {
            cout << left << setw(10) << i
                 << fixed << setprecision(2)
                 << setw(15) << data[i] << endl;
        }
    }
    void saveToFile() {
        ofstream file("data.txt");
        for(int i = 0; i < data.size(); i++)
            file << data[i] << endl;
        file.close();
        cout << "Saved to file!\n";
    }
};

/
class Menu {
public:
    void show() {
        cout << "\n===== SAFE DATA PROCESSOR =====\n";
        cout << "1. Add Value\n";
        cout << "2. Display\n";
        cout << "3. Save to File\n";
        cout << "0. Exit\n";
    }
    void operation() {
        cout << "1. Square\n2. Cube\n";
    }
};
int main() {
    DataProcessor<double> dp;
    Menu m;
    int choice, op;
    double value;
    do {
        m.show();
        cout << "Enter choice: ";
        cin >> choice;
        try {
            switch(choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    m.operation();
                    cin >> op;
                    dp.add(value, op);
                    break;
                case 2:
                    dp.display();
                    break;
                case 3:
                    dp.saveToFile();
                    break;
                case 0:
                    cout << "Exit\n";
                    break;
                default:
                    throw Error();
            }
        }
        catch(Error e) {
            e.show();
        }

    } while(choice != 0);

    return 0;
}
