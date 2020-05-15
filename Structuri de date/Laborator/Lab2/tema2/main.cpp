#include <bits/stdc++.h>

using namespace std;

struct coada {
    int info;
    coada *prev, *next;

    coada () {
        info = 0;
        prev = NULL; next = NULL;
    }
}*global_local_prim_element, *global_local_ultim_element;

void push_left (int val) {
    if (global_local_prim_element != NULL) {
        coada *newElem = new coada;

        global_local_prim_element -> prev = newElem;

        newElem -> info = val;
        newElem -> next = global_local_prim_element;
        newElem -> prev = NULL;

        global_local_prim_element = newElem;
    }

    else {
        global_local_prim_element = new coada;
        global_local_prim_element -> info = val;

        global_local_ultim_element = new coada;
        global_local_ultim_element -> info = val;
    }
}

void push_right (int val) {
    if (global_local_ultim_element != NULL) {
        coada *newElem = new coada;

        global_local_ultim_element -> next = newElem;

        newElem -> info = val;
        newElem -> prev = global_local_ultim_element;
        newElem -> prev = NULL;

        global_local_ultim_element = newElem;
    }

    else {
        global_local_prim_element = new coada;
        global_local_prim_element -> info = val;

        global_local_ultim_element = new coada;
        global_local_ultim_element -> info = val;
    }
}

int pop_left () {
    coada *aux = global_local_prim_element;
    int ans = -1;
    if (global_local_prim_element != NULL) {
        ans = global_local_prim_element -> info;
        global_local_prim_element = global_local_prim_element -> next;
        delete aux;
    }

    return ans;
}


int pop_right () {
    coada *aux = global_local_ultim_element;
    int ans = -1;
    if (global_local_prim_element != NULL) {
        ans = global_local_ultim_element -> info;
        global_local_ultim_element = global_local_ultim_element -> next;
        delete aux;
    }

    return ans;
}

int main() {
    push_left (1);
    push_right (2);
    cout << pop_right () << '\n';
    cout << pop_left () << '\n';
    push_right(3);
    cout << pop_left() << '\n';
    return 0;
}
