class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left, right, up, down;
        left = findCol(image, 0, y, true);
        right = findCol(image, y, n, false);
        up = findRow(image, 0, x, true);
        down = findRow(image, x, m, false);
        return (right - left) * (down - up);
    }
    
    int findRow(vector<vector<char>>& image, int up, int down, bool isTop){
        while (up < down){
            int mid  = up + (down - up)/2;
            if (row(image, mid) == isTop){
                down = mid;
            }
            else up = mid+1;
        }
        return up;
    }
    
    int findCol(vector<vector<char>>& image, int left, int right, bool isLeft){
        while (left < right){
            int mid  = left + (right - left)/2;
            if (col(image, mid) == isLeft){
                right = mid;
            }
            else left = mid+1;
        }
        return left;
    }
    
    bool row(vector<vector<char>>& image, int x){
        for (int y = 0; y < image[0].size(); y++){
            if (image[x][y] == '1') return true;
        }
        return false;
    }
    bool col(vector<vector<char>>& image, int y){
        for (int x = 0; x < image.size(); x++){
            if (image[x][y] == '1') return true;
        }
        return false;
    }
};