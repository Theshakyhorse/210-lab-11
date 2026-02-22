#include <iostream>
using namespace std;

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
    
}