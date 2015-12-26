/*
ID: <ID HERE>
LANG: C++11
TASK: subset
*/
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream cin("subset.in");
	ofstream cout("subset.out");

	int max;
	cin >> max;

	int set_sum = max * (max + 1) / 2;
	if (set_sum % 2 == 0) {
		int desired = set_sum / 2;
		vector<unsigned int> numbers(desired + 1);

		numbers[0] = 1;
		for (int i = 0; i < max; i++)
			for (int j = desired - i; j >= 0; j--)
				numbers[j + i] += numbers[j];

		cout << numbers[desired] / 2 << endl;
	} else {
		cout << '0' << endl;
	}

	return 0;
}
