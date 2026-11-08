class Solution {
public:

    bool feasible(vector<int>& piles, int k, int h){
        long long amount = 0 ;
        for(int i = 0; i < piles.size(); ++i){
            long long hours = (piles[i] + k -1) / k;
            amount += hours;
            if(amount > h)
                return false;
        }
        return true;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int maxim = *max_element(piles.begin(), piles.end());
        int start = 1, end = maxim;

        int k = maxim;

        while(start <= end){
            int mij = (start + end) /2 ;
            if(feasible(piles, mij, h)){
                k = mij;
                end = mij-1;
            }
            else    
                start = mij + 1;
        }
        return k;
    }
};