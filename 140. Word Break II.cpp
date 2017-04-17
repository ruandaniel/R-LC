class Solution {
public:
    //DFS from beginning with memory
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic;
        for (auto w : wordDict) dic.insert(w);
        unordered_map<string, vector<string>> m;
        return DFS(s, dic, m);
    }
    
    vector<string> DFS(string s, unordered_set<string> &dic, unordered_map<string, vector<string>> &m){
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (auto w : dic){
            if (s.size() >= w.size() && s.substr(0, w.size()) == w){
                vector<string> sub = DFS(s.substr(w.size()), dic, m);
                for (auto i : sub){
                    if (i.empty()) res.push_back(w);
                    else res.push_back(w + ' ' + i);
                }
            }
        }
        m[s] = res;
        return res;
    }
};
