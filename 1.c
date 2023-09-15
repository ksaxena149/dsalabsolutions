// Write a menu driven program to implement the following operations:
// 1) Create an array of size 10
// 2) Print all elements of the array
// 3) Adding one element in array in any position
// 4) Deleting one element from array from any position

#include <stdio.h>

void create(int a[], int size){
    for (int i = 0; i < size; i++)
    {
        a[i] = i+1;
    }
}

void display(int a[], int size){
    for(int i = 0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert(int a[], int* size, int index, int value){
    if (*size<index)
    {
        return;
    }
    for(int i = *size; i>index; i--){
        a[i] = a[i-1];
    }
    a[index] = value;
    (*size)++;
}

void delete(int a[], int* size, int index){
    if(*size<=index){
        return;
    }
    for(int i = index; i<*size; i++){
        a[i] = a[i+1];
    }
    (*size)--;
}

void main(){
    int size=10;
    int arr[50];
    int ind; 
    int val;
    create(arr, size);
    display(arr, size);
    while (1)
    {
        int choice;
        printf("Enter:\n1: To insert\n2: To delete\n3: To print all values\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            
            printf("Enter index you want to insert at: ");
            scanf("%d", &ind);
            printf("Enter value you want to insert: ");
            scanf("%d", &val);
            insert(arr, &size, ind, val);
            break;
        
        case 2:
            
            printf("Enter index you want to delete at: ");
            scanf("%d", &ind);
            delete(arr, &size, ind);
            break;

        case 3:
            display(arr, size);
        
        default:
            break;
        }
    }
}