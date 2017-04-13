class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int> nums) {
        prefix.push_back(0);
        for (auto num : nums) prefix.push_back(prefix.back() + num);
    }
    
    int sumRange(int i, int j) {
        return prefix[j+1] - prefix[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */