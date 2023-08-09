/*
Stack:
LIFO(Last In First Out)
a new element is added at one end (top) 
and an element is removed from that end only. 

Basic Operations:

    primary operations:
        1] push() − Pushing (storing) an element on the stack.
        2] pop() − Removing (accessing) an element from the stack.



    -] isFull() − check if stack is full.
    -] isEmpty() − check if stack is empty.

At all times, we maintain a pointer to the last PUSHed data on the stack. 
...
[pointer always represents the top of the stack] 
    => It provides top value of the stack without actually removing it

*/

#include <iostream>
#include<conio.h>
using namespace std;

const int SIZE = 10;

template <class T>
class stack {
    private:
        int top;
        T array[SIZE];

    public:
        stack() { top = -1; }

        // stack functions:

        // 1] isEmpty() − check if stack is empty.
        bool isEmpty() {
            if(top==-1)
                return true;
            else
                return false;
            
            // OR Use The Short Hand If Else
            //return (top==-1) ? true : false;
        }
        
        // variable = (condition) ? expressionTrue : expressionFalse;
        // 

        // 2] isFull() − check if stack is full.
        bool isFull() {
            if(top==(SIZE-1))
                return true;
            else
                return false;
                
            // OR Use The Short Hand If Else
            //return (top==(SIZE-1)) ? true : false;
        }

        void push(T);
        T pop();
        void displayItems();
};

/*
Push Operation
The process of putting a new data element onto stack is known as a Push Operation.
Push operation involves a series of steps −
 Step 1 − Checks if the stack is full.
 Step 2 − If the stack is full, produces an error and exit.
 Step 3 − If the stack is not full, increments top to point next empty space.
 Step 4 − Adds data element to the stack location, where top is pointing.
 Step 5 − Returns success.
*/
template <class T>
void stack <T>::push(T element) {
    if(isFull()) {
        cout << "Stack is full.\n";
    }
    else { 
        top++;
        array[top] = element;
    } 
}





/*
Pop Operation
A Pop operation may involve the following steps −
 Step 1 − Checks if the stack is empty.
 Step 2 − If the stack is empty, produces an error and exit.
 Step 3 − If the stack is not empty, accesses the data element at which top is
pointing.
 Step 4 − Decreases the value of top by 1.
 Step 5 − Returns success.
*/

template <class T>
T stack<T>::pop() { 
    T x;
    if(isEmpty()) {
        cout << "Stack is empty.\n";
        return 0; // return null on empty stack
    }
    else {
        x= array[top];
        top--;
        return x; // or we can write  return array[top--];
    }
}




// To Display Items
template <class T>
void stack<T>::displayItems(){
    int i; //for loop
    cout<<"STACK is: ";

    for(i=(top); i>=0; i--)
        cout<<array[i]<<" ";
        cout<<endl;
}






// void main() => make error
int main()
{
    stack <char> s1,s2;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s2.push('x');
    s2.push('y');
    s2.push('z');
    cout<<"content of the s1 after pushing"<<endl;
    s1.displayItems();
    cout<<"content of the s2 after pushing"<<endl;
    s2.displayItems();


    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<"content of the s1 after pushing and poping is:"<<endl;
    s1.displayItems();
    cout<<"\ncontent of the s1 after pushing and poping is:"<<endl;
    s2.displayItems();



    stack<double> ds1, ds2;
    ds1.push(1.1);
    ds1.push(3.3);
    ds1.push(5.5);
    ds2.push(2.2);
    ds2.push(4.4);
    ds2.push(6.6);
    cout<<endl;
    for(int i=0; i<3; i++)
        cout << "Pop ds1: " << ds1.pop() << "\n";
    for(int i=0; i<3; i++)
        cout << "Pop ds2: " << ds2.pop() << "\n";
    getch();
}


