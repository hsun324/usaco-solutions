/*
ID: <ID HERE>
LANG: C++11
TASK: wormhole
*/
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

bool check_cycle(vector<int> &pairs, map<int, int> &transitions) {
	vector<bool> visited(pairs.size());

	for (int i = 0; i < pairs.size(); i++) {
		if (visited[i]) continue;

		int current = i;
		do {
			visited[current] = true;

			int exit = pairs[current], next = -1;
			auto transition = transitions.find(exit);
			if (transition != transitions.end())
				next = transition->second;

			if (next == i)
				break;

			current = next;
		} while (current >= 0);

		if (current >= 0) return true;
	}

	return false;
}

int construct_permutations_and_check(vector<int> &permutation, map<int, int> &transitions) {
	auto first_unassigned = find(permutation.begin(), permutation.end(), -1);
	if (first_unassigned == permutation.end())
		return check_cycle(permutation, transitions) ? 1 : 0;

	int count = 0;

	int unassigned_index = first_unassigned - permutation.begin();
	for (int i = unassigned_index + 1; i < permutation.size(); i++) {
		if (permutation[i] == -1) {
			vector<int> current(permutation);
			current[i] = unassigned_index;
			current[unassigned_index] = i;

			count += construct_permutations_and_check(current, transitions);
		}
	}

	return count;
}

int main() {
	ifstream cin("wormhole.in");
	ofstream cout("wormhole.out");

	int count;
	cin >> count;

	map<int, set<pair<int, int>>> wormholes;
	for (int i = 0, x, y; i < count; i++) {
		cin >> x >> y;
		wormholes[y].emplace(x, i);
	}

	map<int, int> transitions;
	for (auto &wormhole_set : wormholes) {
		int last_index = -1;
		for (auto &index : wormhole_set.second) {
			if (last_index >= 0) transitions[last_index] = index.second;
			last_index = index.second;
		}
	}

	vector<int> permutation(count, -1);
	int cycles = construct_permutations_and_check(permutation, transitions);

	cout << cycles << endl;

	return 0;
}
