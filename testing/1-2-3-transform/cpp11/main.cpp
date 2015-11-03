/*
ID: <ID HERE>
LANG: C++11
TASK: transform
*/

#include <fstream>
#include <vector>

using namespace std;

template <typename t>
class grid {
private:
	vector<vector<t>> elements;
public:
	grid(int size) : elements(size, vector<t>(size)) {}

	t get(const int x, const int y) const {
		return elements[x][y];
	}
	void set(const int x, const int y, const t &value) {
		elements[x][y] = value;
	}
	int size() const {
		return elements.size();
	}
	grid rotate90() const {
		grid result{size()};

		for (int i = 0; i < size(); i++)
			for (int j = 0; j < size(); j++)
				result.set(size() - j - 1, i, get(i, j));

		return result;
	}
	grid rotate180() const {
		grid result{size()};

		for (int i = 0; i < size(); i++)
			for (int j = 0; j < size(); j++)
				result.set(size() - i - 1, size() - j - 1, get(i, j));

		return result;
	}
	grid rotate270() const {
		grid result{size()};

		for (int i = 0; i < size(); i++)
			for (int j = 0; j < size(); j++)
				result.set(j, size() - i - 1, get(i, j));

		return result;
	}
	grid mirror() const {
		grid result{size()};

		for (int i = 0; i < size(); i++)
			for (int j = 0; j < size(); j++)
				result.set(i, size() - j - 1, get(i, j));

		return result;
	}

	bool operator== (const grid<t> &other) const {
		return elements == other.elements;
	}
};

int main() {
	ifstream cin("transform.in");
	ofstream cout("transform.out");

	int grid_size;
	cin >> grid_size;

	grid<bool> original{grid_size};
	grid<bool> transformed{grid_size};

	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			char c;
			cin >> c;
			original.set(i, j, c == '@');
		}
		cin.ignore(1);
	}

	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			char c;
			cin >> c;
			transformed.set(i, j, c == '@');
		}
		cin.ignore(1);
	}

	auto rot90 = original.rotate90();
	auto rot180 = original.rotate180();
	auto rot270 = original.rotate270();
	auto mirror = original.mirror();
	auto rotm90 = mirror.rotate90();
	auto rotm180 = mirror.rotate180();
	auto rotm270 = mirror.rotate270();

	if (transformed == rot90) cout << '1' << endl;
	else if (transformed == rot180) cout << '2' << endl;
	else if (transformed == rot270) cout << '3' << endl;
	else if (transformed == mirror) cout << '4' << endl;
	else if (transformed == rotm90) cout << '5' << endl;
	else if (transformed == rotm180) cout << '5' << endl;
	else if (transformed == rotm270) cout << '5' << endl;
	else if (transformed == original) cout << '6' << endl;
	else cout << '7' << endl;

	return 0;
}
