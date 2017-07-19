class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> mark (s.size(), false); //mark all Bold Chars
        int end = 0;
        for (int i = 0; i < s.size(); i++){
            for (auto word : dict){
                if (s.size() - i < word.size() || i + word.size() <= end) continue;
                bool startWith = true;
                for (int k = 0; k < word.size(); k++){
                    if (word[k] != s[i + k]){
                        startWith = false;
                        break;
                    }
                }
                if (!startWith) continue;
                for (int k = max(end, i); k < min(s.size(), i + word.size()); k++){
                    mark[k] = true;
                }
                if (i + word.size() > end) end = i + word.size();
            }
        }
        //use marks to add tags
        string res = "";
        int i = 0, j = 0;
        while (i < s.size()){
            if (!mark[i]) res.push_back(s[i++]);
            else{
                j = i + 1;
                while (j < s.size() && mark[j]) j++;
                res += "<b>" + s.substr(i, j - i) + "</b>";
                i = j;
            }
        }
        return res;
    }
};