#include <iostream>
using namespace std;
int sum(int x, int y, int z)
{
	return x + y + z;
}
int main()
{
	int a, b, c;

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;

	int S = sum(a, b, c);

	cout << "S = " << S << endl;
	system("pause");
	return 0;
}