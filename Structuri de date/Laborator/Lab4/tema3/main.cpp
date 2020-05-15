//tema 4.3

#include <bits/stdc++.h>

using namespace std;

ifstream f ("input.txt");
ofstream g ("output.txt");

struct Node {
    int value;
    Node *leftNode, *rightNode;

    Node () {
        value = 0;
        leftNode = NULL; rightNode = NULL;
    }

    Node (int x, Node *st, Node *dr) {
        value = x;
        leftNode = st;
        rightNode = dr;
    }

    ~Node () {
        delete leftNode;
        delete rightNode;
    }
};

Node* insertValue (Node* root, int value) {
    if (root == NULL) {
        Node *temp = new Node(value, NULL, NULL);
        return temp;
    }

    if (value < root -> value) {
        Node *temp = new Node();
        temp -> value = root -> value;
        temp -> rightNode = root -> rightNode;
        temp -> leftNode = insertValue (root -> leftNode, value);
        return temp;
    }


    Node *temp = new Node();
    temp -> value = root -> value;
    temp -> leftNode = root -> leftNode;
    temp -> rightNode = insertValue (root -> rightNode, value);
    return temp;
}

void dfs (Node *root, int st, int dr) {
    if (root == NULL) {
        return;
    }

    if (root -> leftNode != NULL) {
        if (root -> value >= st)
            dfs (root -> leftNode, st, dr);
    }

    if (st < root -> value && root -> value < dr) {
        g << root -> value << " ";
    }

    if (root -> rightNode != NULL) {
        if (root -> value <= dr)
            dfs (root -> rightNode, st, dr);
    }
}

int main() {
    Node *root = NULL;

    int n; f >> n;
    for (int i = 1; i <= n; ++ i) {
        int x; f >> x;
        root = insertValue (root, x);
    }

    int st, dr;
    f >> st >> dr;
    dfs (root, st, dr);
    return 0;
}
