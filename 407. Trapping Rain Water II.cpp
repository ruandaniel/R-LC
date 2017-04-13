class Solution {
public:
    //bfs from the border, find non-border neighbors
    //mark neighbors as border, if trap water, fill the cell to the same height and accumulate water
    int dirs[4][4] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
    
    struct Cell{
        int x, y, h;
        Cell(int a, int b, int c): x(a), y(b), h(c){}
    };
    
    struct comp{
        bool operator()(Cell a, Cell b){
            return a.h > b.h;
        }  
    };
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<Cell, vector<Cell>, comp> pq;
        vector<vector<bool>> border(m, vector<bool>(n, false));
        //put all border cell to the pq 
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0 || j == 0 || i == m-1 || j == n-1){
                    border[i][j] = true;
                    pq.push(*(new Cell(i, j, heightMap[i][j])));
                }
        int res = 0;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++){
                int x = t.x + dirs[i][0], y = t.y + dirs[i][1];
                if (x < 0 || y < 0 || x == m || y == n || border[x][y]) continue;
                //mark as border, if trappable (fill to the same height, accumulate the water), put in the pq
                border[x][y] = true;
                res += max(0, t.h - heightMap[x][y]);
                pq.push(*(new Cell(x, y, max(t.h, heightMap[x][y]))));
            }
        }
        return res;
    }
};