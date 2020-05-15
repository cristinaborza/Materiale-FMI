#include <bits/stdc++.h>

using namespace std;

const int Dim = 1e5 + 5;
const int Inf = 1e9 + 5;

int sf, n, x, type;
int hp[Dim], v[Dim];

void heapUp (int pos) {
    while (hp[pos] < hp[pos / 2] && pos > 1) {
        swap (hp[pos], hp[pos / 2]);
        pos /= 2;
    }
}
void insertHeap (int x) {
    hp[++sf] = x;
    heapUp (sf);
}
void heapDown (int pos) {
    while ((hp[pos] > hp[2 * pos] && 2 * pos <= sf) || (hp[pos] > hp[2 * pos + 1] && 2 * pos + 1 <= sf)) {
        if (2 * pos > sf) hp[2 * pos] = Inf;
        if (2 * pos + 1 > sf) hp[2 * pos + 1] = Inf;
        if (hp[2 * pos] == min(hp[2 * pos], hp[2 * pos + 1])) {
            swap (hp[pos], hp[2 * pos]); pos = 2 * pos;
        }
        else {
            swap (hp[pos], hp[2 * pos + 1]); pos = 2 * pos + 1;
        }
    }
}
int deleteHeap () {
    int ans = hp[1];
    hp[1] = hp[sf--];
    heapDown (1);
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> x;
        insertHeap(x);
    }

    for (int i = 1; i <= n; ++ i) {
        v[i] = deleteHeap();
    }

    for (int i = 1; i <= n; ++ i) {
        cout << v[i] << " ";
    }

    return 0;
}
