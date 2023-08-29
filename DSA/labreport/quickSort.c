#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int left, int right){
  int temp;
  int pivot=left;
  int down = left, up = right;
repeat:
  while(arr[down]<=arr[pivot] && down <= right){
    down++;
    while(arr[up]>=arr[pivot]){
      up--;
      if(down<=up){
        temp=arr[down];
        arr[down]=arr[up];
        arr[up]=temp;
        goto repeat;
      } else {
        temp=arr[pivot];
        arr[pivot]=arr[up];
        arr[up]=temp;
        quickSort(arr,left, up-1 );
        quickSort(arr, up+1, right);
      }
    }
  }
}
int main(){
  int arr[]={2, 5, 1, 9, 4, 4, 6 , 8};
  int n = sizeof(arr)/ sizeof(arr[0]);

  printf("Before sorting: ");
  for(int i=0; i<n; i++){
    printf("%d ",arr[i] );
  }

  quickSort(arr, 0, 9);
  printf("\nAfter Sorting: ");
  for (int i=0 ; i <n-1; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}

