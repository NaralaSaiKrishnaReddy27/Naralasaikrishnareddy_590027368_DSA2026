#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, i;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed! Exiting...\n");
        return 1; 
    }

    printf("Memory successfully allocated.\n");

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements in the array are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    printf("Memory successfully freed. Program terminating.\n");

    return 0;
}