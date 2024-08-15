class Solution {
public:
    int rec(vector<vector<int>>& adj, int& ans, int root, int parent) {
    int subtreeSize = 1; // Start with 1 to include the root itself
    vector<int> childSizes;

    for (int child : adj[root]) {
        if (child == parent) continue; // Skip the parent node
        int size = rec(adj, ans, child, root);
        childSizes.push_back(size);
        subtreeSize += size;
    }

    if (!childSizes.empty()) {
        bool isGood = all_of(childSizes.begin(), childSizes.end(), 
                             [&](int sz) { return sz == childSizes[0]; });
        if (isGood) ans++;
    } else {
        // Leaf nodes are good nodes by definition
        ans++;
    }

    return subtreeSize;
}

int countGoodNodes(vector<vector<int>>& edges) {
    int n = edges.size() + 1; // Number of nodes
    vector<vector<int>> adj(n);

    // Build the adjacency list for the undirected tree
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    rec(adj, ans, 0, -1); // Start DFS from root (0)

    return ans;
}
};