/*
ID: <ID HERE>
LANG: C++11
TASK: lamps
*/
#include <array>
#include <cstdint>
#include <fstream>
#include <istream>
#include <set>
#include <utility>

using namespace std;

const array<pair<uint64_t, uint64_t>, 8> results = {{
	{0x0000000000000000ULL, 0x0000000000000000ULL},
	{0x38E38E38E38E38E3ULL, 0x8E38E38E38E38E38ULL},
	{0x5555555555555555ULL, 0x5555555555555555ULL},
	{0x6DB6DB6DB6DB6DB6ULL, 0xDB6DB6DB6DB6DB6DULL},
	{0x9249249249249249ULL, 0x2492492492492492ULL},
	{0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL},
	{0xC71C71C71C71C71CULL, 0x71C71C71C71C71C7ULL},
	{0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFFULL}
}};
const array<int, 8> required = {{1, 2, 1, 1, 2, 1, 2, 0}};
const array<int, 8> except = {{0, 0, 0, 2, 0, 0, 0, 1}};

pair<uint64_t, uint64_t> read_requirement(istream &in) {
	pair<uint64_t, uint64_t> result;

	int temp;
	while ((in >> temp) && temp >= 0) {
		if (temp <= 64) result.first |= 1ULL << (64 - temp);
		else result.second |= 1ULL << (128 - temp);
	}

	return result;
}

int main() {
	ifstream cin("lamps.in");
	ofstream cout("lamps.out");

	int num_lamps, counter;
	cin >> num_lamps >> counter;

	auto required_on = read_requirement(cin);
	auto required_off = read_requirement(cin);

	set<pair<uint64_t, uint64_t>> passing_results;
	for (int i = 0; i < 8; i++) {
		if (required[i] <= counter && except[i] != counter &&
			(results[i].first & required_on.first) == required_on.first &&
			(results[i].second & required_on.second) == required_on.second &&
			(results[i].first & required_off.first) == 0 &&
			(results[i].second & required_off.second) == 0) {
			passing_results.insert(results[i]);
		}
	}

	if (passing_results.empty())
		cout << "IMPOSSIBLE" << endl;
	for (const auto result : passing_results) {
		for (int i = 0; i < num_lamps; i++) {
			if (i < 64) cout << ((result.first >> (63 - i)) % 2);
			else cout << ((result.second >> (127 - i)) % 2);
		}
		cout << endl;
	}

	return 0;
}
