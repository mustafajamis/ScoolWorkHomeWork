#include <iostream>
using namespace std;

// Function declarations
void swap(int& x, int& y);
void print(int array[], int size);
int partition(int arr[], int beg, int end);
void quicksort(int arr[], int beg, int end);

int main()
{
    // Declaration of an unsorted array
    int array[10] = { 27, 22, 11, 94, 83, 14, 30, 19, 46, 33 };

    // Printing unsorted array
    cout << "Original array: " << endl;
    print(array, 10);

    // Calling quicksort function
    quicksort(array, 0, 9);

    // Printing sorted array
    cout << "Sorted array: " << endl;
    print(array, 10);

    return 0;
}

// TODO: Swap function
void swap(int& x, int& y)
{
    // Swaps the values of two variables
    int temp = x;
    x = y;
    y = temp;
}

// TODO: Print-array function
void print(int array[], int size) {
    // Prints the elements of the array
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

// TODO: Partition function
int partition(int arr[], int beg, int end)
{
    // Selects the pivot element
    int pivot = arr[end];
    int i = (beg - 1);

    // Iterate through the array and rearrange elements based on the pivot
    for(int j = beg; j < end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot in its correct position
    swap(arr[i + 1], arr[end]);
    return (i + 1); // Return the index of the pivot
}

// TODO: Quicksort function
void quicksort(int arr[], int beg, int end)
{
    // Recursive implementation of quicksort
    if(beg < end){
        int pivVlInd = partition(arr, beg, end);
        quicksort(arr, beg, pivVlInd - 1);
        quicksort(arr, pivVlInd + 1, end);
    }
}
