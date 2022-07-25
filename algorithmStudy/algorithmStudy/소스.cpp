#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    int a;
    cin >> a;
    string s;
    for (int i = 0; i < a; i++)
    {
        cin >> s;
        if (s == "push")
        {
            int b;
            cin >> b;
            v.push_back(b);
        }
        else if (s == "top")
        {
            if (v.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << v[v.size() - 1];
                cout << endl;
            }
        }
        else if (s == "size")
        {
            cout << v.size();
            cout << endl;
        }
        else if (s == "pop")
        {
            if (v.empty())
            {
                cout << -1;
                cout << endl;
            }
            else
            {
                cout << v[v.size() - 1];
                cout << endl;
                v.pop_back();
            }
        }
        else if (s == "empty")
        {
            if (v.empty())
            {
                cout << 1;
                cout << endl;
            }
            else
            {
                cout << 0;
                cout << endl;
            }

        }
    }

}