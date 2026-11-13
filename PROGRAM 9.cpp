#include <iostream>
using namespace std;

class ClassB;

class ClassA {
private:
    int num;   // private member - normally not accessible outside the class

public:
    ClassA(int n) : num(n) {}

    void display() const {
        cout << "ClassA number = " << num << endl;
    }


    friend void swapNumbers(ClassA &a, ClassB &b);
};

class ClassB {
private:
    int num;   // private member

public:
    ClassB(int n) : num(n) {}

    void display() const {
        cout << "ClassB number = " << num << endl;
    }

  
    friend void swapNumbers(ClassA &a, ClassB &b);
};


void swapNumbers(ClassA &a, ClassB &b) {
    int temp = a.num;
    a.num = b.num;
    b.num = temp;
}

int main() {
    int x, y;

    cout << "Enter first number (for ClassA object)  : ";
    cin  >> x;
    cout << "Enter second number (for ClassB object) : ";
    cin  >> y;

    ClassA objA(x);
    ClassB objB(y);

    cout << "\nBefore swapping:\n";
    objA.display();
    objB.display();

    swapNumbers(objA, objB);   // friend function call - not objA.swapNumbers(...)

    cout << "\nAfter swapping:\n";
    objA.display();
    objB.display();

    return 0;
}

OUTPUT:-
Enter first number (for ClassA object)  : 4
Enter second number (for ClassB object) : 6

Before swapping:
ClassA number = 4
ClassB number = 6

After swapping:
ClassA number = 6
ClassB number = 4