/*


1. daca exista tranzitii care intrea in starea initial,a se aduga o noua stare initiala
2. daca exista tranzitii care ies din starea finala, se adauga o noua stare finala
3. se elimina succesciv starile automatului



*/

#include <bits/stdc++.h>

using namespace std;


class DFA {
	set <int> Q, F;
	set <char> Sigma;
	int q0;
	map <pair <int, char>, int> delta;

public:
	DFA () { this -> q0 = 0; }
	DFA (set <int> Q, set <char> Sigma, map <pair <int, char>, int> delta, int q0, set <int> F) {
		this -> Q = Q;
		this -> Sigma = Sigma;
		this -> delta = delta;
		this -> q0 = q0;
		this -> F = F;
	}

	friend ostream& operator << (ostream& g, DFA&);

	bool isFinalState(int);
	//int deltaStar(int, string);
};

class NFA {
	set <int> Q, F;
	set <char> Sigma;
	set <int> q0;
	map <pair <int, char>, set <int> > delta;

public:
	NFA() { this -> q0 = {0}; }
	NFA(set <int> Q, set <char> Sigma, map <pair <int, char>, set <int> > delta, set<int> q0, set <int> F) {
		this -> Q = Q;
		this -> Sigma = Sigma;
		this -> delta = delta;
		this -> q0 = q0;
		this -> F = F;
	}

	friend istream& operator >> (istream&, NFA&);
	friend nfaToDfa (DFA);
	bool isFinalState (set <int>);
	//set <int> deltaStar (set <int>, string);
};

bool DFA::isFinalState (int q) {
	return F.find(q) != F.end();
}

bool NFA::isFinalState(set <int> q) {
    for (auto it: q) {
        if (F.find(it) != F.end()) {
            return true;
        }
    }

    return false;
}

istream& operator >> (istream& f, NFA& M) {
	int noOfStates;
	f >> noOfStates;
	for (int i = 0; i < noOfStates; ++i) {
		int q;
		f >> q;
		M.Q.insert(q);
	}

	int noOfLetters;
	f >> noOfLetters;
	for (int i = 0; i < noOfLetters; ++i) {
		char ch;
		f >> ch;
		M.Sigma.insert(ch);
	}

	int noOfTransitions;
	f >> noOfTransitions;
	for (int i = 0; i < noOfTransitions; ++i) {
		int s, d, nr;
		char ch;

		set <int> aux;
		f >> s >> ch >> nr;
		for (int j = 1; j <= nr; ++ j) {
            f >> d;
            aux.insert (d);
		}

		M.delta[{s, ch}] = aux;
	}

	int aux;
	f >> aux;
	M.q0 = {aux};

	int noOfFinalStates;
	f >> noOfFinalStates;
	for (int i = 0; i < noOfFinalStates; ++i) {
		int q;
		f >> q;
		M.F.insert(q);
	}

	return f;
}

ostream& operator << (ostream& g, DFA& N) {
    g << N.delta.size() << '\n';
    for (auto it: N.delta) {
        g << it.first.first << " " << it.first.second << " " << it.second << '\n';
    }

    return g;

}

DFA nfaToDfa (NFA M) {
    queue <set <int> > coada;
    coada.push (M.q0);
    while (!coada.empty()) {
        set <int> StareCurenta;
        set <int> aux;
        for (auto lit: M.Sigma) {
            for (auto stare: StareCurenta) {
                aux = reunion (aux, M.delta[{stare, ])
            }
        }
    }
}

int main() {
    NFA M;
    ifstream f ("nfa-dfa.txt");

    f >> M;
    f.close();

    DFA N = nfaToDfa (M);
    cout << N << '\n';
    return 0;
}
