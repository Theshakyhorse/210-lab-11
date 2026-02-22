#include <iostream>
using namespace std;

//the number of employees is typically constant
const int NUM_EMPLOYEES = 3;

//struct representing employees at a company
struct Employee {
    string name;
    int age;
    int * degrees;

    ~Employee() {
        if (degrees)
            delete [] degrees;
        degrees = nullptr;
    }
};

int main(){
    Employee *list = new Employee[NUM_EMPLOYEES];

    return 0;
}

void inputEmployee(Employee * sptr) {
    static int numEmp = 1;
    int deg;
    cout << "Input data for employee #" << numEmp << endl;
    cout << "Name: ";
    getline(cin, sptr->name);
    cout << "Age: ";
    cin >> sptr->age;
    cout << "Number of college degrees: ";
    cin >> deg;
    sptr -> degrees = new int[deg];
    for (int i = 0; i < deg; i++) {
        cout << "Major: " << i+1;
        
    }
}