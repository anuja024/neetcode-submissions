class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh =0;
        int minutes= -1;
        queue<pair<int,int>> q;
        
        for(int i=0;i< grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]== 1) fresh++;

                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(fresh==0) return 0;

        while(!q.empty()){
            int size= q.size();
            minutes++;

            for(int i=0; i< size; i++){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            if(row>0 && grid[row-1][col]==1){
                int newrow = row-1, newcol = col;
                grid[newrow][newcol] =2;
                fresh --;
                q.push({newrow, newcol});
            }

            if(row<grid.size()-1 && grid[row+1][col]==1){
                int newrow = row+1, newcol = col;
                grid[newrow][newcol]=2;
                fresh--;
                q.push({newrow, newcol});
            }

            if(col>0 && grid[row][col-1]==1){
                int newrow = row, newcol = col-1;
                grid[newrow][newcol]=2;
                fresh--;
                q.push({newrow, newcol});
            }

            if(col< grid[0].size()-1 && grid[row][col+1]==1){
                int newrow = row, newcol = col+1;
                grid[newrow][newcol]=2;
                fresh--;
                q.push({newrow, newcol});
            }
            }
        }
        if(fresh == 0) return minutes;   
        else return -1;
    }
};
