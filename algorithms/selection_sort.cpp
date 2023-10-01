# include <iostream>
# include <array>

using namespace std;

// This function will carry out the operations in the algorithm of Selection Sort Method
int selectionSort(int array[], int size){
	for (int i = 0; i < size; i++){
		int minIndex = i;
		for (int j = i + 1; j < size; j++){
			if (array[j] < array[minIndex]){
				minIndex = j;
			}
		}
		if (i != minIndex){
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}

int main(){
    int myArray[] = {6, 4, 3, 6, 7, 8, 1, 4, 5, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);                // This is the method for calculating the length of an array
    
    selectionSort(myArray, size);
    
    for (auto value: myArray){
        cout << value << endl;
    }
}

// Operational Complexity for Selection Sort is O(n^2)