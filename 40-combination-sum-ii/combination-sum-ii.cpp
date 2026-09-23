class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>&candidates, vector<int>&curr, int target, int total, int ind){
        if(total==target){
            ans.push_back(curr);
            return;
        }
        for(int i=ind; i<candidates.size(); i++){
            if(i>ind && candidates[i]==candidates[i-1]){
                continue;
            }
            if(total+candidates[i]>target) {
                break;
            }
            curr.push_back(candidates[i]);
            dfs(candidates, curr, target, total+candidates[i], i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>curr;
        dfs(candidates, curr, target, 0, 0);
        return ans;    
    }
};