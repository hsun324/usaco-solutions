/*
ID: <ID HERE>
LANG: C++11
TASK: palsquare
*/

#include <sstream>
#include <fstream>

using namespace std;

char rebase_char(int digit) {
	return digit + (digit < 10 ? '0' : 'A' - 10);
}
string rebase(int value, int base) {
	stringstream result;
	while (value > 0) {
		result << rebase_char(value % base);
		value /= base;
	}

	string reversed = result.str();
	return string(reversed.rbegin(), reversed.rend());
}

bool palindromic(const string &str) {
	return equal(str.begin(), str.begin() + (str.size() + 1) / 2, str.rbegin());
}

int main() {
	ifstream cin("palsquare.in");
	ofstream cout("palsquare.out");

	int base;
	cin >> base;

	for (int i = 1; i <= 300; i++) {
		string square_base = rebase(i * i, base);
		if (palindromic(square_base)) {
			cout << rebase(i, base) << ' ' << square_base << endl;
		}
	}

	return 0;
}
