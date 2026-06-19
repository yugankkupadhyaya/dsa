1class Solution {
2public:
3   void dfs(int node, int& nodeno, int& edgeno,
4         vector<vector<int>>& adj,
5         vector<int>& visited) {
6        // mark as visited
7        visited[node] = 1;
8        nodeno++;
9        edgeno += adj[node].size();
10       for (int neigh : adj[node]) {
11    if (!visited[neigh]) {
12        dfs(neigh, nodeno, edgeno, adj, visited);
13    }
14}
15    }
16    int countCompleteComponents(int n, vector<vector<int>>& edges) {
17        vector<vector<int>> adj(n);
18        vector<int> visited(n, 0);
19        for (auto& e : edges) {
20            int u = e[0];
21            int v = e[1];
22            adj[u].push_back(v);
23            adj[v].push_back(u);
24        } // now we have adjacencuy list
25
26        int count = 0;
27        for (int i = 0; i < n; i++) {
28            int nodeno = 0;
29            int edgeno = 0;
30
31           if (visited[i] == 0) {
32    dfs(i, nodeno, edgeno, adj, visited);
33
34    edgeno /= 2;
35
36    if (edgeno == nodeno * (nodeno - 1) / 2)
37        count++;
38}
39        }
40        return count;
41    }
42};