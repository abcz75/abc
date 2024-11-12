#include <stdio.h>
#include <stdlib.h>  // For exit function

#define MAX_SIZE 100

int heap_size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && arr[left] > arr[largest])
        largest = left;

    if (right < heap_size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, largest);
    }
}

void insert(int arr[], int key) {
    if (heap_size == MAX_SIZE) {
        printf("Heap Overflow\n");
        return;
    }

    heap_size++;
    arr[heap_size - 1] = key;

    int i = heap_size - 1;
    // Maintain Max-Heap property
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[(i - 1) / 2], &arr[i]);
        i = (i - 1) / 2;
    }
}

void delete_max(int arr[]) {
    if (heap_size == 0) {
        printf("Heap Underflow\n");
        return;
    }

    arr[0] = arr[heap_size - 1];
    heap_size--;
    heapify(arr, 0);
}

void display(int arr[]) {
    if (heap_size == 0) {
        printf("Heap is empty\n");
        return;
    }

    for (int i = 0; i < heap_size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int choice, key;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(arr, key);
                break;
            case 2:
                delete_max(arr);
                break;
            case 3:
                display(arr);
                break;
            case 4:
                exit(0);  // exit() is now defined
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
