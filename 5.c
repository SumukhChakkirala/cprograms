#include <stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == target) {
            return mid;
        }

        // If the element is smaller than mid, it can only be present in the left subarray
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // Else the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    // The element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
