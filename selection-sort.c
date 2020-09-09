#include <stdio.h>
#include<time.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
     int n =100,i;

    int arr[n];
    printf("input:\n");
        for (i = 0; i < n; i++) {
    arr[i]= rand() % 100 + 1;
  }
   // printArray(arr,n);
     double t1=clock();
    selectionSort(arr, n);
     double t2=clock();
//    printf("Sorted array: \n");
//    printArray(arr, n);
 double tot=(t2-t1)/CLOCKS_PER_SEC;
    printf("/n sorting time=%f",tot);
    return 0;
}
