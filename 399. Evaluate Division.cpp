class Solution {
public:
    //use a graph, find path
    unordered_map<string, vector<string>> neighbors;
    unordered_map<string, vector<double>> value;
        
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for (int i = 0; i < equations.size(); i++){ //put all the path into graph in both directions
            auto e = equations[i];
            auto v = values[i];
            neighbors[e.first].push_back(e.second);
            neighbors[e.second].push_back(e.first);
            value[e.first].push_back(v);
            value[e.second].push_back(1.0/v);
        }
        vector<double> res;
        for (auto q : queries){ //for each query find a valid path
            unordered_set<string> visitedFrom;
            double t = findSolution(q.first, q.second, visitedFrom);
            res.push_back(t == 0.0 ? -1.0 : t);
        }
        return res;
    }
    
    double findSolution(string from, string to, unordered_set<string> &visitedFrom){
        //if not exist or visited in this round, stop
        if (visitedFrom.find(from) != visitedFrom.end() || neighbors.count(from) == 0) return 0.0;
        visitedFrom.insert(from);
        if (from == to) return 1; //found, x/x = 1, return 1
        auto neigh = neighbors[from];
        auto vs = value[from];
        for (int i = 0; i < neigh.size(); i++){
            double res = vs[i] * findSolution(neigh[i], to, visitedFrom); //multiple step by step
            if (res) return res;  //non zero means found a path, return the cur path product
        }
        return 0.0;
    }
};