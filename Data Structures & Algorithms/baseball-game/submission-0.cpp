class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();

        stack<int> st;

        for(auto op : operations){
            if(op == "C"){
                st.pop();
            }else if(op == "D"){
                st.push(st.top()*2);
            }else if(op == "+"){
                int top = st.top();
                st.pop();
                int sum = top + st.top();
                st.push(top);
                st.push(sum);
                
            }else{
            st.push(stoi(op));
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};