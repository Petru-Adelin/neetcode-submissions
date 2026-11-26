
class Solution {
public:

    bool valid(int x, int y, int n, int m){
        return (x >= 0 && x < n) && (y >= 0 && y < m);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        vector<pair<int, int>> moves = {{-1, 0 }, {0, 1}, {1, 0}, {0, -1}};
        int n = grid.size();
        int m = grid[0].size();
        
        // BFS
        bool visited[101][101];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                visited[i][j] = false;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 0){
                    que.push({i, j});
                    visited[i][j] = true;
                }

            }
        }
        while(!que.empty()){
            auto [i, j] = que.front();
            que.pop();
            for(auto& move: moves){
                int x = i + move.first;
                int y = j + move.second;
                if(valid(x, y, n, m) && grid[x][y] != -1 && !visited[x][y]){
                    grid[x][y] = min(grid[i][j] + 1, grid[x][y]);
                    visited[x][y] = true;
                    que.push({x, y});
                }
            }
        }
    }
};