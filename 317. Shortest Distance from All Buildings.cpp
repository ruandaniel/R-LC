class Solution {
public:
    //each round, take a building, BFS, cal the dist from it to all reachable cell and accumulate in total[][]
    //mark the visited cell in grid[][] to -1 for first round, -2 for second,..., so that for nth round, we only visit -(n-1) cells
    //use a dist[][] to record dist from the cur to this round building
    //use a total[][] to record dist from cur to all visited buildings
    int dirs[4][4] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int reachable = 0; // mark reachable of cur round, also avoid repeat
        int shortestThisRound;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] != 1) continue; //we need to BFS from a building
                auto dist = grid;
                queue<pair<int, int>> q;
                q.push({i, j});
                dist[i][j] = 0; //dist of building from building
                shortestThisRound = INT_MAX;
                while (!q.empty()){
                    auto t = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++){
                        int x = t.first + dirs[k][0], y = t.second + dirs[k][1];
                        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != reachable) continue; //not reachable or out of bound
                        q.push({x, y});
                        grid[x][y]--;  //change all reachable 0 to 1
                        dist[x][y] = dist[t.first][t.second] + 1;
                        total[x][y] += dist[x][y]; //accumulate the total dist of cur cell to all visited buildings
                        shortestThisRound = min(shortestThisRound, total[x][y]);   //find the min of this round
                    }
                }
                reachable--;
            }
        }
        return shortestThisRound == INT_MAX? -1 : shortestThisRound;
    }
};