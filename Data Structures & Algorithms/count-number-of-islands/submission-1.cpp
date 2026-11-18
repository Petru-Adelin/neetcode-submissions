class Solution {
public:

    bool valid_index(int x, int y, int rows, int cols){
        return (x >= 0 && x < rows) && (y >= 0 && y < cols);
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int islands = 0;
        size_t rows = grid.size();
        size_t cols = grid[0].size();
       
        queue<pair<int, int>> que;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == '1'){
                    islands++;
                    // run a bfs 
                    grid[i][j] = '0';
                    que.push({i, j});
                    while(!que.empty()){
                        auto point = que.front();
                        que.pop();
                        for(int i = 0; i < 4; ++i){
                            // make a move 
                            int row = moves[i].first;
                            int col = moves[i].second;
                            int x = point.first + row;
                            int y = point.second + col;
                            if(valid_index(x, y, rows, cols))
                                if(grid[x][y] == '1'){
                                    que.push({x, y});
                                    grid[x][y] = '0';
                                }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
