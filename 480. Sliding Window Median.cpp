class Solution {
public:
    //use a multiset, maintain a pointer pointing to the mid one
    //notice that, when erasing, always erase the first ele that equals to ...
    //take care of pointers in case of deleting mid
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() < k) return {};
        multiset<int> cache;
        vector<double> res;
        for (int i = 0; i < k; i++) cache.insert(nums[i]);
        auto mid = next(cache.begin(), (k-1)/2);
        bool even = (k % 2 == 0);
        res.push_back(even? (double(*mid) + *next(mid)) / 2 : *mid);
        for (int i = k; i < nums.size(); i++){
            cache.insert(nums[i]);
            if (even){
                if (nums[i] < *mid) mid--;
                if (nums[i-k] <= *mid) mid++;
                cache.erase(cache.lower_bound(nums[i-k]));
            }
            else{
                if (nums[i] >= *mid) mid++;
                if (nums[i-k] > *mid){
                    mid--;
                    cache.erase(cache.lower_bound(nums[i-k]));
                }
                else{
                    mid++;
                    cache.erase(cache.lower_bound(nums[i-k]));
                    mid--;
                }
            }
            res.push_back(even? (double(*mid) + *next(mid)) / 2 : *mid);
        }
        return res;
    }
};