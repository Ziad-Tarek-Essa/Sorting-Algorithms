#include <stdio.h>
#include<time.h>


int max=100;

void merging(int low, int mid, int high,int arr[]) {
   int l1, l2, i;
int b[max];
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(arr[l1] <= arr[l2])
         b[i] = arr[l1++];
      else
         b[i] = arr[l2++];
   }

   while(l1 <= mid)
      b[i++] = arr[l1++];

   while(l2 <= high)
      b[i++] = arr[l2++];

   for(i = low; i <= high; i++)
      arr[i] = b[i];
}

void sort(int low, int high,int arr[]) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid,arr);
      sort(mid+1, high,arr);
      merging(low, mid, high,arr);
   } else {
      return;
   }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}

int main() {
   int i;
    int arr[max];
 for (i = 0; i < max; i++) {
    arr[i]= rand() % 100 + 1;
  }
   printf("List before sorting\n");
   printArray(arr,max);
 double t1=clock();
   sort(0, max,arr);
 double t2=clock();
//   printf("\nList after sorting\n");
//   printArray(arr, max);
 double tot=(t2-t1)/CLOCKS_PER_SEC;
    printf("/n sorting time=%f",tot);

}
