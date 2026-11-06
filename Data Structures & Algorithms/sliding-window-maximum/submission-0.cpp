class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // first = value, second = index
        priority_queue<pair<int, int>> pq;
        // add the elements from the first window
        for(int i = 0; i < k; ++i){
            pair<int, int> p = {nums[i], i};
            pq.push(p);
        }
        vector<int> res;
        res.push_back(pq.top().first);
        int w_shift = k;
        size_t n = nums.size();
        while(w_shift < n){
            // push the next elem on the queue
            pq.push({nums[w_shift], w_shift});
            // get the result of the current shift
            bool found = false;
            while(!found){
                auto top = pq.top();
                if(top.second <= w_shift - k)
                    pq.pop();
                else{
                    res.push_back(top.first);
                    found = true;
                }
            } 
            w_shift++;
        }
        
        return res;
    }
    

};