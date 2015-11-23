/*
ID: <ID HERE>
LANG: C++11
TASK: beads
*/

#include <fstream>
#include <string>

using namespace std;

template <typename iterator>
int get_stretch(iterator begin, iterator end) {
	auto iter = begin;
	auto current_type = *iter;
	while (iter++ != end) {
		if (*iter == 'w') continue;
		if (current_type == 'w') current_type = *iter;
		if (current_type != *iter) break;
	}
	return iter - begin;
}

int main() {
	ifstream cin("beads.in");
	ofstream cout("beads.out");

	int necklace_length;
	cin >> necklace_length;
	cin.ignore(1);

	string necklace;
	necklace.reserve(necklace_length * 2);
	cin >> necklace;
	necklace += necklace;

	int max_length = 0;

	auto iter = necklace.begin(), end = necklace.end();
	auto riter = necklace.rend(), rend = necklace.rend();
	while (iter != end)
		max_length = max(max_length, get_stretch(riter--, rend) + get_stretch(iter++, end));

	cout << min(max_length, necklace_length) << endl;

	return 0;
}
