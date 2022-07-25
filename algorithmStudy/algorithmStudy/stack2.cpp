#include <iostream>
#include <stack>
using namespace std;


stack<char> s;
int main()
{
	int a;
	cin >> a;
	bool isMinus;
	string c;
	for (int i = 0; i < a; i++)
	{
		isMinus = false;
		cin >> c;
		for (int i = 0; i < c.size(); i++)
		{
			if (c[i] == '(')
				s.push('(');
			else if (c[i] == ')')
			{
				if (s.empty())
					isMinus = true;
				else
					s.pop();
			}
		}
		if (s.empty()&&!isMinus)
			cout << "YES" << endl;
		else if(!s.empty() || isMinus)
			cout << "NO" << endl;
		while (!s.empty())
		{
			s.pop();

		}
		
		
	}
}