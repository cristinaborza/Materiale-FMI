#include <bits/stdc++.h>

using namespace std;

ifstream f ("input.txt");
ofstream g ("output.txt");

double A[50][50];
int n, m;
const double Eps = 1e-6;

void Read () {
    f >> n >> m; // n ecuatii, m necunoscute
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) f >> A[i][j];
    }
}

void getCofactor(double mat[50][50], double temp[50][50], int p, int q, int n) {
    int i = 1, j = 1;
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j > n - 1) {
                    j = 1;
                    i ++;
                }
            }
        }
    }
}

double FindDeterminant(double mat[50][50], int n){
    double ans = 0;
    if (n == 1)
        return mat[1][1];

    double aux[50][50];
    double sign = 1;

    for (int i = 1; i <= n; i++) {
        getCofactor(mat, aux, 1, i, n);
        ans += sign * mat[1][i] * FindDeterminant(aux, n - 1);
        sign = -sign;
    }

    return ans;
}

bool Verif (int mask, int n, int r) {
    int nrb = 0;
    for (int i = 0; i < n; ++ i) {
        if ((mask & (1 << i)) != 0) ++ nrb;
        if (nrb > r) break;
    }

    if (nrb != r) return false;
    return true;
}

bool Check (double mat[50][50], int n, int m, int r) {
    for (int mask1 = 0; mask1 < (1 << n); ++ mask1) {
        if (Verif (mask1, n, r) == false) continue;
        for (int mask2 = 0; mask2 < (1 << m); ++ mask2) {
            if (Verif(mask2, m, r) == false) continue;

            double aux[50][50];
            int lin = 1, col = 1;
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < m; ++ j) {
                    if (((mask1 & (1 << i)) != 0) && ((mask2 & (1 << j)) != 0)) {
                        aux[lin][col] = mat[i + 1][j + 1];
                        ++ col;
                        if (col > r) {
                            col = 1;
                            ++ lin;
                        }
                    }
                }
            }

            double det = FindDeterminant (aux, r);
            if (det < -Eps || det > Eps) {
                return true;
            }
        }
    }

    return false;
}

int FindRank (double mat[50][50], int n, int m) {
    int Rmax = min (n, m);
    for (int i = Rmax; i >= 1; -- i) {
        if (Check (mat, n, m, i) == true) {
            return i;
        }
    }

    return 0;
}

pair <int, int> FindMinor (double mat[50][50], int n, int m, int r) {
    for (int mask1 = 0; mask1 < (1 << n); ++ mask1) {
        if (Verif (mask1, n, r) == false) continue;
        for (int mask2 = 0; mask2 < (1 << m); ++ mask2) {
            if (Verif(mask2, m, r) == false) continue;

            double aux[50][50];
            int lin = 1, col = 1;
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < m; ++ j) {
                    if (((mask1 & (1 << i)) != 0) && ((mask2 & (1 << j)) != 0)) {
                        aux[lin][col] = mat[i + 1][j + 1];
                        ++ col;
                        if (col > r) {
                            col = 1;
                            ++ lin;
                        }
                    }
                }
            }

            double det = FindDeterminant (aux, r);
            if (det < -Eps || det > Eps) {
                return {mask1, mask2};
            }
        }
    }
}

void swap_vectori (vector <double> &a, vector <double> &b) {
    int sz = a.size();
    double aux[sz];

    for (int i = 0; i < sz; ++ i) {
        aux[i] = a[i];
        a[i] = b[i];
        b[i] = aux[i];
    }
}

void Gauss (pair <int, int> mask, int r) {
    double mat[50][50];
    vector <double> B[50];
    int lin = 0, col = 1;

    for (int i = 0; i < n; ++ i) {
        if ((mask.first & (1 << i)) == 0) continue;
        ++ lin; col = 1;
        for (int j = 0; j < m; ++ j) {
            if (((mask.first & (1 << i)) != 0) && ((mask.second & (1 << j)) != 0)) mat[lin][col++] = (double)A[i + 1][j + 1];
            else B[lin].push_back (-(double)A[i + 1][j + 1]);
        }
    }

    lin = 1, col = 1;
    while (lin <= r && col <= r) {
        bool ok = false;
        int pos = 0;

        for (int i = lin; i <= r; ++ i) {
            if (mat[i][col] < -Eps || mat[i][col] > Eps) {
                ok = true;
                pos = i;
                break;
            }
        }

        if (!ok) {
            ++ col;
            continue;
        }

        if (pos != lin) {
            for (int i = 1; i <= r; ++ i) {
                swap (mat[lin][i], mat[pos][i]);
            }

            swap_vectori (B[lin], B[pos]);
        }

        for (int i = col + 1; i <= r; ++ i) {
            mat[lin][i] /= mat[lin][col];
        }

        for (int i = 0; i < B[lin].size(); ++ i) {
            B[lin][i] /= mat[lin][col];
        }
        mat[lin][col] = 1;

        for (int i = lin + 1; i <= r; ++ i) {
            for (int j = col + 1; j <= r; ++ j) {
                mat[i][j] -= mat[i][col] * mat[lin][j];
            }

            for (int j = 0; j < B[i].size(); ++ j) {
                B[i][j] -= mat[i][col] * B[lin][j];
            }

            mat[i][col] = 0;
        }

        ++ lin, ++ col;
    }

    vector <double> ans[50];
    for (int i = r; i >= 1; -- i) {
        for (int j = 1; j <= r; ++ j) {
            if (mat[i][j] < -Eps || mat[i][j] > Eps) {
                for (int l = 0; l < B[i].size(); ++ l) {
                    ans[j].push_back (B[i][l]);
                }
                for (int k = j + 1; k <= r; ++ k) {
                    for (int l = 0; l < ans[j].size(); ++ l)
                        ans[j][l] -= mat[i][k] * ans[k][l];
                }

                break;
            }
        }
    }

    for (int i = r + 1; i <= m; ++ i) {
        for (int j = r + 1; j < i; ++ j) {
            ans[i].push_back (0);
        }
        ans[i].push_back (1);
        for (int j = i + 1; j <= m; ++ j) {
            ans[i].push_back (0);
        }
    }

    vector <double> sol[50];
    for (int i = 0; i < m - r; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            sol[i].push_back (ans[j][i]);
        }
    }

    for (int i = 0; i < m - r; ++ i) {
        g << "(";
        for (int j = 0; j < sol[i].size(); ++ j) {
            g << sol[i][j];
            if (j != sol[i].size() - 1) g << ", ";
        }

        g << ")\n";
    }
}

void Solve () {
    double det = FindDeterminant (A, n);
    if (n == m && (det > Eps || det < -Eps)) {
        g << "Singur solutie este: (";
        for (int i = 1; i <= m; ++ i) {
            g << "0";
            if (i < m) g << ", ";
        }

        g << ")\n";
        exit (0);
    }

    int r = FindRank (A, n, m);
    if (n > m && r == m) {
        g << "Singur solutie este: (";
        for (int i = 1; i <= m; ++ i) {
            g << "0";
            if (i < m) g << ", ";
        }

        g << ")\n";
        exit (0);
    }

    pair <int, int> aux = FindMinor (A, n, m, r);
    Gauss (aux, r);
}

int main() {
    Read ();
    Solve ();
    return 0;
}
