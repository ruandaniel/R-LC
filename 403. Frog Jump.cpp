//Method 1: DP (162ms)
class Solution {
public:
    //DP, for cur stone, update reachable stones by inserting their available jumps to the HashMap
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n == 1) return 1;
        unordered_map<int, unordered_set<int>> dp; //record available jumps
        dp[0].insert(1);
        for (auto stone : stones){
            for (auto jump : dp[stone]){
                if (stone + jump == stones.back()) return true;
                if (jump > 1) dp[stone + jump].insert(jump - 1);
                dp[stone + jump].insert(jump);
                dp[stone + jump].insert(jump + 1);
            }
        }
        return false;
    }
};

//Method 2: DFS (9ms)
class Solution {
public:
    unordered_set<int> stonesSet;
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n <= 1) return true;
        stonesSet.insert(0);
        for(int i = 1; i < n; i++)
        {
            if(stones[i] - stones[i-1] > i) return false; //too far, ith jump's maximum is i
            stonesSet.insert(stones[i]);
        }
        return DFS(1, 1, stones[n-1]);
    }
    bool DFS(int pos, int preJump, int target){ //cur pos, pre jump, target pos
        if (stonesSet.find(pos) == stonesSet.end() || pos > target) return false; //not a stone or too far
        if (pos == target) return true;
        for (int i = 1; i >= -1; i--){ //from farest jump to shortest jump
            int curJump = preJump + i;
            if (curJump > 0 && DFS(pos + curJump, curJump, target)) return true;
        }
        return false;
    }
};