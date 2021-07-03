//Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//Driver Code Ends

//Solution Class Starts
class Solution{
    public:
    int countTriplet(int arr[], int n){
        //Your code goes here
        mergeSort(arr,0,n-1);
        int count=0, sum, j, k;
        for(int i=n-1; i>=2; --i){
            j=0, k=i-1;
            while (k>j){
                sum=arr[j]+arr[k];
                if (sum==arr[i]){
                    ++count;
                    ++j;
                    --k;
                }
                else if (sum<arr[i])
                    ++j;
                else
                    --k;                
            }
        }
        return count;
    }

    void mergeSort(int arr[],int left,int right){
        if (left==right)
            return;
        int mid = left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }

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
//Solution Class Ends

//Driver Code Starts
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i = 0; i<n; ++i)
        cin>>arr[i];
    Solution ob;
    cout<<"The required triplet count is: "<<ob.countTriplet(arr,n);       
	return 0;
}
//Driver Code Ends