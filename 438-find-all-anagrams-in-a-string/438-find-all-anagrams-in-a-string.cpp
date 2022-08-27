class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char,int> s1;
        unordered_map<char,int> p1;
        
        for(int i=0;i<p.size();i++)
        {
            p1[p[i]]++;
        }
        
        vector<int> ans;
        int i=0;
        int j=0;
        int k = p.size();
        while(j<s.size())
        {
            s1[s[j]]++;
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(s1==p1)
                {
                    ans.push_back(i);
                }
                s1[s[i]]--;
                if(s1[s[i]]==0)
                {
                    s1.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};