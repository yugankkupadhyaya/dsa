class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int>result;

        queue <int>q; 
      for (auto &p : prerequisites){
            indegree[p[0]]++;
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
        }
        // look for 0 indegree
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        //now lets operate on all the indegree 0 and queue 
        while(!q.empty()){
            int node =q.front();
            q.pop();
            result.push_back(node);
            for(auto p:adj[node]){
                indegree[p]--;
                if(indegree[p]==0){
                    q.push(p);
                }
            }
        }
        
        for(int a:indegree){
            if(a!=0){
                return {};
            }
        }
         return result;



    }
};