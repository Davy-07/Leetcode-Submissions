class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int count = 0;
        int ans = INT_MAX;
        int i=0;
        int j=0;
        while(j<blocks.size())
        {
            if(blocks[j]=='W')
            {
                count++;
            }
            
            if(j-i+1==k)
            {
                ans = min(ans,count);
                if(blocks[i]=='W')
                {
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};