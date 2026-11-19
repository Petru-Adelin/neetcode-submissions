class Solution {
public:

    bool valid_index(int x, int y, int rows, int cols){
        return (x >= 0 && x < rows) && (y >= 0 && y < cols);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int max_size = 0;
        size_t rows = grid.size();
        size_t cols = grid[0].size();
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == 1){
                    int size = 1;
                    que.push({i, j});
                    grid[i][j] = 0;
                    while(!que.empty()){
                        auto point = que.front();
                        que.pop();
                        for(int k = 0; k < 4; ++k){
                            // choose a move
                            auto move = moves[k];
                            int x = point.first + move.first;
                            int y = point.second + move.second;
                            if(valid_index(x, y, rows, cols))
                                if(grid[x][y] == 1){
                                    que.push({x,y});
                                    grid[x][y] = 0;
                                    size++;
                                }
                        }
                    }
                    max_size = max(max_size, size);
                }
            }
        }
        return max_size;
    }
};