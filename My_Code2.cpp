#include <iostream>
#include <conio.h>
using namespace std;

const int Stack_Size = 10; // Determine the length of the Stack => Static Stack
// OR Make It As Dynamic Stack
// 

template <class A>
class Stack {
    private: 
        int Top;                // Determine Int Value => The Top Of Stack 
        A array[Stack_Size];    // Create a Array representing the Stack => It Have The Size That We Want. [Stack_Size = 10]
    public:
        Stack() { Top = -1; }   // Constructor => It Call It Self Automaticly "Every Time you Call The Class"

        // Now We Will Write The Stack Functions:
        // 1] Is_Emty() => It Make Check If Stack Is Empty.  => return true if yes ;
        bool Is_Emty() { return (Top==-1)?true:false; }

        // 2] Is_Full() − check if stack is full.
        bool Is_Full() { return (Top==(Stack_Size-1))?true:false; }

        // 3] Push()
        void Push(A Element) {
            if (Is_Full()){cout<<"The Stack Is Full \n";}
            else { 
                Top++;  
                array[Top]=Element;
                }
        }

        A Pop() {
            A X;
            if (Is_Emty()){cout<<"The Stack Is Emty \n"; return 0;}
            else {
                X = array[Top];
                Top--;
                return X;
            }
        }


        void Display_All_Stack() {
            int i;
            cout << "Stack Is:";

            for (i=(Top); i>=0; i--){
                cout<<array[i]<<"\n";
            }
        }
    
};




int main()
{
    Stack <char> s1,s2;
    s1.Push('a');
    s1.Push('b');
    s1.Push('c');
    s2.Push('x');
    s2.Push('y');
    s2.Push('z');
    cout<<"content of the s1 after pushing"<<endl;
    s1.Display_All_Stack();
    cout<<"content of the s2 after pushing"<<endl;
    s2.Display_All_Stack();


    cout<<s1.Pop()<<endl;
    cout<<s1.Pop()<<endl;
    cout<<s2.Pop()<<endl;
    cout<<s2.Pop()<<endl;
    cout<<"content of the s1 after pushing and poping is:"<<endl;
    s1.Display_All_Stack();
    cout<<"\ncontent of the s1 after pushing and poping is:"<<endl;
    s2.Display_All_Stack();



    Stack<double> ds1, ds2;
    ds1.Push(1.1);
    ds1.Push(3.3);
    ds1.Push(5.5);
    ds2.Push(2.2);
    ds2.Push(4.4);
    ds2.Push(6.6);
    cout<<endl;
    for(int i=0; i<3; i++)
        cout << "Pop ds1: " << ds1.Pop() << "\n";
    for(int i=0; i<3; i++)
        cout << "Pop ds2: " << ds2.Pop() << "\n";
    getch();
}



