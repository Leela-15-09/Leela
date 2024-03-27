#include <stdio.h>

int are_elements_unique(int arr[], int size) {
    // Create an array to store encountered elements
    int encountered[100000] = {0}; // Assuming the maximum element value is 100000
    
    // Iterate through the array
    for (int i = 0; i < size; i++) {
        // If the element is already encountered, it's not unique
        if (encountered[arr[i]] == 1) {
            return 0;
        }
        // Mark the element as encountered
        encountered[arr[i]] = 1;
    }
    
    // If all elements are unique, return 1
    return 1;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (are_elements_unique(arr, size)) {
        printf("All elements in the array are unique.\n");
    } else {
        printf("Array contains duplicate elements.\n");
    }
    
    return 0;
}
