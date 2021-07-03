//Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//Driver Code Ends

//Solution Class Starts
class solution{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subArraySum(int arr[], int n, int s){
        //Your code here
        vector<int> pos={1};
        int sum=0;
        if (s>0){
            for (int i=0;i<n;++i){
                sum=sum+arr[i];
                while(sum>s){
                    sum=sum-arr[pos[0]-1];
                    pos[0]=pos[0]+1;
                }
                if(sum==s){
                    pos.push_back(i+1);
                    break;
                }
            }     
        }
        if (pos.size()==1)
            pos.front()=-1;
        return pos;
    }
};
//Solution Class Ends

//Driver Code Starts
int main(){
    int t;
    cout<<"Enter the number of runs: ";
    cin>>t;
    while(t--){
        int n;
        long long s;
        cout<<"Enter the size of array and desired sum: ";
        cin>>n>>s;
        int arr[n];
        cout<<"Enter the elements of array: ";
        for(int i=0;i<n;++i)
            cin>>arr[i];
        solution ob;
        vector<int>res;
        res = ob.subArraySum(arr, n, s);
        cout<<"The required subarray is from: ";
        for(int i = 0;i<res.size();++i)
            cout<<res[i]<<"\t";        
    }
	return 0;
}
//Driver Code Ends
