#include <fstream>

using namespace std;

int main() {
	ifstream input("clumsy.in");
	
	string text;
	input >> text;

	int current = 0;
	int adjustment = 0;
	for (size_t i = 0, l = text.size(); i < l; i++) {
		if (text[i] == '(') {
			++current;
		} else if (current == 0) {
			++current;
			++adjustment;
		} else {
			--current;
		}
	}

	ofstream output("clumsy.out");
	output << (current / 2) + adjustment << endl;
}
