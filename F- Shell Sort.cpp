#include <iostream>
using namespace std ;
void shellSort (int numbers[] , int size) ;
void showData (int numbers[], int size) ;
int main () {
    int numbers [] = {9,1,8,2,7,3,6,4,5} ;
    int size = sizeof(numbers) / sizeof(numbers[0]) ;
    cout << "Unsorted Array : " << endl;
    showData(numbers ,size) ;
    cout << "sorted Array : " << endl;
    shellSort(numbers ,size) ;
    showData(numbers ,size) ;
    return 0 ;
}

void shellSort(int array[], int n) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

void showData (int numbers[], int size) {
    for (int i = 0 ; i < size ; i++) {
        cout << numbers[i] << " ";
    }
    cout << '\n' ;
}
