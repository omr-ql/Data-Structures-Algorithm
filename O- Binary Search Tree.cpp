#include <iostream>
#include <queue>
#include <algorithm>
using namespace std ; 
class Node { 
public :
    int data ;
    Node* right = NULL ; 
    Node* left = NULL ; 
    Node (int value) {
        data = value ;
        right = NULL ;
        left = NULL ; 
    }
};

class BST {
public : 
    Node* root ; 
    BST () {
        root = NULL ; 
    }

    Node* Insert (Node* pnode , int item) {
        if (pnode == NULL) {
            Node * newNode = new Node(item) ; 
            pnode = newNode ;
        }

        else if (item < (pnode -> data)) {
            pnode -> left = Insert(pnode->left,item) ; 
        }

        else {
            pnode -> right = Insert(pnode -> right , item) ; 
        }
        return pnode ; 
    }

    void Insert (int item) {
        root = Insert(root , item) ; 
    }

    Node* Search (Node* r , int key) {
        
        if (r == NULL) {
            return NULL ;
        }
        else if (r -> data == key) {
            return r ; 
        }
        else if (key < (r -> data)) {
            return Search( (r->left) , key ) ; 
        }
        else {
            return Search( (r -> right) , key ) ; 
        }
    }

    bool Search (int key ) {
        Node* result = Search (root , key) ; 

        if (result == NULL) {
            return false ; 
        }
        else {
            return true ; 
        }
    }

     Node* minNode (Node* r) {
        if (r == NULL) {
            return NULL ; 
        }
        else if (r -> left == NULL) {
            return r ; 
        }
        return minNode (r->left) ; 
    }
    Node* maxNode (Node* r) {
        if (r == NULL) {
            return NULL ; 
        }
        else if (r->right == NULL) {
            return r ;
        }

        return maxNode(r->right) ; 
    }

    Node* Deletion (Node* r , int key) {
        if (r == NULL) {
            return NULL ; 
        }
        if (key < r-> data) {
            r->left = Deletion(r->left , key) ;
        }
        else if (key > r-> data) {
            r->right = Deletion(r->right , key) ; 
        }
        else {
            if (r->left == NULL && r->right == NULL) {
                r = NULL ; 
            }
            else if (r-> left != NULL && right) {
                r ->data = r ->left ->data ; 
                delete r->left ; 
                r ->left = NULL ; 
            }
            else if (r->left == NULL && r->right) {
                r-> data = r-> right-> data ; 
                delete r->right ; 
                r->right = NULL ;  
            }
            else {
                Node* max = maxNode(r->left) ; 
                r -> data = max -> data ; 
                r -> left = Deletion(r -> left , max->data) ;
            }   
            return r ;
        }
    }

    void breadthFirstTraversal (Node* root) {
        if (!root) {
            return;
        }

        queue <Node*> q ; 
    
        q.push(root) ; 

        while (!q.empty()) {
            Node* current = q.front() ; 
            q.pop() ; 
            
            cout << current -> data << " " ; 

            if (current -> left) {
                q.push (current -> left) ; 
            }

            if (current -> right) {
                q.push(current -> right) ; 
            }
        }
    } 	

    void PreOrder (Node* r) { // data -> left -> right 
        if (r == NULL) {
            return ;
        }

        cout << r -> data << " * ";  ; 
        PreOrder(r -> left) ;
        PreOrder(r -> right) ;
    }

    void InOrder (Node* r) { // left -> data -> right 
        if (r == NULL) {
            return ; 
        }

        InOrder (r -> left);
        cout << r -> data << " * ";  ; 
        InOrder(r -> right);

    }

    void PostOrder (Node * r) { // left -> right -> data 
        if (r == NULL) {
            return ; 
        }
        PostOrder(r -> left) ; 
        PostOrder(r -> right) ; 
        cout << r->data << " * "; 
    }
}; 

int main () {
    BST B ; 

    B.Insert(45);
    B.Insert(15);
    B.Insert(79);
    B.Insert(90);
    B.Insert(10);
    B.Insert(55);
    B.Insert(12);
    B.Insert(20);
    B.Insert(50);

    B.InOrder(B.root) ; 
    cout << endl; 
    B.PreOrder(B.root) ; 
    cout << endl; 
    B.PostOrder(B.root) ; 

    int key ; 
    cout << "Enter your value :" << endl; 
    cin >> key ; 

    if (B.Search(key)) {
        cout << "Your item " << key << " has been found !" << endl; 
    }
    else {
        cout << "Your item " << key <<" Item missed" << endl; 
    }

    int num ; 
    cout << "Enter the item that you want to delete : " << endl; 
    cin >> num ; 
    Node * result = B.Deletion(B.root , num ) ; 
    cout << "The Tree will after delete " << num << " will be : " << endl; 
    B.PreOrder(result) ; 	
    return 0 ; 
}