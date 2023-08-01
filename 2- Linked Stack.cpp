#include <iostream>
using namespace std ;
template <class T>
class Stack {
private :
    struct node {
        T item ;
        node *next ;
    };
    node *top , *current ;
public :
    Stack() {
        top = NULL ;
    }
    void push (T newItem) {
        node *newItemPtr = new node ;
        if (newItemPtr == NULL) {
            cout << "Stack push can't allocate a memory !" << endl;
        }
        else {
            newItemPtr -> item = newItem ;
            newItemPtr -> next = top ;
            top = newItemPtr ;
        }
    }

    bool isEmpty () {
        if (top == NULL) {
            return true ;
        }
        else {
            return false ;
        }
    }

    void pop () {
        if (isEmpty()) {
            cout << "The Stack is empty on the top ! " << endl ;
        }
        else {
            node *temp = new node ;
            top = top -> next = NULL ;
            delete temp ;
        }
    }

    void pop (T &Element) {
        if (isEmpty()) {
            cout << "The Stack is empty on the top ! " << endl ;
        }
        else {
            Element = top -> item ;
            node *temp = new node ;
            top = top -> next = NULL ;
            delete temp ;
        }
    }
    void getTop (T &Element) {
        if (isEmpty()) {
            cout << "The Stack is empty on the top ! " << endl ;
        }
        else {
            node *temp = new node ;
        }
    }

    void Show () {
        current = top ;
        cout << "[" ;
        while (current != NULL) {
            cout << current -> item << " ";
            current = current -> next ;
        }
        cout << "]" << endl;
    }
};

int main () {
    int Element ;
    Stack <int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.Show() ;
    ///
    S.pop(Element) ;
    cout << Element << endl ;
    return 0 ;
}