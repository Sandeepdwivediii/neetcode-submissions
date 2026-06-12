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
        void merge(int a, int b){
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
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        DSU dsu(n);
        for(auto &e : edges){
            int x = e[0];
            int y = e[1];

            if(dsu.find(x) == dsu.find(y)){
                return false;
            }else{
                dsu.merge(x,y);
            }
        }
        return true;
    }
};
