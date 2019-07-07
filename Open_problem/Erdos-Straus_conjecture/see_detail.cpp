/* エルデス-シュトラウスの予想 */
/* nを2以上の任意の自然数とする。
4/n = 1/x + 1/y + 1/z 
を満たす自然数x, y, zが必ず存在するか？*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cout << "Input a nutural of number 2 or more. --> ";
	cin >> n;

	/*
	4/n = 1/x + 1/y + 1/z 
	<=> 4/n = (yz + zx + xy)/xyz
	<=> 4 : n = (yz + zx + xy) : xyz
	<=> 4xyz = n(yz + zx + xy)
	*/

	for (int x = 1; x < n * 100; x++)
	{
		for (int y = 1; y < n * 100; y++)
		{
			for (int z = 1; z < n * 100; z++)
			{
				if ((4 * x * y * z) == (n * (y * z + z * x + x * y)))
				{
					cout << "could find x, y, z." << endl;
					cout << "x = " << x << "," << endl;
					cout << "y = " << y << "," << endl;
					cout << "z = " << z << endl;

					/* 4xyz = n(yz + zx + xy) */
					cout << "4*x*y*z = " << 4*x*y*z << "," << endl;
					cout << "n(yz + zx + xy) = " << n*(y*z + z*x + x*y) << "," << endl;

					return 0;
				}
			}
		}
	}

	cout << "couldn't find x, y, z under the range of n * 100." << endl;

	return 0;
}
