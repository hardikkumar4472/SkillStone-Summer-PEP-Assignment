#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[src] = 0;
    q.push(src);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},    // 0
        {0, 3, 4}, // 1
        {0, 5},    // 2
        {1},       // 3
        {1},       // 4
        {2}        // 5
    };
    
    int src = 0;
    vector<int> distances = shortestPath(adj, src);
    
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < distances.size(); i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }
    
    return 0;
}