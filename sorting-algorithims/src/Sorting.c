#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void insertionsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) { //create a for loop for i = 1 and loop until it is greater than n
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int arr[], int n) {
    int i = 0, j = 0, tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (arr[j] > arr[j + 1]) {  // swap if order is broken
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

 void heapify(int arr[], int n, int i) { //function to prepare array for heap sort by setting the order of values of PArent and Children Nodes
    int max = i;
    int leftChild = 2 * i + 1; 
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[max])
      max = leftChild;

    if (rightChild < n && arr[rightChild] > arr[max])
      max = rightChild;

    if (max != i) {
      swap(&arr[i], &arr[max]);
      heapify(arr, n, max);
    }
  }

  void heapsort(int arr[], int n) { //heap sort algorithim
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      heapify(arr, i, 0);
    }
  }


int ArrayGeneration(int arr[], int size) { //function for array generation

    srand(time(NULL));

    for(int y=0; y < size; y++) { //for loop that exists for y < size
        arr[y] = rand() % size; //generates and fills arr[y] with true random numbers > 1000000
    }
    return 0;
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void sort_exe(int arr[], int size, int algorithim) {
    clock_t start, end;
    double timeTotal;

    for(int x=0; x < size; x++) {
        ArrayGeneration(arr, size);
        switch(algorithim){ //this causes the program to run a matrix to run each of the cases
            case 0:
                start = clock(); //clock start
                insertionsort(arr, size); //sort algorithim ran
                end = clock(); //clock stop
                break; //stops case 0
            case 1:
                start = clock(); //clock start
                quicksort(arr, 0, size); //sort algorithim ran
                end = clock();//clock stop
                break; //stops case 1
            case 2:
                start = clock();//clock starts
                bubble_sort(arr, size); //sort algorithim ran
                end = clock(); //clock stop
                break; //stops case 2
            case 3:
                start = clock(); //clock start
                heapsort(arr, size); //sort algorithim runs
                end = clock(); //clock ends
                break; //stops case 3
        }
        timeTotal = timeTotal + ((double) (end - start)) /CLOCKS_PER_SEC;
    }
    printf("Took %f seconds to run sort successfully\n", timeTotal);
}

void reverse_array(int arr[], int size){
  for (int i = 0; i < size / 2; i++){
    int tmp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = tmp;
  }
}

int main (int argc, char * argv[]) {
int size;

size = atoi(argv[1]);

int ss_arr[size];
int quick_arr[size];
int bubble_arr[size];
int heap_arr[size];

printf("Selection Sort\n");
sort_exe(ss_arr, size, 0);
printf("Quick Sort\n");
sort_exe(quick_arr, size, 1);
printf("Bubble Sort\n");
sort_exe(bubble_arr, size, 2);
printf("Heap Sort\n");
sort_exe(heap_arr, size, 3);

/*
printArray(ss_arr, size);
printArray(quick_arr, size);   //These can be used to check the sorting algorithim is sorting correctly
printArray(bubble_arr, size);
printArray(heap_arr, size);
*/

reverse_array(ss_arr, size); //Reverses sorted array by passing to reverse_array function
reverse_array(quick_arr, size);
reverse_array(bubble_arr, size);
reverse_array(heap_arr, size);

/*
printArray(ss_arr, size);
printArray(quick_arr, size);        //Used to test if reverse function runs correctly
printArray(bubble_arr, size);
printArray(heap_arr, size);
*/

printf("Reversed Array sort\n");

printf("Selection Sort\n");
sort_exe(ss_arr, size, 0);
printf("Quick Sort\n");
sort_exe(quick_arr, size, 1);
printf("Bubble Sort\n");
sort_exe(bubble_arr, size, 2);
printf("Heap Sort\n");
sort_exe(heap_arr, size, 3);

/*
printArray(ss_arr, size);
printArray(quick_arr, size);   //These can be used to check the sorting algorithim is sorting correctly on reversed array
printArray(bubble_arr, size);
printArray(heap_arr, size);
*/
}
