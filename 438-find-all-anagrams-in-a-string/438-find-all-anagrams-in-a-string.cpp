class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char,int> p1;
        for(int i=0;i<p.size();i++)
        {
            p1[p[i]]++;
        }
        
        int count = p1.size();
        int i=0;
        int j=0;
        int k = p.size();
        vector<int> ans;
        while(j<s.size())
        {
            if(p1.find(s[j])!=p1.end())
            {
                p1[s[j]]--;
                if(p1[s[j]]==0)
                {
                    count--;
                }
            }
            
            if(j-i+1<k)
            {
                j++;
            }
            
            else if(j-i+1==k)
            {
                if(count==0)
                {
                    ans.push_back(i);
                }
                if(p1.find(s[i])!=p1.end())
                {
                    p1[s[i]]++;
                    if(p1[s[i]]==1)
                    {
                        count++;
                    }
                }
                i++;
                j++;
            }
            
        }
        return ans;
    }
};