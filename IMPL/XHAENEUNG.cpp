#include <iostream>
#include <algorithm>

using namespace std;

int getNumberBySortedString(string s)
{
	sort(s.begin(), s.end());

	if (s.compare("eorz") == 0) return 0;
	if (s.compare("eno") == 0) return 1;
	if (s.compare("otw") == 0) return 2;
	if (s.compare("eehrt") == 0) return 3;
	if (s.compare("foru") == 0) return 4;
	if (s.compare("efiv") == 0) return 5;
	if (s.compare("isx") == 0) return 6;
	if (s.compare("eensv") == 0) return 7;
	if (s.compare("eghit") == 0) return 8;
	if (s.compare("einn") == 0) return 9;
	if (s.compare("ent") == 0) return 10;

	return -1;
}

int getNumber(string s) 
{
	if (s.compare("zero") == 0) return 0;
	if (s.compare("one") == 0) return 1;
	if (s.compare("two") == 0) return 2;
	if (s.compare("three") == 0) return 3;
	if (s.compare("four") == 0) return 4;
	if (s.compare("five") == 0) return 5;
	if (s.compare("six") == 0) return 6;
	if (s.compare("seven") == 0) return 7;
	if (s.compare("eight") == 0) return 8;
	if (s.compare("nine") == 0) return 9;
	if (s.compare("ten") == 0) return 10;

	return -1;
}

int calc(int n1, int n2, char oper)
{
	if (oper == '+') return n1 + n2;
	if (oper == '-') return n1 - n2;
	if (oper == '*') return n1 * n2;

	return -1;
}

int main()
{
	int T;

	cin >> T;
	getchar();

	while(T--) 
	{
		char oper;
	 	string n1, n2, dummy, answer;

		cin >> n1 >> oper >> n2 >> dummy >> answer;

		int result = calc(getNumber(n1), getNumber(n2), oper);				

		if (result < 0 || result > 10) {
			cout << "No" << endl;
		} else if (result == getNumberBySortedString(answer)) {
			cout << "Yes" << endl;	
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
