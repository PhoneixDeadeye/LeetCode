class Solution {
public:
    int maxim(vector<int>& arr){
        int maxi=INT_MIN;
        for(int i=0; i<arr.size(); i++){
            maxi = max(arr[i], maxi);
        }
        return maxi;
    }

    int func(vector<int>& arr, int val){
        int ans=0;
        for(int i=0;i<arr.size(); i++){
            ans+=ceil((double)arr[i]/val);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=maxim(piles);
        int mid=0;
        while(l<r){
            mid = (l+r)/2;
            int hours=func(piles, mid);
            if(hours<=h){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};