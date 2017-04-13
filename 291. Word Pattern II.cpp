class Solution {
public:
    //use backtracking to try do mapping with all possible(spare enough space) cases
    unordered_map<char, string> m;
    unordered_set<string> exist; //avoid existed mapping
    bool wordPatternMatch(string pattern, string str) {
        return match(pattern, 0, str, 0);
    }
    
    bool match(string pattern, int i, string str, int j){
        if (i == pattern.size() && j == str.size()) return true;
        else if (i == pattern.size() || j == str.size()) return false;
        if (m.count(pattern[i]) != 0){ //mapping exist, test and continue
            string s = m[pattern[i]];
            if (str.substr(j, s.size()) != s) return false;
            else return match(pattern, i+1, str, j+s.size());
        }
        else{
            int rem = str.size()-j;
            for (int k = i+1; k < pattern.size(); k++){ //check possible mapping len (spare space for next pattern chars)
                if (m.count(pattern[k]) != 0) rem -= m[pattern[k]].size();
                else rem -= 1;
            }
            for (int k = 1; k <= rem; k++){ //try all possible mapping
                string cur = str.substr(j, k);
                if (exist.find(cur) != exist.end()) continue;
                m[pattern[i]] = cur;
                exist.insert(cur);
                if (match(pattern, i+1, str, j+cur.size())) return true;
                m.erase(pattern[i]);
                exist.erase(cur);
            }
            return false;
        }
    }
};