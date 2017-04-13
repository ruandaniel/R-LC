class Solution {
public:
    //use bit to mark same-0 or not same-1 char, get a new bit dic, select only same length words
    //find a mask that has shortest abbrlen and & any bitword in dic != 0 (means at least has one unique char)
    int bestMask, bestLen, targetLen;
    unordered_map<int, bool> tested;
    
    string minAbbreviation(string target, vector<string>& dictionary) {
        vector<int> bitDic;
        int candidate = 0; //mark all 1's bits
        for (auto w : dictionary){
            if (w.size() != target.size()) continue;
            int bitWord = 0;
            for (int i = 0; i < target.size(); i++){
                bitWord <<= 1;
                if (target[i] != w[i]) bitWord += 1; //differ, then 1, else 0
            }
            bitDic.push_back(bitWord);
            candidate |= bitWord; //finally all 1 bits will be in this, so that we avoid uneccessary mask btr
        }
        targetLen = bestLen = target.size();
        bestMask = -1;
        findMask(bitDic, candidate, 0, 0);
        return translate(target);
    }
    
    void findMask(vector<int> bitDic, int candidate, int start, int mask){
        if (!tested[mask]){
            tested[mask] = true;
            int len = abbrLen(mask);
            if (len >= bestLen) return; //already too long, stop; because change 0 to 1 will never decrease abbrLen
            bool pass = true;
            for (auto w : bitDic){
                if ((mask & w) == 0){ //if the abbr is same as any word in dic, fail
                    pass = false;
                    break;
                }
            }
            if (pass){
                bestLen = len;
                bestMask = mask;
            }
        }
        if (start == targetLen) return; //reach the length, stop
        findMask(bitDic, candidate, start+1, mask); //put cur bit 0, pass to next level
        if ((1 << start & candidate) != 0) findMask(bitDic, candidate, start+1, mask | (1 << start));
    }
    
    int abbrLen(int mask){
        int res = 0, count = 0;
        for (int i = 0; i < targetLen; i++){
            if ((mask & 1 << i) == 0){
                count++;
            }
            else{
                if (count != 0){
                    res += to_string(count).size();
                }
                count = 0;
                res++;
            }
        }
        if (count) res += to_string(count).size();
        return res;
    }
    
    string translate(string target){
        if (bestMask == -1) return target;
        string res = "";
        int count = 0;
        for (int i = 0; i < target.size(); i++){
            int shift = target.size() - 1 - i;
            if ((bestMask & 1 << shift) == 0){
                count++;
            }
            else{
                if (count != 0){
                    res += to_string(count);
                }
                count = 0;
                res += target[i];;
            }
        }
        if (count) res += to_string(count);
        return res;
    }
};