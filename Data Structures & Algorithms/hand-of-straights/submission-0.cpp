class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // sort the hands
        if(hand.size() % groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());
        int group_formed = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i < hand.size(); ++i){
            if(freq.find(hand[i]) == freq.end())
                freq[hand[i]] = 1;
            else 
                freq[hand[i]]++;
        }
        for(int i = 0; i < hand.size(); ++i){
            if(freq[hand[i]] != 0){
                // consider a new group 
                freq[hand[i]]--;
                for(int j = 1; j < groupSize; ++j){
                    int val = hand[i] +j;
                    if(freq.find(val) == freq.end() || freq[val] == 0)
                        return false;
                    else 
                        freq[val]--;
                }
            }
        }
        return true;
    }
};
