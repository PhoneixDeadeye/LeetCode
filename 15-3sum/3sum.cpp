class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int x = nums[i];
            int sum = -x;
            int l = i+1;
            int r = n-1;
            while(l<r){
                int curr = nums[l]+nums[r];
                if(curr==sum){
                    ans.push_back({x, nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(l < r && nums[r] == nums[r + 1]) r--;
                }
                else if(curr>sum){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};