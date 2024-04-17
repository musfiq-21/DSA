#include <iostream>
using namespace std;

int BS(int* arr, int elemnt, int lo, int hi){

    int mid = (lo+hi)/2;
    //cout<<mid<<endl;
    if(arr[mid] == elemnt){
        return mid;
    }
    if(lo==hi){
        return -1;
    }
    else 
    {
        if(arr[mid]<elemnt){
            return BS(arr, elemnt, mid+1, hi);
        }
        else{
            return BS(arr, elemnt, lo, mid);
        }

    }
 
}

int main(){
    int arr[7] = {2, 4, 7, 9, 11, 13, 17};

    cout<<BS(arr, 17, 0, 6)<<endl;

//    cout<<"Assalamu Alaikum Vai, I'm from BSSE 15th batch\n";
}