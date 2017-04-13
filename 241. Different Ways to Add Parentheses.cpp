class Solution {
public:
    unordered_map<string, vector<int>> mem; //reduce repeated computing
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++){
            char c = input[i];
            if (c == '+' || c == '-' || c == '*'){ //divide input into two parts by cur operator
                vector<int> left, right;
                string l = input.substr(0, i), r = input.substr(i + 1);
                if (mem.find(l) != mem.end()) 
                    left = mem[l];
                else 
                    left = diffWaysToCompute(l);
                if (mem.find(r) != mem.end()) 
                    right = mem[r];
                else 
                    right = diffWaysToCompute(r);
                for (auto r1 : left){ //store all combinations
                    for (auto r2 : right){
                        if (c == '+') res.push_back(r1 + r2);
                        else if (c == '-') res.push_back(r1 - r2);
                        else res.push_back(r1 * r2);
                    }
                }
            }
        }
        if (res.empty()){ //no operator
            res.push_back(atoi(input.c_str()));
        }
        mem[input] = res;
        return res;
    }
};