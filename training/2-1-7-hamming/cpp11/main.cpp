/*
ID: <ID HERE>
LANG: C++11
TASK: hamming
*/
#include <fstream>
#include <vector>

using namespace std;

int get_hamming_distance(int left, int right) {
	int dist = 0;
	for (int i = 0; i < 32; i++)
		if (((left ^ right) & (1 << i)) != 0)
			dist++;
	return dist;
}
bool is_sufficient(const vector<int> &list, int comp, int req) {
	for (int i : list)
		if (get_hamming_distance(i, comp) < req)
			return false;
	return true;
}

int main() {
	ifstream cin("hamming.in");
	ofstream cout("hamming.out");

	int required, length, distance;
	cin >> required >> length >> distance;

	vector<int> found;
	found.reserve(required);

	for (int i = 0; found.size() < required; i++)
		if(is_sufficient(found, i, distance))
			found.push_back(i);

	for (int i = 0; i < required; i += 10) {
		cout << found[i];
		for (int j = i + 1; j < i + 10 && j < required; j++)
			cout << ' ' << found[j];
		cout << endl;
	}

	return 0;
}
