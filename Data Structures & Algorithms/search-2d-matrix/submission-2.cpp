using mat = vector<vector<int>>;

class Solution {
public:

    int col_bin_search(mat& m, int start, int end, int target){
        if(start > end)
            return start;
        int mij = (start + end) / 2;
        if(m[mij][0] == target)
            return mij;
        if(m[mij][0] < target)
            return col_bin_search(m, mij+1, end, target); 
        return col_bin_search(m, start, mij-1, target);
    }

    int row_bin_search(mat& m, int row, int start, int end, int target){
        if(start > end)
            return -1;
        int mij = (start + end) / 2;
        if(m[row][mij] == target)
            return mij;
        if(m[row][mij] < target)
            return row_bin_search(m, row, mij+1, end, target);
        return row_bin_search(m, row, start, mij-1, target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        
        // Find the boundary row using binary search on the first column
        int up_until_row = col_bin_search(matrix, 0, rows - 1, target);

        // 1. Check if the binary search hit an exact match in the first column
        if (up_until_row < rows && matrix[up_until_row][0] == target) {
            return true;
        }

        // 2. If up_until_row is 0, target is smaller than the matrix's smallest element
        if (up_until_row == 0) {
            return false;
        }

        // 3. Search only the rows strictly before up_until_row
        size_t row_size = matrix[0].size() - 1;
        for (int i = 0; i < up_until_row; ++i) {
            if (row_bin_search(matrix, i, 0, row_size, target) != -1) {
                return true;
            }
        }
        
        return false;
    }
};