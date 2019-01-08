#include<stdio.h>
int binarySearchR(int arr[], int key, int s, int e){
 int mid=(s+e)/2;
if(s<e){
   
    if(arr[mid]>key){
        return binarySearchR(arr,key,s,mid);
    }
    if(arr[mid]<key){
        return binarySearchR(arr,key,mid+1,e);
    }
    return mid;
}
return -1;
}

int main(){
int res;
int arr[]={10,11,12,13,14};
   res=binarySearchR(arr,14,0,5);
printf("%d Element found",res);
   return 0;
}