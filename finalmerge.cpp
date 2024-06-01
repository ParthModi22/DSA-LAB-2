#include <iostream>
using namespace std;

// Function to merge two sorted subarrays arr[l..m] and arr[m+1..r]
int merge(int *arr, int l, int m, int r) {
    int comparisons = 0;

    // Create temporary arrays
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int *L = new int[n1];
    int *R = new int[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        comparisons++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k++] = R[j++];
    }
    delete[] L;
    delete[] R;


    return comparisons;
}

// Merge sort function
int mergeSort(int arr[], int l, int r) {
    int comparisons = 0;
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Recursive calls to sort the first and second halves
        comparisons += mergeSort(arr, l, m);
        comparisons += mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        comparisons += merge(arr, l, m, r);
    }
    return comparisons; 
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int comparisons = mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
