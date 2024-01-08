#include <iostream> 
using namespace std ;
void bubbleSort(int numbers[] , int size) ;
int main () {
    int numbers[] = {9,1,8,2,7,3,6,4,5} ; 

    cout << "The numbers are in random place : " << endl; 
    for (int i = 0 ; i < sizeof(numbers) / sizeof(numbers[0])  ; i++) {
        cout << numbers[i] << " " ;
    }

    cout << endl; 

    cout << "The numbers in a order : " << endl; 
    bubbleSort(numbers ,9) ;

    for (int x : numbers) {
        cout << x << " " ; 
    } 
}
void bubbleSort (int numbers[] , int size) {
    for (int i = 0 ; i < size ; i++) {
        for (int j = 0 ; j < size ; j++) {
                if (numbers[j] > numbers[j+1]) {
                    int temp = numbers[j] ; 
                    numbers[j] = numbers[j+1] ; 
                    numbers[j+1] = temp ;
                }    
            } 
        }
} 
