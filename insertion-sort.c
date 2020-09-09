#include <stdio.h>
#include <math.h>
#include<time.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}



/* Driver program to test insertion sort */
int main()
{
    int n =100,i;
    int arr[n];
 for (i = 0; i < n; i++) {
    arr[i]= rand() % 100 + 1;
  }
   printArray(arr, n);
    double t1=clock();
    insertionSort(arr, n);
     double t2=clock();
   // printArray(arr, n);
 double tot=(t2-t1)/CLOCKS_PER_SEC;
    printf("/n sorting time=%f",tot);
    return 0;
}
