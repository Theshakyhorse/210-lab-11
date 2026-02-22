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

void inputEmployee(Employee *);

int main(){
    Employee *list = new Employee[NUM_EMPLOYEES];

    for (int i = 0; i < NUM_EMPLOYEES; i++){
        inputEmployee(&list[i]);
    }

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
        cout << "Major " << i+1 << ": ";
        cin >> sptr->degrees[i];
    }
    cin.ignore();
    cout << endl << endl;
    numEmp += 1;
}