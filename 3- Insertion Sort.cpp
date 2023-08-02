#include <iostream>
using namespace std ; 
void insertionSort (int array[] , int size);
void showArray (int array[] , int size);

int main() {
    int array [] = {9,1,8,2,7,3,6,4,5} ;
    int size = sizeof(array) / sizeof(array[0]) ; 

    cout << "The array that unsorted : " << endl; 
    showArray(array , size) ; cout << '\n' ;

    cout << "The array that sorted by insertion sort : " << endl; 
    insertionSort(array , size) ; 
    showArray(array , size) ; 

}

void insertionSort (int array[] , int size) {
    for (int i = 1 ; i < size ; i++) {
        int key = array[i] ;
        int j = i - 1 ; 

        while (key < array[j] && j >= 0) {
            array[j + 1 ] = array[j] ;
            -- j ;  
        }
        array[j + 1 ] = key ; 
    }
}

void showArray (int array[] , int size) {
    for (int i = 0 ; i < size ; i++) {
        cout << array[i] << " " ; 
    }
}