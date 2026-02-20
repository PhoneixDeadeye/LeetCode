class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0;
        int t = 0;

        for(int i=0; i<bills.size(); i++){
            int curr = bills[i];

            if(curr==5) f++;
            else if(curr==10){
                if(f>0){
                    f--;
                    t++;
                }
                else return false;
            }
            else{
                if(f>0 && t>0){
                    f--;
                    t--;
                }
                else if(f>=3){
                    f -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};