#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int main()
{
	int result = 0;
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		int b;
		cin >> b;
		if (b != 0)
			s.push(b);
		else
			s.pop();
	}
	if (!s.empty())
	{
		while (!s.empty())
		{
			result += s.top();
			s.pop();
		}
	}
	cout << result;
}