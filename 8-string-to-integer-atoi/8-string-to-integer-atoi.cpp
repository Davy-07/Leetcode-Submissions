class Solution {
public:
    int myAtoi(string s) {
        int i=0, j=0, n=s.size();
        bool neg=false, sign=false;
        while(j<n and !isdigit(s[j]) ){
            if(sign) return 0;
            if(s[j]!=' '){
                if(s[j]=='-' or s[j]=='+') sign=true;
                else return 0;
            }
            ++j, i=j;
        }
        if(j and s[j-1]=='-') neg=true;
        while(j<n and isdigit(s[j])) ++j;
        long ans=0;
        while(i<j){
            int a = s[i] - 48;
            ans = (ans*10) + a;
            if(neg and (ans*-1)<=INT_MIN) return INT_MIN;
            else if(ans>INT_MAX) return INT_MAX;
            ++i;
        }
        
        if(neg) ans*=-1;
        
        return ans;
    }
};