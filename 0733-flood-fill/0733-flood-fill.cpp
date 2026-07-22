class Solution {
public:

    void dfs(int row, int col,
             vector<vector<int>>& ans,
             vector<vector<int>>& image,
             int newColor,
             int oldColor,
             int delRow[],
             int delCol[]) {

        // Color the current cell
        ans[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        // Visit all 4 directions
        for(int i = 0; i < 4; i++) {

            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            // Check if neighbour is valid
            if(newRow >= 0 && newRow < n &&
               newCol >= 0 && newCol < m &&
               image[newRow][newCol] == oldColor &&
               ans[newRow][newCol] != newColor) {

                dfs(newRow, newCol,
                    ans,
                    image,
                    newColor,
                    oldColor,
                    delRow,
                    delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        // Original color of starting pixel
        int oldColor = image[sr][sc];

        // If already same color, return
        if(oldColor == color)
            return image;

        // Copy image into answer
        vector<vector<int>> ans = image;

        // Direction arrays
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Start DFS
        dfs(sr, sc,
            ans,
            image,
            color,
            oldColor,
            delRow,
            delCol);

        return ans;
    }
};