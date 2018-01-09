class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int> > lst(n + 1);
        vector<vector<int> > redundant;
        for (int i = 0; i < n; i++) {
            lst[edges[i][0]].push_back(edges[i][1]);
            lst[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = n - 1; i >= 0; i--) {
            vector<bool> visited(n + 1, false);
            if (dfs(edges[i][0], edges[i][1], visited, lst, true)) {
                return edges[i];
            }
        }
        return vector<int>();        
    }
    bool dfs(int u, int v, vector<bool>& visited, vector<vector<int> >& lst, bool first) {
        if (u == v)
            return true;
        visited[u] = true;
        for (int i = 0; i < lst[u].size(); i++) {
            if (((first && lst[u][i] != v) || (!first)) && !visited[lst[u][i]]) {
                if (dfs(lst[u][i], v, visited, lst, false))
                    return true;
            }
        }
        return false;
    }
};
