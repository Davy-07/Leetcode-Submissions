class Solution {
public:
    
    int m,n;
    bool isValid(int i,int j)
    {
           if(i<0 || j<0 || i>=m || j>=n)
           {
               return false;
           }
           else{
               return true;
           }
    }
    
    void dfs(vector<vector<char>>& grid, int r,int c)
    {
        grid[r][c] = '2';
        if(isValid(r+1,c) && grid[r+1][c]=='1')
        {
            dfs(grid,r+1,c);
        }
        if(isValid(r-1,c)&& grid[r-1][c]=='1')
        {
            dfs(grid,r-1,c);
        }
        if(isValid(r,c+1) && grid[r][c+1]=='1')
        {
            dfs(grid,r,c+1);
        }
        if(isValid(r,c-1) && grid[r][c-1]=='1')
        {
            dfs(grid,r,c-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        m= grid.size();
        n=grid[0].size();
        int ans = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        
        return ans;
    }
};