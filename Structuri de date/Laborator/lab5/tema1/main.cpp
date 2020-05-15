#include <bits/stdc++.h>

using namespace std;

const int Dim = 1e4 + 5;
bool c[Dim];

class directedGraph {
    vector <int> G[Dim]; // lista de adiacenta
    int NrNode; // numarul de noduri din graf

    unordered_map <int, bool> mp; // pentru a afla in O(1) daca exista sau nu o muchie

public:
    directedGraph() {
        NrNode = 0;
    }

    void addNode(int);
    void addEdge(int, int);
    int hasEdge(int, int);

    void BFS(int);
    void DFS(int);
    int twoCycles();

    friend istream& operator >>(istream&, directedGraph&);
};

void directedGraph::addNode(int a) {
    ++ NrNode;
}

void directedGraph::addEdge(int source, int target) {
    G[source].push_back (target);
    mp[source * Dim * 10 + target] = true;
}

int directedGraph::hasEdge(int source, int target) {
    if (mp[source * Dim * 10 + target] == true) {
        return true;
    }

    return false;
}

void directedGraph::BFS(int startNode) {
    memset(c, 0, sizeof (c));

    queue <int> coada;
    coada.push (startNode);
    c[startNode] = 1;
    while (!coada.empty()) {
        int node = coada.front();
        coada.pop();

        cout << node << " ";

        for (auto it: G[node]) {
            if (c[it] == 0) {
                coada.push(it);
                c[it] = 1;
            }
        }
    }
}

void directedGraph::DFS(int startNode) {
    cout << startNode << " ";
    c[startNode] = 1;
    for (auto it: G[startNode]) {
        if (c[it] == 0) {
            c[it] = 1;
            this -> DFS(it);
        }
    }
}

int directedGraph::twoCycles() {
    int ans = 0;
    for (int node = 1; node <= NrNode; ++ node) {
        for (auto it: G[node]) {
            if (this -> hasEdge(it, node) == true) {
                ++ ans;
            }
        }
    }
    return ans / 2;
}

istream& operator >> (istream& f, directedGraph &G) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        G.addNode(i);
    }

    for (int i = 1; i <= m; ++ i) {
        int x, y;
        cin >> x >> y;
        G.addEdge(x, y);
    }

    return f;
}

int main() {
    directedGraph G1, G2;
    cin >> G1 >> G2;

    G1.BFS(1);
    cout << '\n';
    memset (c, 0, sizeof (c));
    G1.DFS(1);
    cout << '\n' << G1.twoCycles() << '\n';

    G2.BFS(1);
    cout << '\n';
    memset (c, 0, sizeof (c));
    G2.DFS(1);
    cout << '\n' << G2.twoCycles() << '\n';

    return 0;
}
