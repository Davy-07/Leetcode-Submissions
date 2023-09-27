class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<1){
          return 0;
        }
        set <int> s(nums.begin(),nums.end());
        int ans = 1;
        int maxi =1;
        auto it = s.begin();
        int prev = *(it);
        it++;
        int cur = *(it);
        while(it!=s.end()){
          if(cur-prev!=1){
            maxi =1;
          }
          else{
            maxi++;
          }
          ans = max(ans,maxi);
          prev = cur;
          it++;
          cur = *(it);
        }
      return ans;
    }
};