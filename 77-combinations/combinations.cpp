class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, int n, int k, vector<int>&curr){
        if(i>n){
            if(curr.size()==k){
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back(i);
        solve(i+1, n, k, curr);
        curr.pop_back();
        solve(i+1, n, k, curr);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(1, n, k, curr);
        return ans;
    }
};