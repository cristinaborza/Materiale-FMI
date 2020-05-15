#include <bits/stdc++.h>

using namespace std;

//ifstream f ("input.txt");
//ofstream g ("output.txt");

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



int main() {
    push (1);
    cout << pop () << '\n';
    push (2);
    push (3);

    cout << pop () << '\n';
    cout << pop () << '\n';
    return 0;
}
