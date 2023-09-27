class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> s(nums.begin(),nums.end());
        int ans = 0;

        while(s.size()>0){
            int maxi = 1;
            int num = *(s.begin());
            s.erase(num);
            int temp = num-1;
            while(s.count(temp)){
                maxi++;
                s.erase(temp);
                temp--;
            }
            temp = num+1;
            while(s.count(temp)){
                maxi++;
                s.erase(temp);
                temp++;
            }
            ans= max(maxi,ans);
        }
        return ans;
    }
};