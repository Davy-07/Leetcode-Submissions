class Solution {
public:
    
    bool convert(int n,int base)
    {
        vector<int> ans;
        while(n>0)
        {
            int rem = n%base;
            ans.push_back(rem);
            n = n/base;
        }
        
        
        
        bool res = true;
        for(int i=0;i<ans.size()/2;i++)
        {
            if(ans[i]!=ans[ans.size()-i-1])
            {
                return false;
            }
        }
        return res;
    }
    
    
    
    bool isStrictlyPalindromic(int n) {
        
        bool ans;
        for(int i=2;i<=n-2;i++)
        {
            ans = convert(n,i);
            if(ans==false)
            {
                break;
            }
        }
        return ans;
    }
};