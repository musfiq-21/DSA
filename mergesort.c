#include <stdio.h>
int arr[1000000] = {9, 3, 7, 5, -5, 4, 8, 2, 20};

void merge(int l, int mid, int h){

    int temp[h-l+1];
    int a = mid-l+1, b= h-mid, i=0, j=0, k=0;
    int min1[a+1], min2[b+1];

    for(;i<a; i++){
        min1[i] = arr[l+i];
    }
    min1[a] = 2e9;
    i=0;

    for(;j<b; j++){
        min2[j] = arr[mid+1+j];
    }
    min2[b] = 2e9;
    j=0;

    for( ; i<a || j<b; k++){
        if(min1[i]<=min2[j])
            temp[k]=min1[i++];
        
        else
            temp[k]=min2[j++];
    }

    for(;i<a; i++){
        temp[k++] = min1[i];
    }

    for(; j<b; j++){
        temp[k++] = min2[j];

    }
    k=0;

    for(int i=l; i<=h; i++){
        arr[i] = temp[k++];
    }
    
}

void mergeSort( int l, int h){
    int mid = (l+h)/2;

    if(l<h){
        mergeSort(l, mid);
        mergeSort(mid+1, h);
        merge(l, mid, h);
    }
    return;
}

int main(){

    mergeSort(0, 9);


    for(int i=0; i<=9; i++)
        printf("%d ", arr[i]);

    printf("\n");
}