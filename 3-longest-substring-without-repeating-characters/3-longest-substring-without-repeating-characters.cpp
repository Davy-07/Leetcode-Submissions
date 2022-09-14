class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()==0)
        {
            return 0;
        }
        int j=0;
        int i = 0;
        set<char> st;
        int max_ans = 1;
        while(j<s.size())
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j]);
                j++;;
            }
            else if(st.find(s[j])!=st.end())
            {
                if(st.size()>max_ans)
                {
                    max_ans = st.size();
                }
                st.clear();
                i++;
                j=i;
            }
            
        }
        if(st.size()>max_ans)
        {
            max_ans = st.size();
        }
        return max_ans;
    }
};