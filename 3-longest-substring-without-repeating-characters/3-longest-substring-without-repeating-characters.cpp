class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()==0)
        {
            return 0;
        }
        int j=0;
        int i = 0;
        unordered_map<char,int> m;
        int max_ans = 1;
        while(j<s.size())
        {
            if(m.find(s[j])==m.end())
            {
                m[s[j]]++;
                j++;;
            }
            else if(m.find(s[j])!=m.end())
            {
                if(m.size()>max_ans)
                {
                    max_ans = m.size();
                }
                m.clear();
                i++;
                j=i;
            }
            
        }
        if(m.size()>max_ans)
        {
            max_ans = m.size();
        }
        return max_ans;
    }
};