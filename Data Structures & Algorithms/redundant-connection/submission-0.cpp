class Solution {
public:
    class DSU{
        public:
        vector<int>parent;
        vector<int>size;

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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        for(auto &e:edges){
            auto x = e[0];
            auto y = e[1];

            if(dsu.find(x) == dsu.find(y)){
                return {x,y};
            }else{
                dsu.merge(x,y);
            }
        }
        return {};
    }
};
