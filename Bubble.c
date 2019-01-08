#include<stdio.h>
void bubbleSort(int arr[],int len){
    int isSwapped=0;
    int i,j;
for(  i=0;i<len;i++ ){
    isSwapped=0;
    for( j=0;j<len;j++){
        if(arr[j]>arr[j+1]){
            isSwapped=1;
        int temp= arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
     }
 }
 if(isSwapped==0){
     break;
 }
}
}
int main(){
    int arr[]={3,2,7,8,5};
    int i;
for(i=0;i<5;i++){
    printf("%d\t",arr[i]);
}
bubbleSort(arr,5);
  printf("\n Sorted array is :\n");
for( i=0;i<5;i++){
    printf("%d\t",arr[i]);
}
return 0;
}