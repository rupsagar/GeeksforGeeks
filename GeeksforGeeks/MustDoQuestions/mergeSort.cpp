#include<iostream>
using namespace std;

class sort{
    public:
    void mergeSort(int arr[],int left,int right){
        if (left==right)
            return;
        int mid = left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    private:
    void merge(int arr[], int left, int mid, int right){
        int leftArrSize = mid-left+1, rightArrSize = right-mid;
        int leftArr[leftArrSize], rightArr[rightArrSize];
        for (int i = 0; i<leftArrSize; ++i)
            leftArr[i] = arr[left+i];
        for (int i = 0; i<rightArrSize; ++i)
            rightArr[i] = arr[mid+1+i];
        int leftIndex = 0, rightIndex = 0, arrIndex = left;
        while (leftIndex<leftArrSize && rightIndex<rightArrSize){
            if (leftArr[leftIndex]<=rightArr[rightIndex]){
                arr[arrIndex] = leftArr[leftIndex];
                ++leftIndex;
            }else{
                arr[arrIndex] = rightArr[rightIndex];
                ++rightIndex;
            }
            ++arrIndex;
        }
        while (leftIndex<leftArrSize){
            arr[arrIndex] = leftArr[leftIndex];
            ++leftIndex;
            ++arrIndex;
        }
        while (rightIndex<rightArrSize){
            arr[arrIndex] = rightArr[rightIndex];
            ++rightIndex;
            ++arrIndex;
        }
    }
};

int main(){
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i<n; ++i)
        cin>>arr[i];
    sort obj;
    obj.mergeSort(arr,0,n-1);
    
    cout<<"The sorted array is: ";
    for (int i = 0; i<n; ++i)
        cout<<arr[i]<<"\t";
    return 0;
}
