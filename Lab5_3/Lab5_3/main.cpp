#include <iostream>
#include <cmath>
using namespace std;
double f(const double x);
int main()
{
	double yp, yk, z;
	int n;
	cout << "yp = "; cin >> yp;
	cout << "yk = "; cin >> yk;
	cout << "n = "; cin >> n;
	double dp = (yk - yp) / n;
	double y = yp;
	while (y <= yk)
	{
		z = f(1 + pow(y, 2)) + pow(f(f(1) + pow(f(pow(y, 2)), 2)), 2);
		cout << y << " " << z << endl;
		y += dp;
	}
	return 0;
}
double f(const double x)
{
	if (abs(x) >= 1)
		return cos(x / 2) / (1 + pow(sin(x), 2));
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = (2 * i * (2 * i - 1)) / ((3 * i - 2) * (3 * i - 1) * (3 * i));
			a *= R;
			S += a;
		} while (i < 6);
		return S;
	}
}