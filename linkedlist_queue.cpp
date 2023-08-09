#include <iostream>
using namespace std;
#include<conio.h>
template <class T>
class LinkedQueue{
    private:
        template <class T>
        struct node{
            T data;
            node <T> *link;
        };
        node <T> *head;

    public:
        LinkedQueue();
        void enequeue(T element);
        T dequeue();
        void display();
        T count();
        ~LinkedQueue();
};

template <class T>
LinkedQueue<T>::LinkedQueue(){
    head = NULL;
}

template <class T>
void LinkedQueue<T>::enequeue(T element){
    node <T>*q,*t;
    if( head == NULL ) {// insert into empty queue
        head = new node<T>;
        head->data = element;
        head->link = NULL;
    }
    else{ // append
        q = head;
        while( q->link != NULL )
            q = q->link;
            t = new node<T>;
            t->data = element;t->link = NULL;
            q->link = t;
    } 
}

template <class T>
T LinkedQueue<T>::dequeue( ){
    node <T>*q;
    T x;
    q = head;
    if(head==NULL){ // check if the queue is empty
        cout<<"empty queue";
        return 0;
    }
    else{
        head = q->link; // delete from the beginning of the queue
        x = q->data;
        delete q;
        return x;
    } 
}

template <class T>
void LinkedQueue<T>::display(){
    node <T>*q;
    cout<<endl;
    for( q = head ; q != NULL ; q = q->link )
        cout<<endl<<q->data;
}

template <class T>
T LinkedQueue<T>::count(){
    node <T>*q;
    int c=0;
    for( q=head ; q != NULL ; q = q->link )
        c++;
        return c;
}

template <class T>
LinkedQueue<T>::~LinkedQueue(){ 
    node <T>*q;
    if( head == NULL )
        return;
    while( head != NULL ){
        q = head->link;
        delete head;
        head = q;
    } 
}

int main(){
    LinkedQueue <int>lq;
    cout<<"No. of elements = "<<lq.count()<<endl;
    lq.dequeue();
    lq.enequeue(12);
    lq.enequeue(10);
    lq.enequeue(7);
    lq.enequeue(11);
    lq.enequeue(17);
    lq.enequeue(4);
    lq.display();
    cout<<"\nNo. of elements = "<<lq.count();
    cout<<"\ndeque 1: "<<lq.dequeue();
    cout<<"\ndeque 2: "<<lq.dequeue();
    cout<<"\ndeque 3: "<<lq.dequeue();
    cout<<"\ndeque 4: "<<lq.dequeue();
    cout<<"\nNo. of elements = "<<lq.count();
    cout<<"\n\nthe final queue";
    lq.display();
    getch();
    return 0;
}









