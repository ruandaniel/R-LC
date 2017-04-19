//Method 1: pq, O(nlogn) time
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
		priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq; //min-heap
		for (auto num : nums) m[num]++;
		for (auto i : m){
			pq.push({i.second, i.first});
			if (pq.size() > k) pq.pop();
		}
		vector<int> res;
		while (!pq.empty()) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
    }
};

//Method 2: bucket sort, O(n) time
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == 0) return {};
        vector<vector<int>> freq(nums.size() + 1, vector<int>());
        unordered_map<int, int> m; //<num, freq>
		for (auto num : nums) m[num]++;
		for (auto i : m){
		    freq[i.second].push_back(i.first);
		}
		vector<int> res;
        for (int i = nums.size(); ; i--){
            if (!freq[i].empty()){
                for (auto j : freq[i]) {
                    res.push_back(j);
                    if (--k == 0) return res;
                }
            }
        }
    }
};