//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        if(n==1)
        {
            return arr[0];
        }
        int cur_sum = 0;
        int max_sum = INT_MIN;
        for(int i=0;i<n;i++)
        {
            max_sum = max(max_sum,arr[i]);
            cur_sum+=arr[i];
            max_sum = max(max_sum,cur_sum);
            if(cur_sum<0)
            {
                cur_sum = 0;
            }
        }
        return max_sum;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends