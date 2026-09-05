class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&grid, vector<vector<bool>> & visited){
        if(i<0|| i>=grid.size()|| j<0|| grid[0].size()<=j) return;
        if(grid[i][j]=='0') return;
        if(visited[i][j]) return;
        visited[i][j] =true;

        dfs(i-1, j, grid, visited);
        dfs(i+1, j, grid, visited);
        dfs(i, j-1, grid, visited);
        dfs(i, j+1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        vector<vector<bool>>visited(
            grid.size(),
            vector<bool>(grid[0].size(), false)
        );
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
               if(!visited[i][j] && grid[i][j]=='1'){
                    count ++;
                    dfs(i, j, grid, visited);
                } 
            }
        }
        return count;
    }
};
