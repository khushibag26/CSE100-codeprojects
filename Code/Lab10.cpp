#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


class SCC {
    int V;                     // vertices
    vector<vector<int>> adj;   // list
    int time;                  // given time

    // sees so that all elements in the list are accounted for
    void sccDFS(int v, vector<int> &num, vector<int> &less, stack<int> &st, vector<bool> &inList, vector<int> &ID);

public:
    SCC(int V);          
    void moveEdge(int v, int w); 
    void seeSCCs(vector<int> &ID); 
};


SCC::SCC(int V) {
    this->V = V;
    adj.resize(V);
    time = 0;
}


void SCC::moveEdge(int v, int w) {
    adj[v].push_back(w);
}


void SCC::sccDFS(int v, vector<int> &num, vector<int> &less, stack<int> &st, vector<bool> &inList, vector<int> &ID) {
    static int sccCounter = 0; 

    
    num[v] = less[v] = ++time;
    st.push(v);
    inList[v] = true;

    
    for (int neighbor : adj[v]) {
        if (num[neighbor] == -1) {
            sccDFS(neighbor, num, less, st, inList, ID);
            less[v] = min(less[v], less[neighbor]);
        } else if (inList[neighbor]) {
            less[v] = min(less[v], num[neighbor]);
        }
    }

    
    if (less[v] == num[v]) {
        vector<int> component;       // components of the Strongly Connected Components
        int u;
        int smallVertex = v; 

        do {
            u = st.top();
            st.pop();
            inList[u] = false;

            component.push_back(u);
            smallVertex = min(smallVertex, u);
        } while (u != v);

        for (int vertex : component) {
            ID[vertex] = smallVertex;
        }
    }
}

void SCC::seeSCCs(vector<int> &ID) {
    vector<int> num(V, -1);  
    vector<int> less(V, -1);   
    stack<int> st;            
    vector<bool> inList(V, false); 


    ID.resize(V, -1);

    // for the unvisited vertices
    for (int i = 0; i < V; i++) {
        if (num[i] == -1) {
            sccDFS(i, num, less, st, inList, ID);
        }
    }
}

// Driver function
int main() {
    int V, E;
    cin >> V >> E;

    SCC graph(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph.moveEdge(u, v);
    }

    
    vector<int> ID;

    graph.seeSCCs(ID);

    for (int i = 0; i < V; i++) {
        cout << ID[i] << endl;
    }

    return 0;
}
