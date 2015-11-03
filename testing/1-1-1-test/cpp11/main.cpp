/*
ID: <ID HERE>
LANG: C++11
TASK: test
*/

#include <fstream>

using namespace std;

int main() {
	ifstream cin("test.in");
	ofstream cout("test.out");

	int a, b;
	cin >> a >> b;

	cout << a + b << endl;

    return 0;
}
