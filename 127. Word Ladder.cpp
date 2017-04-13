class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict;
        for (auto word : wordList) wordDict.insert(word);
        unordered_set<string> head, tail;
        if (wordDict.find(endWord) == wordDict.end()) return 0; //endWord must be a transformed word
        head.insert(beginWord);
        tail.insert(endWord);
        int res = 1;
        while (!head.empty() && !tail.empty()){
            if (head.size() > tail.size()) swap(head, tail); //make sure we process a shorter one
            unordered_set<string> cur; //new-level
            for (auto it : head){
                //for each word, delete it in dict, replace every letter and if dict contains, add to cur
                wordDict.erase(it);
                auto w = it;
                for (auto t : tail){
                    if (w == t) return res;
                }
                for (int i = 0; i < w.size(); i++){
                    char copy = w[i];
                    for (char c = 'a'; c <= 'z'; c++){
                        w[i] = c;
                        if (wordDict.find(w) != wordDict.end()){
                            cur.insert(w);
                        }
                    }
                    w[i] = copy;
                }
            }
            swap(head, cur);
            res++;
        }
        return 0;
    }
};