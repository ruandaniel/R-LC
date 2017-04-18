class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m; //<word, index>
        set<int> lens; //store all existing lengths
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++){
            m[words[i]] = i;
            lens.insert(words[i].size());
        }
        //for each word, pair it with shorter or same-length words
        for (int i = 0; i < words.size(); i++){
            string w = words[i], rev = w;
            reverse(rev.begin(), rev.end());
            int len = w.size();
            if (m.count(rev) && m[rev] != i) res.push_back({i, m[rev]});
            for (auto j = lens.begin(); *j != len; j++){
                int l = *j;
                //set words[i] on the left
                if (isPal(w.substr(l)) && m.count(rev.substr(len - l)))
                    res.push_back({i, m[rev.substr(len - l)]});
                //set words[i] on the right
                if (m.count(rev.substr(0, l)) && isPal(w.substr(0, len - l)))
                    res.push_back({m[rev.substr(0, l)], i});
            }
        }
        return res;
    }
    
    bool isPal(string s){
        int i = 0, j = s.size()-1;
        while (i < j)
            if (s[i++] != s[j--]) return false;
        return true;
    }
    
};