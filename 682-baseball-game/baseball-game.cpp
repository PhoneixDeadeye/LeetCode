class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(auto it:operations){
            if(it=="+"){
                int top = st.top();
                st.pop();
                int newtop = st.top()+top;
                st.push(top);
                st.push(newtop);
                sum+=newtop;
            }
            else if(it=="D"){
                int top = st.top();
                int newtop = top*2;
                st.push(newtop);
                sum+=newtop;
            }
            else if(it=="C"){
                int top = st.top();
                st.pop();
                sum-=top;
            }
            else{
                st.push(stoi(it));
                sum+=st.top();
            }
        }
        return sum;
    }
};