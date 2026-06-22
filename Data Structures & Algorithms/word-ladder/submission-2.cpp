class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(beginWord == endWord) return 1;
        if(!st.count(endWord))return 0;

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == endWord) return steps;

                for(int i=0;i<curr.size();i++){
                    int orig = curr[i];
                    for(char ch = 'a' ; ch <='z';ch++){
                        curr[i] = ch;

                        if(st.count(curr)){
                            st.erase(curr);
                            q.push(curr);
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
