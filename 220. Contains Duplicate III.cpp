//Binary search using set, O(nlogk)
//maintain a window using a set, BS (num - t) in set, check if it <= num + t 
//if window.size > k, delete nums[i-k]
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for (int i = 0; i < nums.size(); i++){
            auto it = window.lower_bound(long(nums[i]) - t);
            if (it != window.end() && *it <= long(nums[i]) + t) return true;
            window.insert(nums[i]);
            if (i >= k) window.erase(nums[i - k]);
        }
        return false;
    }
};

//Using bucket, O(n)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0) return false;
		unordered_map<long, long> m; //bucket index, bucket element
		for (int i = 0; i < nums.size(); i++){
			long a = (long)nums[i] - INT_MIN;
			long bucketId = a / ((long)t + 1); //bucket size = t + 1
			if (m.count(bucketId)) return true;
			if (m.count(bucketId - 1) && (long)nums[i] - m[bucketId - 1] <= t) return true;
			if (m.count(bucketId + 1) && m[bucketId + 1] - (long)nums[i] <= t) return true;
			m[bucketId] = nums[i];
			if (m.size() > k) {
				long kickId = ((long)nums[i - k] - INT_MIN) / ((long)t + 1);
				m.erase(kickId); //maintain window
			}
		}
		return false;
    }

};