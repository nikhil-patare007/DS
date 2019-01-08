#include<stdio.h>
void selectionSort(int arr[],int n){
    int min;
    for(int i=0;i<n;i++){
        min=arr[i];
        for(int j=i; j<n; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
int main(){
    int arr[]={1,3,5,7,6};
    selectionSort(arr,6);
    return 0;
}