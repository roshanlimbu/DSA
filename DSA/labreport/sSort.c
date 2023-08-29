#include <stdio.h>

void insertionSort(int arr[], int n){
  int i,j, k;
  for(i=1; i<n; i++){
    k=arr[i];
    for(j=1; j>=0 && arr[j]>k; j--){
      arr[j+1]=arr[j];
    }
    arr[j+1]=k;
  }
}
int main(){
  int arr[]={2, 5, 1, 9, 4, 4, 6 , 8};
  int n = sizeof(arr)/ sizeof(arr[0]);

  printf("%d", n);
  printf("Before sorting: ");
  for(int i=0; i<=n; i++){
    printf("%d ",arr[i] );
  }

  insertionSort(arr, n);
  printf("\nAfter Sorting: ");
  for (int i=0 ; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
