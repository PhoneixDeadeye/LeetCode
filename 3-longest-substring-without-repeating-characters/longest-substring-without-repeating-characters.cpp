class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mpp;
        int res = 0;
        int l=0;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
            while(mpp[s[i]]>1){
                mpp[s[l]]--;
                l++;
            }
            res = max(res, i-l+1);
        }
        return res;
    }
};