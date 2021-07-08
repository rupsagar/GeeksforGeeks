#include<iostream>
using namespace std;

int numOfHouses(int, int, int*);
void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main(){
    int t; //number of runs
    cin>>t;
    int count[t];
    for (int i = 1; i<=t; ++i){
        int n,b; //number of houses and amount of money
        cin>>n>>b;
        int a[n]; // prices of the houses
        for (int j=0;j<n;++j)
            cin>>a[j];

        count[i] = numOfHouses(n,b,a);
        cout<<"Case #"<<i<<": "<<count[i]<<endl;
    }
}

int numOfHouses(int n, int b, int a[]){
    mergeSort(a,0,n-1);
    int count = 0, sum = 0;
    while(count<n){
        sum = sum+a[count];
        if (sum>b)
            break;
        ++count;
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