// COMSC-210 | Lab 11 | Alexander Sierra
#include <iostream>
using namespace std;

//the number of employees is typically constant
const int NUM_EMPLOYEES = 5;

//struct representing employees at a company
struct Employee {
    string name;
    int age;
    int numDeg;
    string * degrees;

    ~Employee() {
        if (degrees)
            delete [] degrees;
        degrees = nullptr;
    }
};

void inputEmployee(Employee *);
void outputEmployee(Employee *);

int main(){
    Employee *list = new Employee[NUM_EMPLOYEES];

    //loops to fill list with multiple employees
    for (int i = 0; i < NUM_EMPLOYEES; i++){
        inputEmployee(&list[i]);
    }

    //loops to output all employees in list
    for (int i = 0; i < NUM_EMPLOYEES; i++){
        outputEmployee(&list[i]);
    }

    return 0;
}

//takes input to for employees
void inputEmployee(Employee * sptr) {
    static int numEmp = 1; //which employee's data is being input
    cout << "Input data for employee #" << numEmp << endl;
    cout << "Name: ";
    getline(cin, sptr->name);
    cout << "Age: ";
    cin >> sptr->age;
    cout << "Number of college degrees: ";
    cin >> sptr->numDeg;
    sptr -> degrees = new string[sptr->numDeg];
    //this loop takes major names and puts them in the degrees array
    for (int i = 0; i < sptr->numDeg; i++) {
        cout << "Major " << i+1 << ": ";
        cin >> sptr->degrees[i];
    }
    //formatting
    cin.ignore();
    cout << endl;
    numEmp++; //updates counter to show which employee
}

//outputs employees
void outputEmployee(Employee * sptr) {
    cout << "Employee details:" << endl;
    cout << "Name: " << sptr->name << endl;
    cout << "Age: " << sptr->age << endl;
    for (int i = 0; i < sptr->numDeg; i++){
        cout << "Major " << i+1 << ": ";
        cout << sptr->degrees[i] << endl;
    }
    cout << endl;
}