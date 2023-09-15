// Write a program for:
// 1. Linear Search
// 2. Binary Search
#include <stdio.h>

int createArray(int a[], int size){
  for (int i = 0; i < size; i++)
  {
    printf("Enter element %d: ", i+1);
    scanf("%d", &a[i]);
  }
  printf("\n");
}

int linearSearch(int a[], int size, int value){
  for (int i = 0; i < size; i++)
  {
    if(a[i]==value){
      return i;
    }
  }
  return -1;
}

int binarySearch(int a[], int size, int value){
  int left = 0;
  int right = size -1;
  while(left <= right){
    int mid = left + (right-left)/2;
    if(a[mid]==value){
      return mid;
    }
    else if (a[mid]<value){
      left = mid+1;
    }
    else {
      right = mid - 1;
    }
  }
  return -1;
}

int main(){
  int size;
  printf("Enter the size of the array(max size 50): ");
  scanf("%d", &size);
  printf("\n");
  int arr[50];
  createArray(arr, size);
  printf("Enter the element you want to search: ");
  int target;
  scanf("%d", &target);
  printf("\n");
  int foundIndex = linearSearch(arr, size, target);
  int foundIndexB = binarySearch(arr, size, target);
  if (foundIndex>-1){
    printf("Element found at index: %d using linear search", foundIndex);
  }
  if (foundIndexB>-1){
    printf("Element found at index: %d using binary search", foundIndexB);
  }
  else
  {
    printf("Element not found in the array :(");
  }
  return 0;
}