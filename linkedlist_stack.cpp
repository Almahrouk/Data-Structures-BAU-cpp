#include <iostream>
#include<conio.h>
using namespace std;
template <class T>
class linkedstack{
    private:
        template <class T>
        struct node {
            T data;
            node <T> *link;
        };
    node <T> *head;

    public:
        linkedstack();
        void push(T element);
        T pop ();
        void display();
        T count();
        ~linkedstack();
};


template <class T>
linkedstack<T>::linkedstack() {
    head = NULL;
}

template <class T>
void linkedstack<T>::push(T element) {
    node <T>*q,*t;
    if( head == NULL ){ // insert into empty stack
        head = new node<T>;
        head->data = element;
        head->link = NULL;
    }
    else{ // append
        q = head;
        while( q->link != NULL )
            q = q->link;
            t = new node<T>;t->data = element;
            t->link = NULL;
            q->link = t;
    } 
}

template <class T>
T linkedstack<T>::pop () {
    T x;
    if( head == NULL ){ // check if the stack is empty
        cout<<"empty stack";
        return 0;
    }
    else{ // delete from the end of the stack
        node <T>*q,*r;
        q = head;
        r = q;
        while( q->link!=NULL ) {
            r = q;
            q = q->link;
        } 
        r->link=NULL;
        x=q->data;
        delete q;
        return x;
    } 
}

template <class T>
void linkedstack<T>::display() {
    node <T>*q;
    cout<<endl;
    for( q = head ; q != NULL ; q = q->link )
        cout<<endl<<q->data;
}

template <class T>
T linkedstack<T>::count() {
    node <T>*q;
    int c=0;
    for( q=head ; q != NULL ; q = q->link )
        c++;
        return c;
}

template <class T>
linkedstack<T>::~linkedstack() {
    node <T>*q;
    if( head == NULL )
        return;
    while( head != NULL ){
        q = head->link;
        delete head;
        head = q;
    } 
}

int main() {
    linkedstack <int>ls;
    cout<<"No. of elements = "<<ls.count()<<endl;
    ls.pop();
    ls.push(12);
    ls.push(10);
    ls.push(4);
    ls.push(9);
    ls.push(20);
    ls.push(15);
    ls.display();
    cout<<"\nNo. of elements = "<<ls.count()<<endl;
    cout<<"\npop 1:"<<ls.pop();
    cout<<"\npop 2:"<<ls.pop();
    cout<<"\npop 3:"<<ls.pop();
    cout<<" \npop 4:"<<ls.pop();
    cout<<"\nNo. of elements = "<<ls.count();
    cout<<"\n\nthe final stack";
    ls.display();
    getch();
    return 0;
}