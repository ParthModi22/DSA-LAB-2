#include<iostream>
using namespace std;

void insertionsort(int *arr,int n){
    int comp = 0,swap=0;
    for(int i =1;i<n;i++){
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key){
            comp++;
            arr[j+1]=arr[j];
            swap++;
            j--;
        }
        comp++;
        arr[j+1]=key;
    }
    cout<<"sorted array: ";
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
    cout<<"number of comparisons are: "<<comp<<endl;
    cout<<"number of swaps are: "<<swap<<endl;
}

int main(){
    int arr[]={44,34,23,12,2,3,1};
    int n  = sizeof(arr)/sizeof(arr[0]);
    cout<<"original array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertionsort(arr,n);

    return 0;
}