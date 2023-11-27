#include <iostream>
using namespace std ; 
void swap (int & num1 , int & num2);
void showArray (int num [] , int size);
void selectionSort(int array[], int size);

int main () {
    int numbers [] = {9,1,8,2,7,3,6,4,5} ; 
    int size = sizeof(numbers) / sizeof(numbers[0]) ;

    cout << "The array : " << endl;
    showArray(numbers , size) ; 

    cout << "After the ordering : " << endl; 
    selectionSort(numbers , size) ; 
    showArray(numbers,size) ;
}

void swap (int * num1 , int * num2) {
    int temp = *num1 ;
    *num1 = *num2 ; 
    *num2 = temp ; 
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}

void showArray (int num [] , int size) {
    for (int i = 0 ; i < size ; i ++) {
        cout << num[i] << " " ;
    }
    cout << endl;
}
