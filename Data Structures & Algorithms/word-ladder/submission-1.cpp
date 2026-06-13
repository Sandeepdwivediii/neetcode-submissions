class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() , wordList.end());
        queue<string>q;

        if(beginWord == endWord) return 0;
        q.push(beginWord);
        st.erase(beginWord);

        int steps = 1;
        while(!q.empty()){
            int n = q.size();

            while(n--){
            string curr = q.front();
            q.pop();

            if(curr == endWord) return steps;

            for(int i=0;i<curr.size();i++){
                char orig = curr[i];
                for(char ch='a'; ch <='z';ch++){
                    curr[i] = ch;
                    if(st.find(curr) != st.end()){
                        q.push(curr);
                        st.erase(curr);
                    }
                    curr[i] = orig;
                }
            }
            }
            steps++;
        }
        return 0;
    }
};
