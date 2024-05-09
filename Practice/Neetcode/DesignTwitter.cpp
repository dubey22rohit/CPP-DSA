#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
   private:
    vector<pair<int, int>> posts;
    unordered_map<int, unordered_set<int>> followMap;

   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int count = 10;
        for (int i = posts.size() - 1; i >= 0; i--) {
            if (count == 0) {
                break;
            }
            int followingId = posts[i].first;
            int tweetId = posts[i].second;
            unordered_set<int> following = followMap[userId];
            if (following.find(followingId) != following.end() ||
                followingId == userId) {
                feed.push_back(tweetId);
                count--;
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

int main() { return 0; }