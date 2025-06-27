class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans;
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            int val = nums[mid];
            if(val>nums[r] ){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return nums[l];
    }
};