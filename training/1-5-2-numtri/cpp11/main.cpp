/**
ID: <ID HERE>
LANG: C++11
TASK: numtri
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream cin("numtri.in");
	ofstream cout("numtri.out");

	int size;
	cin >> size;

	vector<vector<int>> triangle(size);
	for (int i = 0; i < size; i++) triangle[i].resize(i + 1);

	for (auto &row : triangle)
		for (auto &cell : row)
			cin >> cell;

	for (int i = size - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			triangle[i - 1][j] += max(triangle[i][j], triangle[i][j + 1]);

	cout << triangle[0][0] << endl;

	return 0;
}
