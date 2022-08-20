class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        string t = s;
        sort(s.begin(),s.end(),greater<char>());
        if(t==s)
        {
            return 0;
        }
        int count = 0;
        while(1)
        {
            for(int i=0;i<t.size()-1;i++)
            {
                if(t[i]=='0' && t[i+1]=='1')
                {
                    t[i]='1';
                    t[i+1] = '0';
                    i++;
                }
            }
            count++;
            if(t==s)
            {
                break;
            }
            
        }
        return count;
    }
};