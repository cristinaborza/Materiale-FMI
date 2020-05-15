//tema 4.2

#include <bits/stdc++.h>

using namespace std;

ifstream f ("input.txt");
ofstream g ("output.txt");

struct Node {
    string s;
    Node *leftNode, *rightNode;

    Node () {
        s = "";
        leftNode = NULL; rightNode = NULL;
    }

    Node (string x, Node *st, Node *dr) {
        s = x;
        leftNode = st;
        rightNode = dr;
    }

    ~Node () {
        delete leftNode;
        delete rightNode;
    }
};

string findMin (Node *root) {
    if (root -> leftNode != NULL)
        return findMin(root -> leftNode);
    return root -> s;
}

int comp (string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    for (int i = 0; i < min (n, m); ++ i) {
        if (s1[i] < s2[i]) {
            return -1;
        }

        if (s1[i] > s2[i]) {
            return 1;
        }
    }

    if (n < m)
        return -1;
    if (n > m)
        return 1;
    return 0;
}

Node* insertValue (Node* root, string s) {
    if (root == NULL) {
        Node *temp = new Node(s, NULL, NULL);
        return temp;
    }

    if (comp (s, root -> s) < 0) {
        Node *temp = new Node();
        temp -> s = root -> s;
        temp -> rightNode = root -> rightNode;
        temp -> leftNode = insertValue (root -> leftNode, s);
        return temp;
    }


    Node *temp = new Node();
    temp -> s = root -> s;
    temp -> leftNode = root -> leftNode;
    temp -> rightNode = insertValue (root -> rightNode, s);
    return temp;
}

void inordine (Node *root) {
    if (root == NULL) return;
    inordine (root -> leftNode);
    g << root -> s << " ";
    inordine (root -> rightNode);
}

int main() {
    Node *root = NULL;
    int n; f >> n;
    for (int i = 1; i <= n; ++ i) {
        string cuv; f >> cuv;
        root = insertValue (root, cuv);
    }

    inordine (root);
    return 0;
}
