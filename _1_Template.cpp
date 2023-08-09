/*
Template:
Templates are powerful features of C++ which allows us to write generic
programs.

=> There are two ways we can implement templates:

    1] Function Templates.

    2] Class Templates.

*********************************************************************
1] Function Templates.

template <typename T>
T functionName(T parameter1, T parameter2, ...) {
/// code
}

Call:
functionName<dataType>(parameter1, parameter2,...);
*/




// Example: Adding Two Numbers Using Function Templates

#include <iostream>
using namespace std;

template <typename T>
T add(T num1, T num2) {
    return (num1 + num2);
}

int main() {
    int result1;
    double result2;

    // calling with int parameters
    result1 = add<int>(2.5, 3.7);
    cout << "2 + 3 = " << result1 << endl; //→5

    // calling with double parameters
    result2 = add<double>(2.2, 3.3);
    cout << "2.2 + 3.3 = " << result2 << endl; //→5

    cout<< add<char>(2.5, 3.7);
    return 0;
}

/*************************************/

// Example 1: C++ Class Templates

// C++ program to demonstrate the use of class templates
#include <iostream>
using namespace std;

// Class template
template <class T>
class Number {
    private:
    // Variable of type T
        T num;
    
    public:
        Number(T n) {num=n; } // constructor
        T getNum() {
            return num;
        }
    // Create Object => T get_num();
};

int main() {
    // create object with int type
    Number<int> numberInt(7);

    // create object with double type
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl; //→7
    cout << "double Number = " << numberDouble.getNum() << endl; // → 7.7

    return 0;
}

/*
Function Definition 'Outside The Class'
template <class T>
T Number<T>::get_num() {
    return num;
}
*/


