#include <stdio.h>
#include<time.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
        int n =10000,i;

    int arr[n];
    printf("input:\n");
        for (i = 0; i < n; i++) {
    arr[i]= rand() % 100 + 1;
  }
    printArray(arr,n);
    double t1=clock();
    bubbleSort(arr, n);
    double t2 = clock();
    //printf("\nSorted array: \n");
   // printArray(arr, n);
   double tot=(t2-t1)/CLOCKS_PER_SEC;
    printf("\n sorting time=%f",tot);
    return 0;
}
