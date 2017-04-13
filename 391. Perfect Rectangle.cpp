class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // area should be same, all corner points should appear twice except for the big rec corners
        unordered_map<string, bool> m;
        //use a string x@y to represent a cordinator
        int l = INT_MAX, r = INT_MIN, t = INT_MIN, b = INT_MAX;
        int area = 0;
        for (auto rec : rectangles){  //left, bottom, right, top
            vector<string> cor;
            cor.push_back(to_string(rec[0]) + "@" + to_string(rec[1]));
            cor.push_back(to_string(rec[0]) + "@" + to_string(rec[3]));
            cor.push_back(to_string(rec[2]) + "@" + to_string(rec[1]));
            cor.push_back(to_string(rec[2]) + "@" + to_string(rec[3]));
            for (auto c : cor){
                if (m.find(c) == m.end()){
                    m[c] = true;  //once then put
                }
                else{
                    m.erase(c);  //twice then delete
                }
            }
            l = min(l, rec[0]);
            b = min(b, rec[1]);
            r = max(r, rec[2]);
            t = max(t, rec[3]);
            area += (rec[3] - rec[1]) * (rec[2] - rec[0]);
        }
        vector<string> cor;
        cor.push_back(to_string(l) + "@" + to_string(b));
        cor.push_back(to_string(l) + "@" + to_string(t));
        cor.push_back(to_string(r) + "@" + to_string(b));
        cor.push_back(to_string(r) + "@" + to_string(t));
        for (auto c : cor) if (!m[c]) return false;
        if (m.size() != 4) return false;
        return area == (r-l) * (t-b);
    }
};