class Solution {
public:
    //record min and 2nd-min cost of last round, so that we can get min last-round cost for all colors
    //to avoid repeating min()
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int n = costs.size(), k = costs[0].size();
        int min1 = -1, min2 = -1;
        for (int i = 0; i < n; i++){
            int last1 = min1, last2 = min2; //copy last round min and 2nd-min
            min1 = -1;
            min2 = -1;
            for (int j = 0; j < k; j++){
                if (j == last1){ //same color with last-round min, + 2nd-min
                    costs[i][j] += costs[i-1][last2];
                }
                else { //not same as last min, + min; if first round, +0
                    costs[i][j] += last1 >= 0 ? costs[i-1][last1] : 0;
                }
                //update min and 2nd-min for this round
                if (min1 == -1 || costs[i][j] <= costs[i][min1]){
                    min2 = min1;
                    min1 = j;
                }
                else if (min2 == -1 || costs[i][j] < costs[i][min2]) min2 = j;
            }
        }
        return costs[n-1][min1];
    }
};