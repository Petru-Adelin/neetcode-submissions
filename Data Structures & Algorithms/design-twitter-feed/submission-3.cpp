class Twitter {

private:

    int corr[501][501] = {0};
    vector<vector<pair<int, int>>> tweets;
    int timestamp = 0;

public:
    Twitter() {
        tweets = vector<vector<pair<int, int>>>(501);
        for(int i = 0; i < 500; ++i)
            tweets[i] = vector<pair<int, int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timestamp});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {

        // first -> timestamp
        // second -> tweetid
        // third -> index of the user
        // fourth -> index (that tweeted)
        priority_queue<tuple<int, int, int, int>>pq;
        
        for(int i = 0; i <= 500; ++i){
            if((corr[userId][i] == 1 || i == userId) && !tweets[i].empty()){
                int size = tweets[i].size();
                auto [tweetId, timestamp] = tweets[i][size-1];
                pq.push({timestamp, tweetId, i, size-1});
            }
        }

        vector<int> res;

        while(!pq.empty() && res.size() < 10){
            auto [timestamp, tweetId,id, index] = pq.top();
            pq.pop();
            // add to the result
            res.push_back(tweetId);
            if(index > 0){
                int newindex = index-1;
                auto [newTimestamp, newTweet] = tweets[id][newindex];
                pq.push({newTweet, newTimestamp, id, newindex});
            }
            
        }
        if(res.size() == 0)
            return {};
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        corr[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        corr[followerId][followeeId] = 0;
    }
};
