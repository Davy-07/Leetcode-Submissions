class Solution {
public:
    char repeatedCharacter(string s) {
        
        char ans;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end())
            {
                m[s[i]] = 1;
            }
            else if(m.find(s[i])!=m.end())
            {
                ans = s[i];
                break;
            }
        }
        return ans;
        
    }
};