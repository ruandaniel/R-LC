class ValidWordAbbr {
public:
    unordered_map<string, int> m;
    unordered_map<string, bool> exist;
    
    ValidWordAbbr(vector<string> dictionary) {
        for (auto w : dictionary) {
            if (exist[w]) continue;
            m[transform(w)]++;
            exist[w] = true;
        }
    }
    
    bool isUnique(string word) {
        int c = m[transform(word)];
        return c == 0 || (exist[word] && c == 1);
    }
    
    string transform(string word){
        if (word.size() <= 2) return word;
        string s = "";
        s += word[0] + to_string(word.size()-2) + word.back();
        return s;
    }
};