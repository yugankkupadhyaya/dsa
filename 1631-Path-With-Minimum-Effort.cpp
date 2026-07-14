class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isValid(int row, int col) {
    return row >= 0 && row < m &&
           col >= 0 && col < n;
}
  typedef pair<int, pair<int, int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
    
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        res[0][0] =0;

while(!pq.empty()){

    auto curr =pq.top();
    pq.pop();

    int dist = curr.first;
    int row=curr.second.first;
    int col=curr.second.second;
    for(int k=0;k<4;k++){
       int x=row +dx[k];
       int y=col+dy[k];
       if (!isValid(x, y))
    continue;
        int diff=abs(heights[x][y]-heights[row][col]);
        if(isValid(x,y)&&diff<res[x][y]){
           int newEffort = max(dist, diff);
           if (newEffort < res[x][y]) {
    res[x][y] = newEffort;
    pq.push({newEffort, {x, y}});
}


        }

    }


}
return res[m-1][n-1] ;
    }
};