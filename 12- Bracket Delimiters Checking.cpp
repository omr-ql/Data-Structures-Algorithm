#include <iostream>
#include <string>
#include <stack>
using namespace std ; 

bool arePaired (char open , char close) {
    if (open == '(' && close == ')') {
        return true ;  
    }
    else if  (open == '{' && close == '}') {
        return true ;  
    } 
    else if (open == '[' && close == ']') {
        return true ;  
    } 
    return false ; 
}

bool areBalanced (string expression) {
    stack <char> character ; 
    for (int i = 0 ; i < expression.length() ; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
            character.push(expression[i]) ; 
        }

        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
            if (character.empty() || !arePaired(character.top() , expression[i]) ) {
                return false ; 
            }
            else {
                character.pop() ; 
            }
        }
    }  
    return character.empty() ; 
}

int main () {
    string expression ; 
    cout << "Enter your expression " << endl; 
    cin >> expression ; 
    if (areBalanced(expression)){
        cout << "Balanced ! " << endl; 
    }
    else {
        cout << "Not Balanced ! " << endl;  
    }
    return 0 ;
}