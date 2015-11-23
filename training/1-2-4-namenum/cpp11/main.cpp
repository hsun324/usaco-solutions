/*
ID: <ID HERE>
PROG: namenum
LANG: C++11
*/
#include <fstream>
#include <string>

using namespace std;

long long str_to_value(const string &str) {
	static int lookup[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, -1, 7, 7, 8, 8, 8, 9, 9, 9, -1};

	long long value = 0;
	for (auto c : str)
		value = value * 10 + lookup[c - 'A'];
	return value;
}



int main() {
	ifstream cin("namenum.in");
	ofstream cout("namenum.out");

	long long number;
	cin >> number;

	bool found = false;
	string name;
	ifstream fnames("dict.txt");
	while (fnames >> name) {
		if (str_to_value(name) == number) {
			cout << name << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "NONE" << endl;
	}

	return 0;
}
