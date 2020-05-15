#include <bits/stdc++.h>

using namespace std;

ifstream f ("input.txt");
ofstream g ("output.txt");

const int Dim = 1e6 + 5;

struct stiva {
    int info;
    stiva *next;

    stiva() {
        info = 0;
        next = NULL;
    }

} *pointer_global_element_varf;

void push (int val) {
    stiva *NewElem = new stiva;
    NewElem -> info = val;
    NewElem -> next = pointer_global_element_varf;
    pointer_global_element_varf = NewElem;
}

int pop () {
    stiva *nxt = pointer_global_element_varf;
    int ans = -1;
    if (pointer_global_element_varf != NULL) {
        ans = pointer_global_element_varf -> info;
        pointer_global_element_varf = pointer_global_element_varf -> next;
        delete nxt;
    }

    return ans;
}

bitset <Dim> c;


int main() {
    int n;
    f >> n;
    for (int i = 1; i <= n; ++ i) {
        int x; f >> x;
        if (c[x] == 0) {
            push (x);
            c[x] = 1;
        }
        else {
            if (pop () != x) {
                g << "Configuratie invalida!\n";
                return 0;
            }
        }
    }

    g << "Configuratie valida!\n";
    return 0;
}
