// Josh Sample
// Josephus Problem calculator (non-general case i.e. k=2)
/*
	The Josephus Problem is a counting game
	in which people are in a circle waiting
	to be executed. Counting begins at a specified 
	point in the circle and the first person kills the
	person to their left. The procedure is repeated 
	until one person remains. This calculator finds
	the position someone should "sit" at in order
	to be the one remaining.
*/
#include <iostream>
using namespace std;

int safePosition(int n);
int bitOperations(int value);

int main()
{
	int n = 0;
	char repeat;

	do
	{
		cout << "Enter the number of people: ";
		cin >> n;
		cout << "The safe position is position " << safePosition(n) << "." << endl;
		cout << "Enter y to repeat, anything else to exit. ";
		cin >> repeat;
	} while (repeat == 'y' || repeat == 'Y');

	system("pause");
	return 0;
}

int safePosition(int n)
{
	// Assuming n = 2^a + L
	// then f(n) = 2L + 1
	int l = n - bitOperations(n);
	int position = 2 * l + 1;
	return position;
}

int bitOperations(int value)
{
	// Uses bitwise right shift operators
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	value |= value >> 16;
	return value ^ (value >> 1);
}