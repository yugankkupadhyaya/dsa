class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto elem : prerequisites) {
            int u = elem[0];
            int v = elem[1];
            adj[v].push_back(u);
        }
        // create a vector indegree
        vector<int> indegree(numCourses, 0);

        for (int u = 0; u < numCourses; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0)
                q.push(i);
        }

        // bfs part
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int elem : adj[node]) {
                indegree[elem]--;
                if (indegree[elem] == 0)
                    q.push(elem);
            }

        }

        for(int elem:indegree){
            if(elem!=0){
                return false;
            }
        }return true ;

    }
};