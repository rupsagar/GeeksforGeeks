//Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//Driver Code Ends

//Solution Class Starts
class Solution{
public:	
	int countTriplet(int arr[], int n){
	    // Your code goes here
	    int count=0,sum,diff;
        for(int i=0;i<n-2;++i){
            for(int j=i+1;j<n-1;++j){
                sum=arr[i]+arr[j];
                diff=abs(arr[i]-arr[j]);
                for(int k=j+1;k<n;++k){
                    if (sum==arr[k]||diff==arr[k])
                        ++count;
                }
            }
        }
        return count;
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