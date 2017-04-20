class Solution {
public:
	//DP, left to right, each regarded as mid to spread and update the right end
	int minCut(string s) {
		if (s.empty()) return 0;
		int n = s.size();
		vector<int> dp(n + 1, 0);
		for (int i = 0; i <= n; i++){
			dp[i] = i - 1; //dp[0] = -1, dp[1] = 0
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; i - j >= 0 && i + j <= n; j++){ //odd
				if (s[i - j] == s[i + j]){
					dp[i + j + 1] = min(dp[i + j + 1], 1 + dp[i - j]);
				}
				else break;
			}
			for (int j = 1; i - j + 1 >= 0 && i + j <= n; j++){ //even
				if (s[i - j + 1] == s[i + j]){
					dp[i + j + 1] = min(dp[i + j + 1], 1 + dp[i - j + 1]);
				}
				else break;
			}
		}
		return dp[n];
	}
};