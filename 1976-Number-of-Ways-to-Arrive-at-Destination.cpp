class Solution {
public:
    typedef pair<long long, int> P; // {distance, node}

    int countPaths(int n, vector<vector<int>>& roads) {
const int MOD = 1e9 + 7;
        // Adjacency List: {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n);
        vector<int> ways(n, 0);
        ways[0] = 1;

        for (auto& edge : roads) {
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];

            adj[source].push_back({destination, weight});
            adj[destination].push_back({source, weight});
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<long long> dist(n, LLONG_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            long long d = curr.first;
            int node = curr.second;

            // Ignore stale entries
            if (d > dist[node])
                continue;

            // Explore neighbours
            for (auto edge : adj[node]) {

                int neigh = edge.first;
                int wt = edge.second;
               long long newDist = wt + dist[node];
                if (newDist == dist[neigh]) {
                    ways[neigh] =(ways[neigh]+ways[node])%MOD;
                }  else if(newDist < dist[neigh]){

                    dist[neigh] = newDist;
                    ways[neigh] = ways[node];
                    pq.push({newDist, neigh});
                }
            }
        }

        return ways[n-1];
    }
};