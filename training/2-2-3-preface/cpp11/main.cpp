/*
ID: <ID HERE>
LANG: C++11
TASK: preface
*/
#include <fstream>

using namespace std;

char nameLookup[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

int main() {
	ifstream cin("preface.in");
	ofstream cout("preface.out");

	int max;
	cin >> max;

	array<int, 16> totals{};
	for (int i = 1; i <= max; i++) {
		for (int j = 0, k = i; j < 7; j += 2, k /= 10) {
			totals[j] += k % 5 ? ((((k % 5) - 1) % 3) + 1) : 0;
			totals[j + 1] += (k % 10) % 9 > 3;
			totals[j + 2] += k % 10 == 9;
		}
	}

	for (int i = 0; i < 7; i++)
		if (totals[i] > 0)
			cout << nameLookup[i] << ' ' << totals[i] << endl;

	return 0;
}
