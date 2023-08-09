/*
A Linear Queue:
First-in FirstOut lists (FIFO) or Last-In-Last-Out lists (LILO).

A linear queue is a linear data structure that serves the request first (arrived first).
It has two pointers: Front & Rear.

where the insertion takes place from the front end, 
and deletion occurs from the front end.

*/

/*
Operations on Linear Queue :
There are two operations that can be performed on a linear queue:
    1] Enqueue:
    The enqueue operation "inserts" the new element from the "rear end".

    2] Dequeue: 
    The dequeue operation is used to "delete" the existing element from the "front end" of the queue
*/


/*
Basic Operations
Queue operations may involve initializing or defining the queue,
utilizing it, and then completely erasing it from the memory.

Here we shall try to understand the basic operations associated with queues:
    • enqueue() − add (store) an item to the queue.
    • dequeue() − remove (access) an item from the queue.

Few more functions are required to make the above-mentioned queue operation efficient. These are :
    • isfull() − Checks if the queue is full.
    • isempty() − Checks if the queue is empty
*/




/*

Enqueue Operation
Queues maintain two data pointers, front and rear. Therefore, its
operations are comparatively difficult to implement than that of
stacks.
The following steps should be taken to enqueue (insert) data into
a queue −
• Step 1 − Check if the queue is full.
• Step 2 − If the queue is full, produce overflow error and exit.
• Step 3 − If the queue is not full, increment rear pointer to
point the next empty space.
• Step 4 − Add data element to the queue location, where the
rear is pointing.
• Step 5 − return success.
*/


/*
Dequeue Operation
Accessing data from the queue is a process of two tasks − access
the data where front is pointing and remove the data after access.
The following steps are taken to perform dequeue operation −
• Step 1 − Check if the queue is empty.
• Step 2 − If the queue is empty, produce underflow error and
exit.
• Step 3 − If the queue is not empty, Increment front pointer to
point to the next available data element.
• Step 4 − access the data where front is pointing.
• Step 5 − Return success.

*/


#include<iostream>
#include<conio.h>
//#define Size 8
using namespace std;

const int Size = 8;

template <class T>
class linearqueue {
    private:
        int front, rear, count ;
        T arr[Size];
    
    public:
        linearqueue() {
            front=-1;
            rear=-1;
            count=0;
        }
        
        bool isEmpty() {
            return ((rear==-1 && front==-1) || (front==Size-1) || (front==rear)) ? true:false;
            /*
            if((rear==-1 && front==-1)|| front==Size-1|| (front==rear))
                return true;
            else
                return false;
            */
            }

        bool isFull() {
            return (rear==Size-1) ? true:false;
            /*if(rear==Size-1)

                return true;
            else
                return false;*/
                
        }
        
        void enqueue (T item) {
            if(isFull()) {
                cout<<"Queue is Full\n"; }
            else {
                rear++;
                arr[rear]=item;
                count++;
                }
            }

        T dequeue () {
            T dequeueitem;
            if(isEmpty()) {
                cout<<"Queue is Empty\n";
                return 0;
            }
            else {
                front++;
                dequeueitem=arr[front];
                count--;
                return dequeueitem;//--→return arr[++front]
            } 
        }

        int numberofitems() { return count; }
        
        void print_rearandfront() { cout<<"\nrear="<<rear<<" front="<<front<<endl; }

        void print_queue() {
            for (int i = front+1; i <= rear; i++)
                cout << "Position : " << i << " , Value : " << arr[i]<<endl;
        }
};



int main() {
    int s;
    linearqueue <int> q1;
    q1.dequeue(); //empty
    q1.print_rearandfront(); //r=-1 f=-1
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);  
    q1.print_queue(); //position (0)=1 2 3 4 5 6
    q1.print_rearandfront();//r=5 f=-1
    cout<<"number of items in the queue: "<<q1.numberofitems()<<endl; //6
    s=q1.numberofitems();  // s = 6

    for(int i=0;i<s;i++)
        cout << q1.dequeue() << endl;
    
    q1.print_rearandfront(); //r=5 f=5
    cout<<"number of items in the queue: "<<q1.numberofitems()<<endl;//0

    q1.enqueue(77);
    q1.print_rearandfront(); //r=6 f=5

    q1.enqueue(88);
    q1.print_rearandfront();//r=7 f=5

    q1.enqueue(99); //full
    q1.print_queue(); // position (6)=88 99

    cout<<"number of items in the queue: "<<q1.numberofitems()<<endl; //2
    cout << q1.dequeue() << endl; //77
    q1.print_rearandfront(); //r=7 f=6

    cout<<"number of items in the queue: "<<q1.numberofitems()<<endl; //1
    cout << q1.dequeue() << endl; //88
    q1.print_rearandfront(); //r=7 f=7

    cout<<"number of items in the queue: "<<q1.numberofitems()<<endl; //0
    q1.enqueue(99); //full
    q1.print_queue();
    cout << q1.dequeue() << endl; //empty
    getch();

    return 0;
}







