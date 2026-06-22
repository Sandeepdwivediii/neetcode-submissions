class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(auto &flight : flights){
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];
            adj[u].push_back({v,cost});
        
        }
        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);

        dist[src] = 0;
        q.push({src,0});
        int steps = 0;
        while(!q.empty() && steps <=k){
            int sz = q.size();

            while(sz--){
                auto [curr , ct] = q.front();
            q.pop();

            

            for(auto [node , cost] : adj[curr]){
                if(cost + ct < dist[node]){
                    dist[node] = cost+ct;
                    q.push({node , cost+ct});
                }
            }
            }
            steps++;
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];

    }
};



// we make a adj graph node-> dest , cost
// now level by level we will see if we can reach the destination 

