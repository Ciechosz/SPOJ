// DIJKSTRA
// 2014-12-13

#include <iostream>
#include <climits>
#include <functional>

#include <list>
#include <vector>

using namespace std;

struct polaczenie;

struct wierzcholek{
	int odleglosc;
	list<polaczenie> polaczenia;

	wierzcholek(){
		odleglosc = INT_MAX;
	}

	bool operator<(wierzcholek const& other){
		return odleglosc < other.odleglosc;
	}

	bool operator>(wierzcholek const& other){
		return odleglosc > other.odleglosc;
	}
};



struct polaczenie{
	int waga;
	wierzcholek* cel;

	polaczenie(int waga, wierzcholek* cel){
		this->waga = waga;
		this->cel = cel;
	}
};

class container{
public:
	std::vector<wierzcholek*> wierzcholki;

	wierzcholek* pop(){
		// find min
		if (wierzcholki.size()) {
			int min = wierzcholki[0]->odleglosc;
			wierzcholek* minWierzcholek = wierzcholki[0];
			vector<wierzcholek*>::iterator minIt = wierzcholki.begin();
			for (vector<wierzcholek*>::iterator it = wierzcholki.begin() + 1; it != wierzcholki.end(); ++it) {
				if ((*it)->odleglosc < min) {
					min = (*it)->odleglosc;
					minWierzcholek = *it;
					minIt = it;
				}
			}
			wierzcholki.erase(minIt);
			return minWierzcholek;
		} else {
			return 0;
		}
	}

	void push(wierzcholek* w){
		wierzcholki.push_back(w);
	}

	bool empty(){
		return wierzcholki.empty();
	}
};

int main(){
	std::ios_base::sync_with_stdio(0);

	int tests;
	cin >> tests;
	while (tests--) {
		int liczbaWierzcholkow, liczbaKrawedzi;
		cin >> liczbaWierzcholkow >> liczbaKrawedzi;

		wierzcholek* wierzcholki = new wierzcholek[liczbaWierzcholkow + 1];
		
		for (int i = 1; i <= liczbaKrawedzi; ++i) {
			int poczatek, koniec, waga;
			cin >> poczatek >> koniec >> waga;
			wierzcholki[poczatek].polaczenia.push_back(polaczenie(waga, &wierzcholki[koniec]));
			
		}

		container wierzcholki_queue;
		for (int i = 1; i <= liczbaWierzcholkow; ++i) {
			wierzcholki_queue.push(&wierzcholki[i]);
		}

		int start, koniec;
		cin >> start >> koniec;
		wierzcholki[start].odleglosc = 0;

		bool zaczete = false;

		while (!wierzcholki_queue.empty()) {
			wierzcholek* current;
			if (!zaczete) {
				current = &wierzcholki[start];
				zaczete = true;
			} else {
				current = wierzcholki_queue.pop(); 
			}

			for (list<polaczenie>::iterator it = current->polaczenia.begin(); it != current->polaczenia.end(); ++it) {
				if (current->odleglosc + (*it).waga < (*it).cel->odleglosc) {
					(*it).cel->odleglosc = current->odleglosc + (*it).waga;
				}
			}
		}

		if (wierzcholki[koniec].odleglosc == INT_MAX) {
			cout << "NIE" << endl;
		} else {
			cout << wierzcholki[koniec].odleglosc << endl;
		}

		delete[] wierzcholki;
	}

	return 0;
}
