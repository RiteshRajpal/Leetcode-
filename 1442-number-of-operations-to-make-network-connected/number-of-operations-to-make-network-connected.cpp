class Solution {
public:

    // DFS to visit all computers in the same connected group
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {

        // Mark current computer as visited
        visited[node] = true;

        // Visit all computers connected to current computer
        for(int neighbor : graph[node]) {

            // If this computer is not visited
            if(!visited[neighbor]) {

                // Visit it using DFS
                dfs(neighbor, graph, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // To connect n computers, we need at least n-1 cables
        if(connections.size() < n - 1)
            return -1;

        // Create adjacency list for n computers
        vector<vector<int>> graph(n);

        // Add all connections to the graph
        for(auto connection : connections) {

            int u = connection[0];
            int v = connection[1];

            // Connection works in both directions
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Keep track of visited computers
        vector<bool> visited(n, false);

        // Number of separate groups
        int components = 0;

        // Check every computer
        for(int i = 0; i < n; i++) {

            // If computer is not visited,
            // it starts a new connected group
            if(!visited[i]) {

                // Visit the entire group
                dfs(i, graph, visited);

                // Count this group
                components++;
            }
        }

        // To connect k groups, we need k-1 operations
        return components - 1;
    }
};