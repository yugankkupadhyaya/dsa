class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<int> dist(n, 1e8);
        dist[src] = 0;
        vector<int> temp = dist;

        // we need k+1 relaxations
        // apllying bellmon ford

        for (int i = 0; i < k + 1; i++) {

            for (auto& edge : flights) {

                int s = edge[0];
                int d = edge[1];
                int cost = edge[2];
                if (dist[s]!=1e8&&(temp[d] > dist[s] + cost)) {
                    temp[d] = dist[s] + cost;
                }

                
            }dist = temp;
        }
        if(dist[dst]!=1e8){
            return dist[dst];

        }return -1 ;

    }
};