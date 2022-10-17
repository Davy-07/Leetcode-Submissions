class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> m;
        if(sentence.size()<26)
        {
            return false;
        }
        int count = 0;
        for(int i=0;i<sentence.size();i++)
        {
            if(m.find(sentence[i])==m.end())
            {
                count++;
                m[sentence[i]]++;
            }
        }
        
        if(count==26)
        {
            return true;
        }
        else{
            return false;
        }
    }
};