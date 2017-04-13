class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() < 2) return "/";
        int left = 0, right = 1;
        string res = "";
        list<string> cache;
        for (; right <= path.size(); right++){
            if (path[right] != '/' && right != path.size()) continue; //care about the ending without '/'
            string cur = path.substr(left+1, right-left-1);
            if (cur != "" && cur != "."){ // /./ and // do nothing
                if (cur == ".."){
                    if (!cache.empty()) cache.pop_back();
                }
                else cache.push_back(cur);
            }
            left = right;
        }
        while (!cache.empty()){
            res += '/' + cache.front();
            cache.pop_front();
        }
        return res == ""? "/" : res;
    }
};