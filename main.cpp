#include <iostream>
using namespace std;

//the number of employees is typically constant
const int NUM_EMPLOYEES = 2;

//struct representing employees at a company
struct Employee {
    string name;
    int age;
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
    static int numEmp = 1; //tracks which employee's data is being input
    int deg;
    cout << "Input data for employee #" << numEmp << endl;
    cout << "Name: ";
    getline(cin, sptr->name);
    cout << "Age: ";
    cin >> sptr->age;
    cout << "Number of college degrees: ";
    cin >> deg;
    sptr -> degrees = new string[deg];
    for (int i = 0; i < deg; i++) {
        cout << "Major " << i+1 << ": ";
        cin >> sptr->degrees[i];
    }
    cin.ignore();
    cout << endl;
    numEmp++;
}

void outputEmployee(Employee * sptr) {
    cout << "Employee list:" << endl;
    cout << "Name: " << sptr->name << endl;
    cout << "Age: " << sptr->age << endl;
    for (int i = 0; i < sptr->degrees->size(); i++){
        cout << "Major " << i+1 << ": ";
        cout << sptr->degrees[i] << endl;
    }
    cout << endl;
}