#include <fstream>
#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

int main() {
	ifstream fin("highcard.in");
	ofstream fout("highcard.out");

	int num_sing_cards;
	fin >> num_sing_cards;

	bitset<100000> cards;
	for (int i = 0; i < num_sing_cards; i++) {
		int card;
		fin >> card;
		cards[card - 1] = true;
		cout << "? " << card << endl;
	}

	int elsie = 0, score = 0;
	for (int i = 0; i < 2 * num_sing_cards; i++) {
		cout << "C " << i << ' ' << cards[i] << endl;
		if (cards[i]) {
			elsie++;
		} else if (elsie) {
			elsie--;
			score++;
		}
	}

	fout << score << endl;
}

