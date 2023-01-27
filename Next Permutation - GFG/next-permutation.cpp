//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int index1,index2,i,j;
            for(i=arr.size()-2;i>=0;i--)
            {
                if(arr[i+1]>arr[i])
                {
                    index1 = i;
                    break;
                }
            }
            if(i<0)
            {
                reverse(arr.begin(),arr.end());
            }
            else{
                    for(j=arr.size()-1;j>i;j--)
                    {
                        if(arr[j]>arr[index1])
                        {
                            break;
                        }
                    }

                    swap(arr[index1],arr[j]);
                    reverse(arr.begin()+index1+1,arr.end());
            }
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends