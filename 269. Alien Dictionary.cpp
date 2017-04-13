class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) return words[0];
        //generate a graph[26][26], neighbor<int, vector>, indegree[]
        vector<vector<int>> g(26, vector<int>(26, 0));
        vector<int> indegree(26, -1); //-1 means no show up
        unordered_map<int, vector<int>> neighbor;
        for (auto c : words[0]) if (indegree[c-'a'] == -1) indegree[c-'a'] = 0;  //letter shows up, ind = 0
        for (int i = 0; i < words.size()-1; i++){
            int len = min(words[i].size(), words[i+1].size());
            for (auto c : words[i+1]) if (indegree[c-'a'] == -1) indegree[c-'a'] = 0;
            for (int j = 0; j < len; j++){
                int a = words[i][j] - 'a', b = words[i+1][j] - 'a';
                if (a == b) continue;
                if (g[b][a] == 1) return "";
                else {
                    g[a][b] = 1;
                    indegree[b]++;
                    neighbor[a].push_back(b);
                }
                break;
            }
        }
        //put all zero-indegree letter into queue
        queue<int> q;
        for (int i = 0; i < 26; i++){
            if (indegree[i] == 0) q.push(i);
        }
        //topographical sort
        string res;
        while (!q.empty()){
            auto t = q.front();
            q.pop();
            res.push_back(char('a'+t));
            for (auto n : neighbor[t]){
                indegree[n]--;
                if (indegree[n] == 0) q.push(n);
            }
        }
        //check circle
        for (int i = 0; i < 26; i++) if (indegree[i] > 0) return "";
        return res;
    }
    
};