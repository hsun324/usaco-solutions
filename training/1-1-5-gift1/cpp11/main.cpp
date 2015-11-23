/*
ID: <ID HERE>
LANG: C++11
TASK: gift1
*/

#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main() {
	ifstream cin("gift1.in");
	ofstream cout("gift1.out");

	int person_count;
	cin >> person_count;

	vector<string> names(person_count);
	for (int i = 0; i < person_count; i++)
		cin >> names[i];

	map<string, int> balances;
	for (int i = 0; i < person_count; i++) {
		string current_person;
		int total_amount, num_recipients;

		cin >> current_person >> total_amount >> num_recipients;

		if (num_recipients > 0) {
			int per_recipient = total_amount / num_recipients;
			balances[current_person] -= per_recipient * num_recipients;

			for (int j = 0; j < num_recipients; j++) {
				string recipient;
				cin >> recipient;
				balances[recipient] += per_recipient;
			}
		}
	}


	for (const auto &name : names)
		cout << name << " " << balances[name] << endl;

	return 0;
}
