class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        
       for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(
                  !st.size() ||
                  s[i] == ')' && st.top() != '(' ||
                  s[i] == ']' && st.top() != '[' ||
                  s[i] == '}' && st.top() != '{')
                    return false;
                st.pop();
            }
        }
        
        return !st.size();
    }
};