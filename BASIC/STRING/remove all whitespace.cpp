#include <iostream>
using namespace std;

//METHOD 1:- using loop
// TIME COMP:- O(n)
void removeSpaces1(char* str)
{
	// To keep track of non-space character count
	int count = 0;

	// Traverse the given string. If current character
	// is not space, then place it at index 'count++'
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ')
			str[count++] = str[i]; // here count is
	// incremented
	str[count] = '\0';
}

//METHOD 2:- using stl
// NOTE:- its run only on onlide IDE
/*
string removeSpaces2(string str2)
{
	str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());
	return str2;
}
*/

int main()
{
	char str1[] = "g  eeks   for ge  eeks  ";
	removeSpaces1(str1);
	cout << str1 << endl;


	// string str2 = "g  eeks   for ge  eeks   ";
	// str2 = removeSpaces2(str2);
	// cout << str2 << endl;

	return 0;
}