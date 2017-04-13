class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        if (n == 3) return 1;
        vector<bool> prime(n, true);
        int res = 1; //2
        for (int i = 3; i < n; i += 2){
            if (prime[i]){
                res++;
                for (int j = 2; j * i < n; j++){
                    prime[i*j] = false;
                }
            }
        }
        return res;
    }
};