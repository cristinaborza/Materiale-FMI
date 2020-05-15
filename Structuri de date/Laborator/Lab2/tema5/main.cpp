#include <bits/stdc++.h>

using namespace std;

const int Dim = 1e6 + 5;

int n, vf, elem, ap;
int v[Dim];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> v[i];
    }

    vf = 1;
    elem = v[1];

    for (int i = 2; i <= n; ++ i) {
        if (v[i] == elem) ++ vf;
        else  -- vf;

        if (vf < 0) {
            elem = v[i];
            vf = 1;
        }
    }

    for (int i = 1; i <= n; ++ i) {
        if (v[i] == elem) ++ ap;
    }

    if (ap > n / 2) cout << "Elementul majoritar este " << elem << '\n';
    else cout << "Nu exista element majoritar!\n";

    return 0;
}
