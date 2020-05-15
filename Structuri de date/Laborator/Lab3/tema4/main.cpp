#include <bits/stdc++.h>

using namespace std;

const int Dim = 1e5 + 5;

unsigned int v[Dim], aux[Dim], c[260], idx[260];
unsigned int n, mask = 255;

void radix (int p) {
    memset (c, 0, sizeof (c));
    for (int i = 1; i <= n; ++ i) {
        int pos = ((v[i] & mask) >> p);
        ++ c[pos];
    }

    idx[0] = 0;
    for (int i = 1; i <= 255; ++ i) {
        idx[i] = idx[i - 1] + c[i - 1];
    }

    for (int i = 1; i <= n; ++ i) {
        int pos = ((v[i] & mask) >> p);
        aux[++idx[pos]] = v[i];
    }

    for (int i = 1; i <= n; ++ i) {
        v[i] = aux[i];
    }

    mask = (mask << 8);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> v[i];
    }

    mask = 255;
    for (int i = 0; i < 32; i += 8) {
        radix (i);
    }

    for (int i = 1; i <= n; ++ i) {
        cout << v[i] << " ";
    }

    return 0;
}
