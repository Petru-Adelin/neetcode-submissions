int init = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {

    /*
        mat[i][j] == 1 => We have a queen 
        mat[i][j] == 2 => We don t have a queen
    */
    bool valid_placement(int **mat, int n, int i, int j){
        // check horizontly
        for(int k = 0; k < n; ++k){
            if(mat[i][k] == 1)
                return false;
            if(mat[k][j] == 1)
                return false;
        }
        // upper principle diag
        for(int k = min(i, j); k >= 0; k--){
            if(mat[i-k][j-k] == 1)
                return false;
        }
        // lower principle diag 
        for(int k = 0; k < n - max(i, j); k++){
            if(mat[i+k][j+k] == 1)
                return false;
        }
        // upper second diag
        // j = n - i -1 
        // i-k && j+k => 
        for(int k = 0; k <= min(i, n-j-1); k++){
            if(mat[i-k][j+k] == 1)
                return false;
        }
        // lower second diag
        for(int k = 0; k <= min(n-i-1, j); k++){
            if(mat[i+k][j-k] == 1)
                return false;
        }
        return true;
    }

    vector<string> stringify(int **mat, int n){
        vector<string> sol;
        for(int i = 0; i < n; ++i){
            string part = "";
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0)
                    part += ".";
                else 
                    part += "Q";
            }
            sol.push_back(part);
        }
        return sol;
    }

public:

    void bkt(int **mat,int index, int n, vector<vector<string>>& sol){
        if(index == n){
            // convert solution into vector<string> 
            auto partial = stringify(mat, n);
            sol.push_back(partial);
            return;
        }
        // find the location for the queen in the row 'index'
        for(int i = 0; i < n; ++i){
            if(mat[index][i] == 0 && valid_placement(mat, n, index, i)){
                mat[index][i] = 1;
                bkt(mat, index+1, n, sol);
                mat[index][i] = 0;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        int **mat = new int*[n];
        for(int i = 0; i < n; ++i){
            mat[i] = new int[n];
            fill(mat[i], mat[i]+n, 0);
        }

        vector<vector<string>> sol;
        bkt(mat, 0, n, sol);
        
        // reconrd the answear and free the memory
        for(int i = 0; i < n; ++i){
            delete[] mat[i];
        }
        delete[] mat;
        return sol;
    }
};