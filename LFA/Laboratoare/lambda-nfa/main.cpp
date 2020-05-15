#include <bits/stdc++.h>

using namespace std;

class LNFA {
	set <int> Q, F;
	set <char> Sigma;
	set <int> q0;
	map <pair <int, char>, set <int> > delta;

public:
	LNFA() { this -> q0 = {0}; }
	LNFA(set <int> Q, set <char> Sigma, map <pair <int, char>, set <int> > delta, set<int> q0, set <int> F) {
		this -> Q = Q;
		this -> Sigma = Sigma;
		this -> delta = delta;
		this -> q0 = q0;
		this -> F = F;
	}

	set <int> getInitialState() const { return this -> q0; }
	friend istream& operator >> (istream&, LNFA&);
	set <int> lambdaInchidere (int);
	bool isFinalState (set <int>);
	set <int> deltaStar (set <int>, string);
};

set <int> LNFA::lambdaInchidere (int q) {
    set <int> ans;

    queue <int> coada;
    coada.push(q);

    bool c[Q.size()];
    memset (c, 0, sizeof (c));

    while (!coada.empty()) {
        int node = coada.front();
        coada.pop();

        ans.insert (node);
        for (auto it: delta[{node, '.'}]) {
            if (c[it] == 0) {
                c[it] = 1;
                coada.push(it);
            }
        }
    }

    return ans;

}

bool LNFA::isFinalState(set <int> q) {
    for (auto it: q) {
        if (F.find(it) != F.end()) {
            return true;
        }
    }

    return false;
}

set <int> LNFA::deltaStar (set <int> s, string w) {
    int n = w.length();

    set <int> LocalFinalStates;
    for (auto i: s) {
        set <int> aux = lambdaInchidere(i);
        for (auto j: aux)
            LocalFinalStates.insert(j);
    }

    set <int> aux;
    for (auto i: LocalFinalStates) {
        for (auto j: delta[{i, w[0]}]) {
            aux.insert (j);
        }
    }

    LocalFinalStates.clear();
    for (auto it: aux) {
        LocalFinalStates.insert (it);
    }

    for (auto i: LocalFinalStates) {
        set <int> aux = lambdaInchidere(i);
        for (auto j: aux)
            LocalFinalStates.insert(j);
    }

    n--;
    if (n == 0) {
        return LocalFinalStates;
    }

    int contor = 0;
    while (n) {
        set <int> aux;
        for (int i: LocalFinalStates) {
            for (int j: delta[{i, w[contor + 1]}]) {
                aux.insert (j);
            }
        }

        n--;
        contor++;

        LocalFinalStates.clear();
        for (int i: aux) {
            LocalFinalStates.insert (i);
        }

        aux.clear();
        for (auto i: LocalFinalStates) {
            aux = lambdaInchidere(i);
            for (auto j: aux)
                LocalFinalStates.insert (j);
        }
    }

    return LocalFinalStates;
}

istream& operator >> (istream& f, LNFA& M) {
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

int main() {
	LNFA M;

	ifstream f("lnfa.txt");

	f >> M;
	f.close();

	set <int> lastState = M.deltaStar(M.getInitialState(), "a");

	if (M.isFinalState(lastState)) {
		cout << "Cuvant acceptat";
	}

	else {
		cout << "Cuvant respins";
	}

	return 0;
}
