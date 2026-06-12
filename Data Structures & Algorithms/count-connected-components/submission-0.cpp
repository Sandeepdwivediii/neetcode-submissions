class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        vector<int> size;

        DSU(int n){
            size.resize(n,1);
            parent.resize(n);

            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int find(int x){
            if(parent[x] == x) return x;
            else return parent[x] = find(parent[x]);
        }

        void merge(int a , int b){
            int la = find(a);
            int lb = find(b);

            if(la == lb) return;
            if(size[la] < size[lb]){
                swap(la,lb);
            }
            parent[lb] = la;
            size[la] += size[lb];
        }
    };
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto &e: edges){
            auto x = e[0];
            auto y = e[1];
            dsu.merge(x,y);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(dsu.find(i) == i){
                count++;
            }
        }
        return count;

    }
};
