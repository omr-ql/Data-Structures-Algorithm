#include <iostream>
using namespace std ;
class Node {
public :
    int data ;
    Node * next ;
    Node () {
        data = 0 ;
        next = NULL ;
    }
};

class Queue {
public :
    Node* front ; 
    Node* rear ; 

    Queue () {
        front = rear = NULL ; 
    }
    bool isEmpty () {
        if (front == NULL && rear == NULL) {
            return true ; 
        } 
        else {
            return false ; 
        }
    }

    void EnQueue (int num) {
        if (isEmpty()) {
            Node *newnode = new Node ; 
            newnode -> data = num ;
            front = rear = newnode ; 
        }
        else {
            Node *newnode = new Node ; 
            newnode -> data = num ;
            rear -> next = newnode ; 
            rear = newnode ; 
        }
    } 

    int DeQueue () {
        int delVal = 0 ; 
        if (isEmpty()) {
            throw runtime_error("Empty List") ; 
        }

        else if(front == rear) {
            delete front ; 
            front = rear = NULL ; 
        }

        else {
            Node* delPtr = front ; 
            front = front -> next ; 
            delVal = delPtr -> data ; 
            delete delPtr ; 
        }

        return delVal ; 
    }

    int getFront () {
        return front -> data ;
        cout << endl ; 
    }

    int getRear () {
        return rear -> data ; 
        cout << endl ; 
    }
    int counter () {
        int counter = 0 ; 
        Node* current = front ; 
        while (current != NULL) {
            counter ++ ; 
            current = current -> next ; 
        }
        return counter ;
         cout << endl ;  
    }   

    int Search (int element) {
        Node* current = front ; 
        while (current != NULL) {
            if (current->data == element) {
                cout << "The Number found ! which is = " << element << endl;
            }
            current = current -> next ; 
        }
        cout << endl ; 
    }

    void Clear () {
        Node* current = front ; 
        while (!isEmpty()) {
            DeQueue() ; 
        }
    }
    int sum (int num) {
        int counter = 0 ; 
        Node* currnet = front ; 

        while (currnet != NULL)
        {
            counter = counter + (currnet -> data) ; 
            currnet = currnet -> next ; 
        }
        return counter ; 
    }

    double avarege (int num) {
        double counter = 0 ; 
        Node* currnet = front ; 

        while (currnet != NULL)
        {
            counter = counter + (currnet -> data) ; 
            currnet = currnet -> next ; 
        }
        return (counter) / num ; 
    }

    int mode (int num) {
        Node* current = front ; 
        while (current != NULL ) {
            if ((current -> data) == (current -> next -> data)) {
                cout << current -> data << endl; 
            }
            current = current -> next ; 
        }
        
    }

    void clear () {
        if (isEmpty()) {
            throw runtime_error("The list empty") ; 
        }
        else {
            Node* current = front ; 
            while (current != NULL) {
                DeQueue() ; 
            }
        }
    }
    void showData () {
        Node * current = front;
        while (current != NULL) {
            cout << current ->data ; 
            current = current -> next ; 
            cout << " > " ; 
        }
        cout << "NULL" ; 
        cout << '\n' ; 
    }
    
};
int main () {
    Queue q ;
    int items ; 
    cout << "Enter your items : " ; 
    cin >> items ; 
    for (int i = 0 ; i < items ; i++) {
        int element ;
        cout << "Enter your elements : " << endl;
        cin >> element ;
        q.EnQueue(element) ;
    }

    cout << "The Elements are : " << endl;
    q.showData() ;

    cout << "The Number of the elements in your queue = " << q.counter() << endl; 

    cout << "The first elements in your queue -> " << q.getFront() << endl; 
    cout << "The first elements in your queue -> " << q.getRear() << endl;
    
    int num ; 
    cout << "Enter the element that you want to search : " ; 
    cin >> num ; 
    q.Search(num) ; 

    cout << "The elements after 1st dequeue : " << endl;
    q.DeQueue() ;
    q.showData() ;
    
    cout << "The elements after 2nd dequeue : " << endl;
    q.DeQueue() ;
    q.showData() ;

    cout << "The Queue after deleting : " ;  
    q.Clear() ; 
    return 0 ; 
}