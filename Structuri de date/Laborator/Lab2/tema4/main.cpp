#include <bits/stdc++.h>

using namespace std;

ifstream f ("input.txt");
ofstream g ("output.txt");

const int Dim = 1e5 + 5;

int w[Dim], p[Dim], mat[505][505];
int m, nr;

int findTata (int x) {
    int cx = x;
    while (p[x] != x) {
        x = p[x];
    }

    while (cx != x) {
        int aux = p[cx];
        p[cx] = x;
        cx = aux;
    }

    return x;
}
void uneste (int x, int y) {
    int tx = findTata(x), ty = findTata(y);
    if (w[tx] < w[ty]) {
        p[tx] = ty;
        w[ty] += w[tx];
    }

    else {
        p[ty] = tx;
        w[tx] += w[ty];
    }
}


int main() {
    f >> m;
    for (int i = 1; i <= m; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            f >> mat[i][j];
            if (mat[i][j] == 1)
                mat[i][j] = ++nr;
        }
    }

    for (int i = 1; i <= nr; ++ i) {
        p[i] = i;
        w[i] = 1;
    }

    for (int i = 1; i <= m; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            if (mat[i][j] != 0 && mat[i - 1][j] != 0) {
                uneste (mat[i][j], mat[i - 1][j]);
            }

            if (mat[i][j] != 0 && mat[i][j - 1] != 0) {
                uneste (mat[i][j], mat[i][j - 1]);
            }
        }
    }

    for (int i = 1; i <= m; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            if (mat[i][j] != 0) mat[i][j] = p[mat[i][j]];
            g << mat[i][j] << " ";
        }

        g << '\n';
    }

    return 0;
}
