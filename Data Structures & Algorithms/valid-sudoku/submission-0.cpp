class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, column[9] = {0}, square[9] = {0};
		for(int i = 0 ; i < 9; ++i){
			for(int j = 0; j < 9; ++j){

				if(board[i][j] == '.')
					continue;
				 
				// index for the square 
				int s_idx = (i/3)*3 + j/3;
				int num = board[i][j] - '0';
				// checking 
				int bin_val = 1 << (num -1);
				if((row[i] & bin_val) != 0)
					return false;
				else 
					row[i] |= bin_val;
				
				if((column[j] & bin_val) != 0)
					return false;
				else 
					column[j] |= bin_val;
				
				if((square[s_idx] & bin_val) != 0)
					return false;
				else 
					square[s_idx] |= bin_val;
			}
		}
		return true;
    }
};