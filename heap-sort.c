#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int heapSize;

void Heapify(int* A, int i)
{
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest;

  if(l <= heapSize && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if(r <= heapSize && A[r] > A[largest])
    largest = r;
  if(largest != i)
    {
      int temp = A[i];
      A[i] = A[largest];
      A[largest] = temp;
      Heapify(A, largest);
    }
}

void BuildHeap(int* A,int n)
{
  heapSize = n - 1;
  int i;
  for(i = (n - 1) / 2; i >= 0; i--)
    Heapify(A, i);
}

void HeapSort(int* A ,int n)
{
  BuildHeap(A,n);
  int i;
  for(i = n - 1; i > 0; i--)
    {
      int temp = A[heapSize];
      A[heapSize] = A[0];
      A[0] = temp;
      heapSize--;
      Heapify(A, 0);
    }
}

int main()
{
    int n =100000,i;
  int tab[n];
  for (i = 0; i < n; i++) {
    tab[i]= rand() % 100 + 1;
  }
  for(i = 0; i < n; i++)
    printf("%d ",tab[i]);
printf("\n");
 double t1=clock();
  HeapSort(tab,n);
 double t2=clock();
//  for(i = 0; i < n; i++)
//    printf("%d ",tab[i]);
 double tot=(t2-t1)/CLOCKS_PER_SEC;
    printf("/n sorting time=%f",tot);
  return 0;
}
