
#define INF -1000

class Solution {
public:

    bool valid(int i, int j, int n, int m){
        return (i >= 0 && i < n) && (j >= 0 && j < m) ;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // 0 - right, 1 - down, 2 - left, 3 - up
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1,0}};
        int move_index = 0;
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = 0;
        while(res.size() != n*m){
            do{
                // set the current element
                if(matrix[i][j] != INF){
                    res.push_back(matrix[i][j]);
                    matrix[i][j] = INF;
                }

                auto [x, y] = moves[move_index];
                if(valid(i+x, j+y, n, m) && matrix[i+x][j+y]!= INF){
                    i += x;
                    j += y;
                }else 
                    break;
                
            }while(true);
            // change the move
            move_index = (move_index + 1)% 4;
        }
        return res;
    }
};