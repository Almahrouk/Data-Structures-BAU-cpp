#include <iostream>
#include<conio.h>
//#include<string>
using namespace std;
template <class T>
class unorderednextlist {
    private:
        template <class T> 
        struct node {
            T data;
            node<T> *next;
        };
        node<T> *head;

    public:
        unorderednextlist() {
            head = NULL;
        }
        ~unorderednextlist() {
            node<T> *q;
            if( head == NULL )
                return ;
            
            while( head != NULL ) {
                q = head->next;
                delete head;
                head = q;
            } 
        }
    void insert( T num );
    void add_as_first( T num );
    void addafter( T c, T num );
    T del( T num );
    void display();
    T count();
};


template <class T>
void unorderednextlist<T>::insert(T num) {
    node<T> *q,*t;
    if( head == NULL ) {// insert into empty list
        head = new node<T>;
        head->data = num;
        head->next = NULL;
    }
    else { //append
        q = head;
        while( q->next != NULL ){
            q = q->next;
            t = new node<T>;
            t->data = num;
            q->next= t;
            t->next = NULL;
        } 
    }
}

template <class T>
void unorderednextlist<T>::add_as_first(T num) {// insert in the beginning
    node <T>*q;
    q = new node<T>;
    q->data = num;
    q->next = head;
    head = q;
}

template <class T>
void unorderednextlist<T>::addafter( T c, T num) { // insert in the middle
    node <T>*q,*t;
    int i;
    for(i=1,q=head;i<c;i++) {
        q = q->next;
        if( q == NULL ) {
            cout<<"\nThere are less than "<<c<<" elements.";
            return ;
        } 
    }

    t = new node<T>;
    t->data = num;
    t->next = q->next;
    q->next = t;
}

template <class T>
T unorderednextlist<T>::del( T num ) {
    node <T>*q,*r;
    q = head;
    if( q->data == num ) { // delete from the beginning
        head = q->next;
        delete q;
        return 0;
    }

    r = q;
    while( q!=NULL ) {
        if( q->data == num ) { 
            r->next = q->next;
            delete q;
            return 0;
        }
    
    r = q;
    q = q->next;
    }

    cout<<"\nElement "<<num<<" not Found."<<endl;
    T arr[count()];
    
}


template <class T>
void unorderednextlist<T>::display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    
    else {
        node <T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}


template <class T>
T unorderednextlist<T>::count() {
    node <T>*q;
    int c=0;
    for( q = head; q != NULL; q = q->next )
        c++;
        return c;
}


int main() {
    unorderednextlist <int> ll;
    cout<<"No. of elements = "<<ll.count();
    ll.insert(12);
    ll.insert(13);
    ll.insert(23);
    ll.insert(43);
    ll.insert(44);
    ll.insert(50);
    ll.add_as_first(2);
    ll.add_as_first(111);
    ll.addafter(2,333);
    ll.addafter(6,666);
    ll.display();
    cout<<"\nNo. of elements = "<<ll.count();
    ll.del(333);
    ll.del(12);
    ll.del(98);
    cout<<"\nNo. of elements = "<<ll.count();
    ll.display();
    getch();
    return 0;
}