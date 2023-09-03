#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int* tmp=new int[high-low+1];
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]){
            tmp[k++]=arr[i++];
        }
        else {
            tmp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        tmp[k++]=arr[i++];
    }
    while(j<=high){
        tmp[k++]=arr[j++];
    }
    for(int i=0;i<k;i++){
        arr[low+i]=tmp[i];
    }
    delete [] tmp;
}
void mergesort(int arr[],int low,int high){
    // int mid=(low+high)/2;
    if(low<high){
        int mid=(high-low)/2+low;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr,low,mid,high);
    }
}
int main()
{
    int a[]={1,3,5,2,4,8,6,7,0,9};
    mergesort(a, 0, 9);
    for(auto tmp:a){
        std::cout<<tmp<<", ";
    }
    std::cout<<endl;
    return 0;
}