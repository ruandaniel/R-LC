class Solution {
public:
    //from back to front, find % == 0 and swap, go to next level
    //in this way, we avoid usd[] and save time
    int countArrangement(int N) {
        vector<int> vs;
        for (int i=0; i<=N; ++i) vs.push_back(i);
        return counts(N, vs);
    }
    int counts(int n, vector<int>& vs) {
        if (n <= 0) return 1;
        int ans = 0;
        for (int i=1; i<=n; ++i) {
            if (vs[i]%n==0 || n%vs[i]==0) {
                swap(vs[i], vs[n]);
                ans += counts(n-1, vs);
                swap(vs[i], vs[n]);
            }
        }
        return ans;
    }
};