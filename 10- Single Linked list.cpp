#include <iostream>
using namespace std ; 
class Node {
public :
    int data ; 
    Node * next ;

    Node() {
        data = 0 ; 
        next = NULL ; 
    }
};

class linkedList {
public : 
    Node* head ; 

    linkedList() {
        head = NULL ; 
    }

    bool isEmpty () {
        if (head == NULL) {
            return true ; 
        }
        else {
            return false ; 
        }
    }

    Node* insertAtFirst (int element) {
        if (isEmpty()) {
            Node* newNode = new Node ; 
            newNode -> data = element ; 
            newNode -> next = NULL ; 
            head = newNode ; 
            return newNode ; 
        }
        else {
            Node * newNode = new Node ;
            newNode -> data = element ;
            newNode -> next = head ; 
            head = newNode ;
            return newNode ; 
        }
        
    }

    Node* insertAtPosition (int item , int element) {
            if (isEmpty()) {
                insertAtFirst(element) ; 
            }
            else {
                Node * newNode = new Node ;
                newNode -> data = element ; 
                Node* current = head ; 
                while (current != NULL && current -> next -> data != item) {
                    current = current -> next ; 
                }
                newNode -> next = current -> next ; 
                current -> next = newNode ; 
                return newNode; 
            }
        }

    Node* insertAtLast (int element) {
        if (isEmpty()) {
            insertAtFirst(element) ; 
        }
        else {
            Node* current = head ; 
            while (current -> next != NULL) {
                current = current -> next ;  
            }
            Node* newNode = new Node ; 
            newNode -> data = element ; 
            current -> next = newNode ; 
            newNode -> next = NULL ; 
            return newNode ; 
        }
    }
    int count () {
        int counter = 0 ;  
        Node* current = head ;
        while (current != NULL) {
            counter ++; 
            current = current -> next ; 
        } 
        return counter ; 
    }

    bool find (int element) {
            Node* current = head ; 
            while (current != NULL) {
                if (element == current -> data ) {
                    return true ;
                }
                else {
                    return false ; 
                }

            }
    }

    void Deletion (int element) {
        if (isEmpty()) {
            cout << "The list is empty" << endl;                 
        }
        else if (head -> data == element) {
            Node* delPtr = head ; 
            head = head -> next ; 
            delete delPtr ; 
        }
        else {
            Node* delPtr = head; 
            Node* prePtr = NULL ; 
            while (delPtr -> data != element) {
                prePtr = delPtr ; 
                delPtr = delPtr -> next ; 
            } 
            prePtr -> next = delPtr -> next ; 
            delete delPtr ; 
        }
    }
    void showData () {
            Node* current = head ; 
            while (current != NULL) {
                cout << current -> data << " " ;
                current = current -> next ;  
            }
            cout << endl;
    }
};  


int main () {
    linkedList l ; 
    l.insertAtFirst(12); 
    l.insertAtFirst(23);
    l.insertAtFirst(34); 
    l.insertAtFirst(49); 
    l.insertAtFirst(52) ; 

    cout << "Here is your elements : " << endl; 
    l.showData() ; 

    int number , item;

    // cout << "Enter your Number : " << endl; 
    // cin >> number ; 

    /* To chick whatever the element inside or not*/
    // if (l.founder(number)) {
    //     cout << "Founded !" << endl; 
    // }
    // else {
    //     cout << "Not founded :(" << endl; 
    // }

    /*To insert an element in specific place*/
    // cout << "Enter the place you want to insert in and the value of the place : " << endl; 
    // cin >> item >> number ; 
    // l.insertAtPosition(item , number) ; 
    // l.showData() ; 

    /*To insert element from the last : */

    // cout << "Enter the number that you want to add : " << endl; 
    // cin >> number ; 

    // l.insertAtLast(number) ; 
    // l.showData() ; 

    /*To Delete The data : */ 

    cout << "Enter the element to delete it : " << endl; 
    cin >> number ; 
    l.Deletion(number) ;
    cout << "The linked list after the deletion : " << endl; 
    l.showData() ; 

    return 0 ; 
}