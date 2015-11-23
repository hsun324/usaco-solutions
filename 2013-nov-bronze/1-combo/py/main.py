import itertools

def read_combo(file):
	return [int(x) - 1 for x in file.readline().split()];

def permute(combo, size):
	return [[x % size for x in permutation] for permutation in itertools.product(*[range(v - 2, v + 3) for v in combo])]

fin = open('combo.in', 'r')
size = int(fin.readline())

fout = open('combo.out', 'w')
fout.write(str(len(set(map(tuple, permute(read_combo(fin), size) + permute(read_combo(fin), size))))) + '\n')
fout.close()

fin.close()
