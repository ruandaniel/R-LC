class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        if (words.empty()) return {};
        unordered_map<char, int> m;
        m['q'] = 1; m['w'] = 1; m['e'] = 1; m['r'] = 1; m['t'] = 1; 
        m['y'] = 1; m['u'] = 1; m['i'] = 1; m['o'] = 1; m['p'] = 1;
        m['a'] = 2; m['s'] = 2; m['d'] = 2; m['f'] = 2; m['g'] = 2; 
        m['h'] = 2; m['j'] = 2; m['k'] = 2; m['l'] = 2;
        m['z'] = 3; m['x'] = 3; m['c'] = 3; m['v'] = 3; m['b'] = 3; m['n'] = 3; m['m'] = 3;
        vector<string> res;
        for (auto w : words){
            if (w.empty()) res.push_back(w);
            else{
                bool isSame = true;
                int t = m[(char)tolower(w[0])];
                for (int i = 1; i < w.size(); i++){
                    if (m[(char)tolower(w[i])] != t) {
                        isSame = false;
                        break;
                    }
                }
                if (isSame) res.push_back(w);
            }
        }
        return res;
    }
};