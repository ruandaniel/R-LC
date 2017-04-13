class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i = sqrt(area);
        while (area % i != 0) i--;
        return {area/i, i};
    }
};