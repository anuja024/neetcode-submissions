class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    int count =0;

    bool dfs(int node, int parent){
        visited[node] = true;
        count++;

        for(int neighbor: adj[node]){
            if(neighbor == parent) continue;

            if(visited[neighbor]) return false;

            if(!dfs(neighbor, node)) return false; // cycle
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) { 
        if( edges.size() != n-1) return false;

        adj.resize(n);
        visited.resize(n, false);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if (!dfs(0, -1))
            return false;

        return count == n;
    }
};
