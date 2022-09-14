class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()==0)
        {
            return 0;
        }
        int max_ans = 0;
        int i=0;
        int j=0;
        set<char> st;
        for(int j=0;j<s.size();j++)
        {
            if(!st.count(s[j]))
            {
                st.insert(s[j]);
                max_ans = max(max_ans,j-i+1);
            }
            else{
                while(st.count(s[j]))
                {
                    st.erase(s[i]);
                    i++;
                }
                st.insert(s[j]);
            }
        }
        
        return max_ans;
    }
};