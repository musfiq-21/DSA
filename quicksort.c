#include <stdio.h>
#include <stdlib.h>
#define N  2e9
int arr[1000000] = {1,2,-3,4,5,6,-7,8,-9, N};

void swap(int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

int partition(int l, int h){

    int i=l, j=h;
    //int randomPivot = l + rand()%(h-l);
    int randomPivot = l;
    int pivot = arr[randomPivot];

    while(i<j){
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
            swap(i, j);
    }

    // for(int j=l; j<h; j++){
    //     if(arr[j]<=pivot){
    //         swap(++i, j);
    //     }
    // }
    
    //swap(i, randomPivot);
    return j;
}

void quickSort(int l, int h){
    if(l<h){
        int pivot = partition(l, h);
        quickSort(l, pivot);
        quickSort(pivot+1, h);
    }
    return;
}

int main(){

    quickSort(0, 8);


    for(int i=0; i<9; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

}