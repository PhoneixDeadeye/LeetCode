class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen=INT_MAX;
        int start = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            while(sum>=target){
                minlen = min(minlen, i-start+1);
                sum-=nums[start];
                start++;
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};