/*
ID: <ID HERE>
LANG: C++11
TASK: milk3
*/
#include <array>
#include <fstream>
#include <set>

using namespace std;

int hash_state(const array<int, 3> &state) {
	return (state[0] << 0) + (state[1] << 5) + (state[2] << 10);
}

void recurse_search_no_repeat(set<int> &results, array<bool, 32768> &visited_states, const array<int, 3> &state, const array<int, 3> &sizes) {
	if (state[0] == 0)
		results.insert(state[2]);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) {
				array<int, 3> new_state(state);
				int to_move = min(state[i], sizes[j] - state[j]);

				if (to_move == 0) continue;

				new_state[j] += to_move;
				new_state[i] -= to_move;

				int new_state_hash = hash_state(new_state);
				if (!visited_states[new_state_hash]) {
					visited_states[new_state_hash] = true;

					recurse_search_no_repeat(results, visited_states, new_state, sizes);
				}
			}
		}
	}
}

set<int> recurse_search(array<int, 3> &sizes) {
	set<int> results;
	array<bool, 32768> visited_states{};
	array<int, 3> start_state{0, 0, sizes[2]};

	visited_states[hash_state(start_state)] = true;

	recurse_search_no_repeat(results, visited_states, start_state, sizes);
	return results;
}

int main() {
	ifstream cin("milk3.in");
	ofstream cout("milk3.out");

	array<int, 3> sizes;
	for (auto &size : sizes) cin >> size;

	auto results = recurse_search(sizes);

	cout << *results.begin();
	for (auto iter = ++results.begin(); iter != results.end(); ++iter)
		cout << ' ' << *iter;
	cout << endl;

	return 0;
}
