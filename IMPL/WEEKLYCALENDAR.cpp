#include <iostream>

using namespace std;

int calendar[512];

const int DAYS_OF_WEEK = 7;
const int DAYS_OF_YEAR = 365;

int getDaysOfMonth(int month)
{
	switch(month)
	{
		case 4: case 6: case 9: case 11: 
			return 30;
		case 2: 
			return 28;
		default:
			return 31;
	}
}

void init()
{
	int calIdx = 0;

	for(int i=1; i<=12; i++) {
		int days = getDaysOfMonth(i);
		for(int j=1; j<=days; j++) {
			calendar[calIdx++] = j;
		}
	}
}

int findIndexInCalendar(int month, int day)
{
	int days = 0;
	for(int i=1; i<month; i++) {
		days += getDaysOfMonth(i);	
	}
	return (days + day - 1);
}

int getOffset(string week)
{
	if (week.compare("Sunday") == 0) return 0;
	if (week.compare("Monday") == 0) return 1;
	if (week.compare("Tuesday") == 0) return 2;
	if (week.compare("Wednesday") == 0) return 3;
	if (week.compare("Thursday") == 0) return 4;
	if (week.compare("Friday") == 0) return 5;
	if (week.compare("Saturday") == 0) return 6;

	return -1;
}

void solve(int month, int day, string week)
{
	int index = findIndexInCalendar(month, day);	
	int offset = getOffset(week);

	int start = index - offset;
	int end = start + (DAYS_OF_WEEK - 1);

	for(int i = start; i <= end; i++) {
		// consider when i < 0
		cout << calendar[(i+DAYS_OF_YEAR) % DAYS_OF_YEAR] << " ";
	}
	cout << endl;
}

int main()
{
	init();

	int T;
	cin >> T;

	while(T--)
	{
		int month, day;
		string week;

		cin >> month >> day >> week;
		
		solve(month, day, week);
	}

	return 0;
}
