#include <fstream>
#include <set>

using namespace std;

int main() {
	ifstream cin("combo.in");
	ofstream cout("combo.out");

	int size;
	cin >> size;

	set<int> options;
	for (int i = 0; i < 2; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		// creates permutations of allowable combinations and turns them into
		// an integer so that set can compare them and only retain uniques

		// the indexes here start at -3 and end at +1 because the input starts
		// at 1 but here we want it to start at 0
		for (int i = a - 3; i <= a + 1; i++) {
			for (int j = b - 3; j <= b + 1; j++) {
				for (int k = c - 3; k <= c + 1; k++) {
					options.insert(((((i % size) + size) % size) << 0) +
								   ((((j % size) + size) % size) << 8) +
								   ((((k % size) + size) % size) << 16));
				}
			}
		}
	}

	// the size of the set is the number of unique combinations
	cout << options.size() << endl;

	return 0;
}

