#include <iostream>
using namespace std;

unsigned longestSequence(char* s)
{
	int length = 1;
	int newlength = 0;
	if (s[0] == '\0') return 0;
	else {
		for (int i = 1; s[i] != '\0'; i++)
		{
			if (s[i] == s[i - 1])length++;
			else {
				if (length > newlength)newlength = length;
				length = 1;
			}
		}
		if (newlength < length)newlength = length;
		return newlength;
	}
}

int main() {
	char s[1000];
	cin.getline(s, 1000);
	cout << "res=" << longestSequence(s) << endl;
	system("pause");
	return 0;
}