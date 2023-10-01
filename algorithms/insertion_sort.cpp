# include <iostream>
# include <array>

using namespace std;

// This function will carry out the operations in the algorithm of Insertion Sort Method
void insertionSort(int array[], int size){
	for (int i = 1; i < size; i++){
		int temp = array[i];
		int j = i - 1;
		while (j > -1 && temp < array[j]){				// Order in which the conditions are written in the brackets matters. This condition is for j > -1 as j at -1 index is not valid. If array[j] is checked, this will result into array[-1] which will throw an error.
			array[j+1] = array[j];
			array[j] = temp;
			j--;
		}
	}
}

int main(){
    int myArray[] = {6, 4, 3, 6, 7, 8, 1, 4, 5, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);                // This is the method for calculating the length of an array
    
    insertionSort(myArray, size);
    
    for (auto value: myArray){
        cout << value << endl;
    }
}

// Operational Complexity for Insertion Sort is O(n^2) but in case of almost sorted arrays, the Operational Complexity will become O(n).