#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double P, S;
	int k, i;

	//While
	S = 0;
	i = 1;
	while(i <= 10) {

		k = 1;
		P = 1;
		while (k <= i) {

			P *= k / i;
			k++;
		}

		S += (1 + P) / pow(i, 2);
		i++;
	}
	cout << S << endl;

	//Do while
	S = 0;
	i = 1;
	do {
		k = 1;
		P = 1;
		do {
			P *= k / i;
			k++;
		} while (k <= i);
		S += (1 + P) / pow(i, 2);
		i++;
	} while (i <= 10);
	cout << S << endl;

	//For(++)
	S = 0;
	for (i = 1; i <= 10; i++) {
		P = 1;
		for (k = 1; k <= i; k++) {
			P *= k / i;
		}
		S += (1 + P) / pow(i, 2);
	}
	cout << S << endl;

	//For(--)
	S = 0;
	for (i = 10; i >= 1; i--) {
		P = 1;
		for (k = i; k >= 1; k--) {
			P *= k / i;
		}
		S += (1 + P) / pow(i, 2);
	}
	cout << S << endl;
	return 0;
}