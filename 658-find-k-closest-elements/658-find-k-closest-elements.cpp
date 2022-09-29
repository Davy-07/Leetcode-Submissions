class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0;//left pointer
        int r=arr.size()-1;//right pointer
        vector<int> ans;//answer vector
        while(l<=r){  //loop until left != right
            if((r-l)+1 > k){ // if elements are greater than k than decide which one to remove
                if(abs(arr[l] - x) > abs(arr[r] - x)){ //if arr[l] is far then x increment l
                    l++;
                }else{//decrement right
                    r--;
                }
            }else{//we have to include to add atleast k elements
                ans.push_back(arr[l]);
                l++;
            }
        }
        return ans;
    }
};