// Example 2: Simple Calculator Using Class Templates 
/*#include <iostream>
using namespace std;

template <class T>
class Calculator1 {
    private:
        T num1, num2;

    public:

        Calculator(T n1, T n2) {  //
        num1 = n1;
        num2 = n2;
        }

        //
        void displayResult() {
            cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
            cout << num1 << " + " << num2 << " = " << add() << endl;
            cout << num1 << " - " << num2 << " = " << subtract() << endl;
            cout << num1 << " * " << num2 << " = " << multiply() << endl;
            cout << num1 << " / " << num2 << " = " << divide() << endl;
            }


        T add() { return num1 + num2; }
        T subtract() { return num1 - num2; }
        T multiply() { return num1 * num2; }
        T divide() { return num1 / num2; }

};
*/
/*
int main() {
    Calculator<int> intCalc(2.4, 1);
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << endl << "Float results:" << endl;
    floatCalc.displayResult();
return 0;
}
*/
/******************************************************************/


// Write above program by Defining a Class Member "Outside" the Class Template


#include <iostream>
using namespace std;

template <class T>
class Calculator {
    private:
        T num1, num2;
    
    public:
        // Here is the first mistake
        T add();
        T subtract();
        T multiply();
        T divide();

        Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
        }

        void displayResult() {
            cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
            cout << num1 << " + " << num2 << " = " << add() << endl;
            cout << num1 << " - " << num2 << " = " << subtract() << endl;
            cout << num1 << " * " << num2 << " = " << multiply() << endl;
            cout << num1 << " / " << num2 << " = " << divide() << endl;
            }
};
// Here is the second error
template <class T>
T Calculator <T>::add() { return num1 + num2; }

template <class T>
T Calculator <T>::subtract() { return num1 - num2; }

template <class T>
T Calculator <T>::multiply() { return num1 * num2; }

template <class T>
T Calculator <T>::divide() { return num1 / num2; }


int main() {
    Calculator<int> intCalc(2.4, 1);
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << endl << "Float results:" << endl;
    floatCalc.displayResult();
return 0;
}




