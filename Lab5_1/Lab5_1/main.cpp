#include <iostream>
#include <cmath>

using namespace std;

double h(const double a, const double b);

int main()
{
	double g, s;
	cout << "g = "; cin >> g;
	cout << "s = "; cin >> s;
	double c = (h(g + 1.0, s) + pow(h(g, s + 1.0), 2)) / (1.0 + pow(h(pow(g, 2), pow(s, 2)), 3));
	cout << "c = " << c << endl;
	return 0;
}
double h(const double a, const double b)
{
	return pow(a, 2) - pow(b, 2);
}