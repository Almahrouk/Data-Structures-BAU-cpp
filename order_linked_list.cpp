#include <iostream>
#include<conio.h>
using namespace std;

template <class T>
class orderedlinklist {
    private:
        template <class T>
        struct node {
            T data;
            node <T> *link;
        };
    node<T> *head;
    
    public:
        orderedlinklist();
        void insert( T num );
        T del( T num );
        void display();
        T count();
        ~orderedlinklist();
};

template <class T>
orderedlinklist<T>::orderedlinklist() {
    head = NULL;
}

template <class T>
void orderedlinklist<T>::insert(T num) {
    node <T>*q,*t,*n;
    n= new node <T>;
    n->data=num;
    if( head == NULL ) { // insert into empty list 
        head=n;
        head->link = NULL;
    }
    else if(num<head->data) { 
        n->link=head;
        head=n;
    }
    else {
        q=head;
        t=head->link;
        while(t!=NULL && num>t->data) {
            q=t;
            t=t->link;
        } 
        q->link=n;
        n->link=t;
    } 
}

template <class T>
T orderedlinklist<T>::del( T num ) {
    node <T>*q,*r;
    q = head;
    if( q->data == num ){ // delete from the beginning 
        head = q->link;
        delete q;
        return 0;
    }
    r = q;
    while( q!=NULL ) {
        if( q->data == num ){ 
            r->link = q->link;
            delete q;
            return 0;
        }
    r = q;
    q = q->link;
    }
    cout<<"\nElement "<<num<<" not Found.";
}

template <class T>
void orderedlinklist<T>::display() {
    node <T>*q;
    cout<<endl;
    for( q = head ; q != NULL ; q = q->link )
        cout<<endl<<q->data;
}

template <class T>T orderedlinklist<T>::count(){
    node <T>*q;
    int c=0;
    for( q=head ; q != NULL ; q = q->link )
        c++;
        return c;
}

template <class T>
orderedlinklist<T>::~orderedlinklist(){
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
    orderedlinklist <int>ll;
    cout<<"No. of elements = "<<ll.count();
    ll.insert(9);
    ll.insert(7);
    ll.insert(8);
    ll.insert(4);
    ll.insert(8);
    ll.insert(1);
    ll.insert(0);
    ll.insert(10);
    ll.insert(4);
    ll.insert(9);

    ll.display();
    //  ll.display();
    
    cout<<"\nNo. of elements = "<< ll.count();
    ll.del(5);
    ll.del(10);
    ll.del(0);
    cout<<"\nNo. of elements = "<< ll.count();
    ll.display();
    getch();
    return 0;
}