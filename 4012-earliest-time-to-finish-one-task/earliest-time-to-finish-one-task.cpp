class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int res = INT_MAX;
        for(auto i : tasks){
            int temp = i[0]+i[1];
            res = min(res, temp);
        }
        return res;
    }
};