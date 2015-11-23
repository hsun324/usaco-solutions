/*
ID: <ID HERE>
LANG: C++11
TASK: milk
*/

#include <fstream>
#include <map>

using namespace std;

int main() {
	ifstream cin("milk.in");
	ofstream cout("milk.out");

	int required, num_sellers;
	cin >> required >> num_sellers;

	map<int, int> sellers;
	for (int i = 0; i < num_sellers; i++) {
		int price, amount;
		cin >> price >> amount;
		sellers[price] += amount;
	}

	int cost = 0;
	for (auto &seller : sellers) {
		int amount = min(seller.second, required);
		cost += amount * seller.first;
		required -= amount;
	}

	cout << cost << endl;

	return 0;
}
