#include <iostream>
#include <vector>
#include <limits>
#define INF numeric_limits<int>::max()
using namespace std;

int main () {
    int edges;
    int vertices;
    cin >> vertices >> edges;

    vector<vector<int>> edgePath;
    for (int i = 0; i < edges; i++) {
        int a;
        int b; 
        int c;
        cin >> a >> b >> c;
        edgePath.push_back({a, b, c});
    }


    vector<int> path(vertices, INF);
    path[0] = 0; // start the algorthim from the origin place

    bool negativeCycle = false; // when detecting negative cycles
    for (int i = 0; i < vertices - 1; i++) {
        for (auto p : edgePath) {
            int a = p[0];
            int b = p[1];
            int c = p[2];
            if (path[a] != INF && path[a] + c < path[b]) { // has to be one together expression, can't split it up
                path[b] = path[a] + c;
            }
        }
    }

    for (auto p: edgePath) {
        int a = p[0];
        int b = p[1];
        int c = p[2];
        if (path[a] != INF && path[a] + c < path[b]) {
            negativeCycle = true;
            break;
        }
    }

    // now the output time
    if (negativeCycle) {
        cout << "FALSE" << endl;
    } else {
        cout << "TRUE" << endl;
        for (int i = 0; i < vertices; i++) {
            if (path[i] == INF) {
                cout << "INFINITY" << endl;
            } else {
                cout << path[i] << endl;
            }
        }
    }
    return 0;
    
}

