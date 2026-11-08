using indeces = vector<int>;
using mat = vector<vector<int>>;


class Solution {
public:

    int col_bin_search(mat& m,int start, int end, int target){
        if(start > end)
            return start;
        int mij = (start + end) / 2;
        if(m[mij][0] == target)
            return mij;
        if(m[mij][0] < target)
            return col_bin_search(m, mij+1, end, target); 
        return col_bin_search(m, start, mij-1, target);
    }

    int row_bin_search(mat& m,int row, int start, int end, int target){
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

        //bianry search it on the first column to find up untill where we should go
        int up_until_row = col_bin_search(matrix, 0, matrix.size()-1, target);
        

        // verify is the first element is the response 
        if(up_until_row < matrix.size() && matrix[up_until_row][0] == target)
            return true;

        size_t row_size = matrix[0].size()-1;
        for(int i = 0; i < up_until_row; ++i){
            int row_result = row_bin_search(matrix, i, 0, row_size, target);
            if(row_result != -1)
                return true;
        }
        return false;
    }
};
