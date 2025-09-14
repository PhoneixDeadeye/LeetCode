class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        vector<int> ans;
        int n = nums.size();
        int i =1;
        ans.push_back(nums[0]);
        k--;
        while(k>0 && i<n){
            if(nums[i]!=nums[i-1]){
                ans.push_back(nums[i]);
                k--;
            }
            i++;
        }
        return ans;
    }
};