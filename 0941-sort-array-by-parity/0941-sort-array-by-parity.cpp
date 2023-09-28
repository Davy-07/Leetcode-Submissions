class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
            queue<int> even;
            queue<int> odd;

            for(int i=0;i<nums.size();i++){
                if(nums[i]%2==0){
                    even.push(nums[i]);
                }
                else{
                    odd.push(nums[i]);
                }
            }
            int i=0;
            while(!even.empty()){
                nums[i] = even.front();
                even.pop();
                i++;
            }

            while(!odd.empty()){
                nums[i] = odd.front();
                odd.pop();
                i++; 
            }
        return nums;

    }
};