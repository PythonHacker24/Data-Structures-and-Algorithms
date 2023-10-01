#include <iostream>
#include <array>

using namespace std;

// This function will carry out the operations in the algorithm of Bubble Sort Method
int bubbleSort(int array[], int size){
    for (int i = size - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(){
    int myArray[] = {6, 4, 3, 6, 7, 8, 1, 4, 5, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);                // This is the method for calculating the length of an array
    
    bubbleSort(myArray, size);
    
    for (auto value: myArray){
        cout << value << endl;
    }
}

// Operational Complexity for Bubble Sort is O(n^2)