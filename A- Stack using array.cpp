#include <iostream>
using namespace std ;
const int MAX_SIZE = 100 ;
template <class T>
class stack {
private:
    T top ;
    T item[MAX_SIZE] ;
public :
    stack() : top(-1) {}
    void push (T Element) {
        if (top > MAX_SIZE) {
            cout << "The Stack is full " << endl;
        }
        else {
            top ++ ;
            item[top] = Element ;
        }
    }
    bool isEmpty () {
        if (top == -1 ) {
            return true ;
        }
        else {
            return false ;
        }
    }
    void pop () {
        if (isEmpty()) {
            cout << "The Stack is Empty already ! " << endl;
        }
        else {
            top -- ;
        }
    }
    void pop (T &Element) {
        if (isEmpty()) {
            cout << "The Stack is Empty already ! " << endl;
        }
        else {
            Element = item[top] ;
            top-- ;
        }
    }
    void getTop (T &Element) {
        if (isEmpty()) {
            cout << "The Stack is Empty on the Top ! " << endl;
        }
        else {
            Element = item[top] ;
            cout << "The Top of the stack is : " << Element << endl;
        }
    }
    void show () {
        cout << "[" ;
        for (T i = top ; i >= 0 ; i--) {
            cout << item[i] << " ";
        }
        cout << "]" ;
        cout << endl;
    }
};

int main () {
    int Top;
    stack <int> S ;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.show() ;
    //////////////////////////////////////////////////
    S.getTop(Top) ;
    //////////////////////////////////////////////////
    if (S.isEmpty() == true) {
        cout << "The stack is empty" << endl;
    }
    else {
        cout << "There already elements in the stack" << endl;
    }
    //////////////////////////////////////////////////
    S.pop(Top) ;
    S.show() ;
    //////////////////////////////////////////////////
    return 0 ;
}
