/**
ID: <ID HERE>
LANG: C++11
TASK: dualpal
*/

#include <sstream>
#include <fstream>
#include <algorithm>

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
	ifstream cin("dualpal.in");
	ofstream cout("dualpal.out");

	int required, start;
	cin >> required >> start;

	for (int i = start + 1, count = 0; count < required; i++) {
		for (int b = 2, n = 0; b <= 10; b++) {
			if (palindromic(rebase(i, b))) {
				if (n == 1) {
					cout << i << endl;
					count++;
					break;
				} else n = 1;
			}
		}
	}

	return 0;
}
