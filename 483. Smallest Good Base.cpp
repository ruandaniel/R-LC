class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        //1+k^1+k^2+k^3+...+k^d=n
        //10^18 -> 2^62, find the largetst d <-> smallest k, d >= 1 , '=' when k = n-1
        for (int i = 62; i > 1; i--){
            if (num << i == 0) continue; //is num large enough for d digits in base 2? if not, skip
            long long base = search(num, i);
            if (base != -1) return to_string(base);
        }
        return to_string(num-1);
    }
    
    long long search(long long num, int i){
        //d = i, find base k
        long long low = 2;
        long long high = pow(double(num), 1.0/i)+1;
        while (low <= high){
            long long sum = 1, cur = 1;
            long long mid = low + (high - low)/2;
            for (int j = 1; j <= i; j++) {
                cur *= mid; //use cur to avoid pow()
                sum += cur;
            }
            if (sum == num) return mid;
            else if (sum < num) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};