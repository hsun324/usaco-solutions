/*
ID: <ID HERE>
LANG: C++11
TASK: ride
*/

#include <fstream>
#include <string>

using namespace std;

int get_checksum(const string &word) {
	int value = 1;
	for (auto c : word)
		value *= c - 'A' + 1;
	return value % 47;
}

int main() {
    ifstream cin("ride.in");
    ofstream cout("ride.out");

    string comet, group;
    cin >> comet >> group;

	cout << (get_checksum(comet) == get_checksum(group) ? "GO" : "STAY") << endl;

    return 0;
}
