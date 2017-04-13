class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> m;
        unordered_set<char> mapped;
        for (int i = 0; i < s.size(); i++){
            if (m.count(s[i]) == 0){
                if (mapped.find(t[i]) != mapped.end()) return false;
                else{
                    m[s[i]] = t[i];
                    mapped.insert(t[i]);
                }
            }
            else{
                if (t[i] != m[s[i]]) return false;
            }
        }
        return true;
    }
};