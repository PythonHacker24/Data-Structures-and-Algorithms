# include <iostream>

using namespace std;

void merge(int array[], int leftIndex, int midIndex, int rightIndex){

	// Calculating size of the two arrays that are derived from splitting the array
	int leftArraySize = midIndex - leftIndex + 1;
	int rightArraySize = rightIndex - midIndex;

	// Declaring new arrays where these splitted arrays are going to be defined
	int leftArray[leftArraySize];
	int rightArray[rightArraySize];

	// Loading new arrays with right and left elements of the array
	for (int i = 0; i < leftArraySize; i++){
		leftArray[i] = array[leftIndex + i];
	}
	for (int j = 0; j < rightArraySize; j++){
		rightArray[j] = array[midIndex + 1 + j];
	}

	// initializing variables
	int index = leftIndex;
	int i = 0;
	int j = 0;

	// Arranging the main array with elements in order of small to large size from the leftArray and rightArray
	while (i < leftArraySize && j < rightArraySize){
		if (leftArray[i] <= rightArray[j]){
			array[index] = leftArray[i];
			index++;
			i++;
		}
		else{
			array[index] = rightArray[j];
			index++;
			j++;
		}
	}

	// If leftArray elements are left over, add them at the end of the main array
	while (i < leftArraySize){
		array[index] = leftArray[i];
		index++;
		i++;
	}

	// If rightArray elements are left over, add them at the end of the main array
	while (j < rightArraySize){
		array[index] = rightArray[j];
		index++;
		j++;
	}

}

void mergeSort(int array[], int leftIndex, int rightIndex){
	if (leftIndex >= rightIndex) return;

	int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
	mergeSort(array, leftIndex, midIndex);
	mergeSort(array, midIndex + 1, rightIndex);

	merge(array, leftIndex, midIndex, rightIndex);
}

/*

int main(){
	int myArray[] = {1,3,7,8,2,4,5,6};

	int size = sizeof(myArray) / sizeof(myArray[0]);
	int leftIndex = 0;
	int rightIndex = size - 1;
	int midIndex = (size / 2) - 1;

	merge(myArray, leftIndex, midIndex, rightIndex);

	for (auto value : myArray){
		cout << value << endl;
	}
}    

*/

int main(){
	int myArray[] = {3, 1, 4, 2};

	int size = sizeof(myArray) / sizeof(myArray[0]);
	int leftIndex = 0;
	int rightIndex = size - 1;

	mergeSort(myArray, leftIndex, rightIndex);

	for(auto value : myArray){
		cout << value << " ";
	}
}    


/* // My solution to the merge function problem

#include <iostream>

using namespace std;

class Sort {
    public:
    
	int merge(int array[], int leftIndex, int midIndex, int rightIndex){
	    int alphaLength = midIndex - leftIndex + 1;
	    int bravoLength = rightIndex - midIndex;
	    
	    int alpha[alphaLength];
	    int bravo[bravoLength];
	    
	    // Loading alpha and bravo with respective elements
	    for (int i = 0; i < alphaLength; i++){
	        alpha[i] = array[leftIndex + i];
	    }
	    for (int k = 0; k < bravoLength; k++){
	        bravo[k] = array[midIndex + 1 + k];
	    }
	    
	    int i = 0;
	    int j = 0;
	    int index = leftIndex;
	    
	    // arranging the array back in the order
	    while (i < alphaLength && j < bravoLength){
	        if (alpha[i] <= bravo[j]){
	            array[index] = alpha[i];
	            index++;
	            i++;
	        }
	        else{
	            array[index] = bravo[j];
	            index++;
	            j++;
	        }
	    }
	    
	    // Filling leftover part
	    while (i < alphaLength){
	        array[index] = alpha[i];
	        index++;
	        i++;
	    }
	    
	    while (j < bravoLength){
	        array[index] = array[j];
	        index++;
	        j++;
	    }
	    
	    
	}
	
};

*/       

/* // My solution to the merger sort function problem

void mergeSort(int array[], int leftIndex, int rightIndex){
            if (leftIndex >= rightIndex) return;
            
            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
            mergeSort(array, leftIndex, midIndex);
            mergeSort(array, midIndex + 1, rightIndex);
            
            merge(array, leftIndex, midIndex, rightIndex);
            
        }

*/