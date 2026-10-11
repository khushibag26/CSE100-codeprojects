#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
    int vertex;
    int weight_num;
};

// Prim's Algorithm applied here
void primMST(int numVertices, const vector<vector<Edge>>& adjList) {
    vector<int> key(numVertices, numeric_limits<int>::max()); // vertices are here
    vector<int> parent_num(numVertices, -1); 
    vector<bool> select(numVertices, false);
    
    // Priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lessHeap;

    // Start with the root vertex, where the vertex starts from
    key[0] = 0;
    lessHeap.push({0, 0}); 

    while (!lessHeap.empty()) {
        // sees the smallest key value
        int val = -1;
        while (!lessHeap.empty()) {
            int vertex = lessHeap.top().second;
            lessHeap.pop();
            if (!select[vertex]) {
                val = vertex;
                break;
            }
        }
        if (val == -1) break;

        select[val] = true; 

        // key and parent_num are updated here accordingly
        for (const Edge& edge : adjList[val]) {
            int v = edge.vertex;
            int weight_num = edge.weight_num;
            if (!select[v] && weight_num < key[v]) {  
                key[v] = weight_num;
                parent_num[v] = val;
                lessHeap.push({key[v], v});
            }
        }
    }

    
    for (int i = 1; i < numVertices; ++i) {
        cout << parent_num[i] << endl;
    }
}

// driver function
int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<vector<Edge>> adjList(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        int val, v, w;
        cin >> val >> v >> w;
        adjList[val].push_back({v, w});
        adjList[v].push_back({val, w});
    }

    primMST(numVertices, adjList);

    return 0;
}
