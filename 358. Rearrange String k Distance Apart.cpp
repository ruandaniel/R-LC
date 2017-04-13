class Solution {
    //in each k step as a round, put the char with highest rem in pq in order, after the round, reput them in to pq if nonzero
public:
    string rearrangeString(string s, int k) {
        if (k < 2) return s;
        unordered_map<char, int> m;
        for (auto c : s) m[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto i : m) pq.push({i.second, i.first}); //put all pairs into maxheap
        int remLen = s.size();
        string res = "";
        while(remLen){
            int steps = min(k, remLen);
            remLen -= steps;
            vector<pair<int, char>> cache;
            for (int i = 0; i < steps; i++){
                if (pq.empty()) return ""; //if no char can fill the position, then fail
                auto t = pq.top();
                pq.pop();
                res += t.second;
                if (t.first-1) cache.push_back({t.first-1, t.second}); //use cache because this round, these char can not appear again
            }
            for (auto i : cache) pq.push(i);
        }
        return res;
    }
};