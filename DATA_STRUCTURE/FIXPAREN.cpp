#include <iostream>
#include <stack>
#include <string>

typedef struct {
	char ch;
	int  index;
} CharInfo;

using namespace std;

bool isLeft(char ch)
{
	return (ch == '{' || ch == '[' || ch == '(' || ch == '<');
}

char getMatchedLeftChar(char right)
{
	if (right == '}') return '{';
	if (right == ']') return '[';
	if (right == ')') return '(';
	if (right == '>') return '<';

	return 0;
}

char getMatchedRightChar(char left)
{
	if (left == '{') return '}';
	if (left == '[') return ']';
	if (left == '(') return ')';
	if (left == '<') return '>';

	return 0;
}

bool isLeftCharPriorThanRightChar(string priorityOrder, char left, char right)
{
	int leftIdx = priorityOrder.find(left);
	int rightIdx = priorityOrder.find(getMatchedLeftChar(right));
	
	return (leftIdx < rightIdx);
}

void solve(string input, string priorityOrder)
{
	stack<CharInfo> st;
	char output[128];

	int len = input.length();
	for(int i = 0; i < len; i++) {

		CharInfo info;

		if (isLeft(input.at(i))) {
			info.ch = input.at(i);
			info.index = i;
			st.push(info);
		} else {

			info = st.top();

			char left = info.ch;
			char right = input.at(i);
			
			if (isLeftCharPriorThanRightChar(priorityOrder, left, right)) {
				right = getMatchedRightChar(left);
			} else {
				left = getMatchedLeftChar(right);
			}
			
			// insert left & right character
			output[info.index] = left;
			output[i] = right;

			st.pop();
		}
	}

	for(int i = 0; i < len; i++) {
		cout << output[i];
	}
	cout << endl;
}

int main()
{
	int T;

	cin >> T;
	while(T--) {
		string input;
		string priorityOrder;

		cin >> input >> priorityOrder;

		solve(input, priorityOrder);
	}

	return 0;
}
