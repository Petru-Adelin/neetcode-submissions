class Solution {

private: 
    // first is for the row (dim == 1) and second is for the column (dim == 0)
    // UP, RIGHT, DOWN, LEFT
    vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool valid_position(int row, int col, int rows, int cols){
        if(row > rows-1 || row < 0)
            return false;
        if(col > cols-1 || col < 0)
            return false;
        return true;
    }

public:

    bool existRec(vector<vector<char>>& board,int row,int col, int comp_idx,  string& word){
        if(comp_idx == word.size())
            return true;
        char c = board[row][col];
        bool result = false;
        board[row][col] = '#';
        for(auto& move: moves){
            auto [r, c] = move;
            if(valid_position(row+r, col+c, board.size(), board[0].size()) && board[row+r][col+c] == word[comp_idx]){
                result = result || existRec(board, row+r, col+c, comp_idx+1, word);
            }
        }
        board[row][col] = c;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // the stack will hold the current position row, col and the index of the char I have to compare for the next char (allowing pruning)
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[0]){
                    bool result = existRec(board, i, j, 1, word);
                    if(result == true)
                        return true;
                }
            }
        }
        return false;
    }
};