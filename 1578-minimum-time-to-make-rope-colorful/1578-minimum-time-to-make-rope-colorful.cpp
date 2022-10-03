class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time =0 ; int i=0,j=0;
        int n = colors.size();
        while(i<n and j<n){
            int mxt=0,currtotal=0;
            while(j<n and colors[i]==colors[j]){
                mxt = max(mxt,neededTime[j]);
                currtotal += neededTime[j];
                j++;
            }
            i=j;
            time += currtotal - mxt;
        }
        return time;
    }
};