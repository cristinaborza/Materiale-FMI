//tema 4.1

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

bool findValue (Node *root, int value) {
    if (root -> value == value) {
        return true;
    }

    if (value < root -> value) {
        if (root -> leftNode == NULL) return false;
        return findValue (root -> leftNode, value);
    }

    if (root -> rightNode == NULL) return false;
    return findValue (root -> rightNode, value);
}

int findMin (Node *root) {
    if (root -> leftNode != NULL)
        return findMin(root -> leftNode);
    return root -> value;
}

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

Node* deleteNode (Node *root, int value) {
    if (root == NULL) {
        Node *temp = new Node();
        return temp;
    }

    if (value < root -> value) {
        Node *temp = new Node();
        temp = root;
        temp -> leftNode = deleteNode(root -> leftNode, value);
        return temp;
    }

    if (value > root -> value) {
        Node *temp = new Node();
        temp = root;
        temp -> rightNode = deleteNode(root -> rightNode, value);
        return temp;
    }

    if (root -> leftNode != NULL && root -> rightNode != NULL) {
        Node *temp = new Node();
        temp -> value = findMin(root -> rightNode);
        temp -> leftNode = root -> leftNode;
        temp -> rightNode = deleteNode (root -> rightNode, temp -> value);
        return temp;
    }

    if (root -> leftNode == NULL) {
        Node *temp = new Node();
        temp = root -> rightNode;
        return temp;
    }

    Node *temp = new Node();
    temp = root -> leftNode;
    return temp;
}

void inordine (Node *root) {
    if (root == NULL) return;
    inordine (root -> leftNode);
    g << root -> value << " ";
    inordine (root -> rightNode);
}

void preordine (Node *root) {
    if (root == NULL) return;
    g << root -> value << " ";
    preordine (root -> leftNode);
    preordine (root -> rightNode);
}

int main() {
    Node *root = NULL;
    int n; f >> n;
    for (int i = 1; i <= n; ++ i) {
        int x; f >> x;
        root = insertValue (root, x);
    }

    inordine (root);
    g << '\n';
    preordine (root);
    g << '\n';

    f >> n;
    for (int i = 1; i <= n; ++ i) {
        int x; f >> x;
        if (findValue(root, x) == true) g << "Exista valoarea " << x << '\n';
        else g << "Nu exista valoarea " << x << '\n';
    }

    f >> n;
    for (int i = 1; i <= n; ++ i) {
        int x; f >> x;
        if (findValue(root, x) == false) {
            g << "Nu exista valoarea " << x << '\n';
        }

        else {
            root = deleteNode(root, x);
            inordine (root);
            g << '\n';
            preordine (root);
            g << '\n';
        }
    }
    return 0;
}
