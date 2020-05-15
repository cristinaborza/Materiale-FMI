#include <bits/stdc++.h>

using namespace std;

const int Dim = 1e6 + 5;

int v[Dim], c[Dim];
int n, x, vmax, sz;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> x;
        ++ c[x];
        vmax = max (vmax, x);
    }

    for (int i = 0; i <= vmax; ++ i) {
        for (int j = 1; j <= c[i]; ++ j) {
            v[++sz] = i;
        }
    }

    for (int i = 1; i <= n; ++ i) {
        cout << v[i] << " ";
    }

    return 0;
}
