class Solution {
public:
    //assume kth permu is a1, a2, ..., an, then if we delete a1, we have n-1 ele, so (n-1)! permus, thus a1 = k/(n-1)!
    string getPermutation(int n, int k) {
        string res = "";
        //create factorial look up table
        vector<int> factorial(n+1, 1);
        for (int i = 1; i <= n; i++){
            factorial[i] = factorial[i-1] * i;
        }
        //create candidates list
        vector<char> can;
        for (int i = 1; i <= n; i++) can.push_back('0' + i);
        
        k--; //starts from 0
        //get index one by one, delete candidates after selected
        for (int i = 1; i <= n; i++){
            int index = k/factorial[n-i];
            res.push_back(can[index]);
            can.erase(can.begin() + index);
            k = k % factorial[n-i];
        }
        
        return res;
    }
};