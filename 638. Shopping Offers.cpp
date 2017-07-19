//DFS with memory
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int, int> mmr;
        //for the key, every digit is a need, from the right; mmr stores lowest cost for a certain need
        mmr[0] = 0;
        return shop(price, special, needs, mmr);
    }
    
    int shop(vector<int>& price, vector<vector<int>>& special, vector<int> needs, unordered_map<int, int>& mmr){
        int key = getKey(needs);
        if (mmr.find(key) != mmr.end()) return mmr[key];
        int curLowCost = 0;
        //direct buy all needs
        for (int i = 0; i < needs.size(); i++){
            curLowCost += needs[i] * price[i];
        }
        //use special
        for (auto spe : special){
            bool flag = true;
            auto newNeeds = needs;
            for (int i = 0; i < needs.size(); i++){
                newNeeds[i] -= spe[i];
                if (newNeeds[i] < 0){
                    flag = false;
                    break;
                }
            }
            if (flag){
                int cost = spe.back() + shop(price, special, newNeeds, mmr);
                curLowCost = min(curLowCost, cost);
            }
        }
        mmr[key] = curLowCost;
        return curLowCost;
    }
    
    int getKey(vector<int>& needs){
        int key = 0;
        for (int i = 0; i < needs.size(); i++){
            key = key * 10 + needs[i];
        }
        return key;
    }
};