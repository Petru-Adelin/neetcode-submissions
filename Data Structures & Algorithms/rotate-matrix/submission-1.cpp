class Solution{
public:
    /**
     * BETTER SOLUTION: Transpose and reverse the raws
     */
    void rotate(vector<vector<int>>& matrix) {
        // transpose of the matrix
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = i+1; j < matrix.size(); ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each raw
        for(auto& row: matrix){
            reverse(row.begin(), row.end());
        }
    }
};