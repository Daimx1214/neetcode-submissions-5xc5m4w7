class Twitter {
    int time;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> friends;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> total;

        for(auto p : tweets[userId]){
            total.push_back({p.second, p.first});
        }

        for(int f : friends[userId]){       
            for(auto p : tweets[f]){         
                total.push_back({p.second, p.first});
            }
        }
        sort(total.begin(), total.end(), greater<pair<int,int>>());

        vector<int> res;
        int i = 0;
        while(i<10 && i<total.size()){
            res.push_back(total[i].second);
            i++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            friends[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
