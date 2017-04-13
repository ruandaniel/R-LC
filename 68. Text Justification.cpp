class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (maxWidth == 0) return {""};
        int left = 0, right = 0;
        vector<string> res;
        while (right < words.size()){
            int curLen = -1;
            while (right < words.size()){ //move two pointers
                if (curLen + 1 + words[right].size() <= maxWidth)
                    curLen += 1 + words[right++].size();
                else break;
            }
            int base = 0, rem = 0; //these two indicates the spaces between words
            if (right != words.size() && right - left > 1){
                base = (maxWidth - curLen)/(right - left - 1);
                rem = (maxWidth - curLen)%(right - left - 1);
            } //if last line or only one word, we don't need space
            string cur = words[left];
            for (int i = left+1; i < right; i++){ //connect words
                if (i-left <= rem) cur += ' ';
                for (int j = 0; j < 1 + base; j++) cur += ' ';
                cur += words[i];
            }
            while (cur.size() < maxWidth) cur += ' '; //cur line not enough long, add space
            res.push_back(cur);
            left = right;
        }
        return res;
    }
};