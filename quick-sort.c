#include <stdio.h>
#include <stdbool.h>
#include<time.h>


void printline(int count) {
   int i;
   for(i = 0;i <count-1;i++) {
      printf("=");
   }
   printf("=\n");
}

void display(int max,int arr[]) {
   int i;
   printf("[");
   // navigate through all items
   for(i = 0;i<max;i++) {
      printf("%d ",arr[i]);
   }

   printf("]\n");
}

void quickSort(int arr[], int left, int right) {

      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }      }
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);

}
int main() {
    int max =100,i;
    int arr[max];
 for (i = 0; i < max; i++) {
    arr[i]= rand() % 100 + 1;
  }

   printf("Input Array:\n ");
   display(max,arr);
   printline(50);
    double t1=clock();
   quickSort(arr,0,max-1);
    double t2=clock();
//   printf("Output Array:\n ");
//   display(max,arr);
//   printline(50);
 double tot=(t2-t1)/CLOCKS_PER_SEC;
    printf("/n sorting time=%f",tot);
}
