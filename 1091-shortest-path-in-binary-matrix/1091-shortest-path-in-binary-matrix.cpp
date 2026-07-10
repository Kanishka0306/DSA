class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<int>> dist (n , vector<int>(m, 1e9));
        queue<pair<int,pair<int,int>>> q; //( DIST , (ROW, COL)} FORMAT 
        dist[0][0] =1;
        q.push({1, {0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1) return dis;


            for(int drow = -1 ; drow<= 1 ; drow++){
                for(int dcol = -1 ; dcol<= 1 ; dcol++){
                    int nrow = row+drow;
                    int ncol = col+dcol;

                    if(nrow>=0 && nrow<n && ncol>= 0 && ncol<m && grid[nrow][ncol]==0 && dis +1 <dist[nrow][ncol]){
                        dist[nrow][ncol] = dis+1;
                        q.push({dis+1, {nrow , ncol}});
                    }
                }
            }
        }
        return -1;

    }
};