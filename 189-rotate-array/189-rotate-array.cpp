class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        //Step1:- Reverse The whole array
        reverse(nums.begin(),nums.end());
        
        //Step2:- Reverse elements from 0 to k
        reverse(nums.begin(),nums.begin()+k);
        
        //Step3:- Reverse elements from k to n
        reverse(nums.begin()+k,nums.end());
        
    }
};