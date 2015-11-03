/*
ID: <ID HERE>
LANG: C++11
TASK: milk2
*/

#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
	ifstream cin("milk2.in");
	ofstream cout("milk2.out");

	int entry_count;
	cin >> entry_count;

	map<int, int> changes;
	for (int i = 0; i < entry_count; i++) {
		int start, end;
		cin >> start >> end;

		changes[start]++;
		changes[end]--;
	}

	int max_cont = 0, max_idle = 0;
	int last_zero = changes.begin()->first, start_zero = last_zero;
	int current_cows = 0;
	for (const auto &change : changes) {
		if (change.second != 0) {
			if (current_cows == 0) {
				last_zero = change.first;
				max_idle = max(max_idle, last_zero - start_zero);
			}

			current_cows += change.second;

			if (current_cows == 0) {
				start_zero = change.first;
				max_cont = max(max_cont, start_zero - last_zero);
			}
		}
	}

	cout << max_cont << ' ' << max_idle << endl;

	return 0;
}
