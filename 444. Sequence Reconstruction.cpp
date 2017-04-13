class Solution {
public:
    //if two consecutive nums in org, we can't find any seq contains both (if contains, they must be consecutive)
    //then it's not unique because their order doesn't matter, we can swap them
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty() && !org.empty()) return false;
        unordered_map<string, bool> cPair; //store conseecutive pairs in seqs
        unordered_map<int, int> pos; //store position of int in org
        for (int i = 0; i < org.size(); i++) pos[org[i]] = i;
        for (auto seq : seqs){
            if (seq.empty()) continue;

            for (int i = 0, pre; i < seq.size(); i++){
                if (pos.count(seq[i]) == 0) return false;  //int not exist in org
                if (i == 0) {
                    cPair[" " + to_string(seq[i])] = true; //in case of org has only one ele
                    pre = seq[i];
                }
                else{
                    if (pos[seq[i]] <= pos[seq[i-1]]) return false; //if order of the cur two in org is wrong, false
                    cPair[to_string(pre) + " " + to_string(seq[i])] = true; //store the consecutive pair
                    pre = seq[i];
                }
            }
        }
        if (cPair.count(" " + to_string(org[0])) == 0) return false; //in case of org has only one ele and not exist in seqs
        for (int i = 1; i < org.size(); i++){
            if (cPair.count(to_string(org[i-1]) + " " + to_string(org[i])) == 0) return false;
        }
        return true;
    }
};