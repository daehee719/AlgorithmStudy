#include <string>
#include <vector>
#include <iostream>
using namespace std;

int i;
string word;

int solution(string s) {
    int answer = 0;
    if (s[0] == 'z')
    {
        i += 4;
        return 0;
    }
    else if (s[0] == 'o')
    {
        i += 3;
        return 1;
    }
    else if (s[0] == 't')
    {
        if (s[1] == 'w')
        {
            i += 3;
            return 2;
        }
        else
        {
            i += 5;
            return 3;
        }
    }
    else if (s[0] == 'f')
    {
        if (s[1] == 'o')
        {
            i += 4;
            return 4;
        }
        else
        {
            i += 4;
            return 5;   
        }
    }
    else if (s[0] == 's')
    {
        if (s[1] == 'i')
        {
            i += 3;
            return 6;
        }
        else
        {
            i += 5;
            return 7;
        }
    }
    else if (s[0] == 'e')
    {
        i += 5;
        return 8;
    }
    else if (s[0] == 'n')
    {
        i += 4;
        return 9;
    }
    return answer;
}

int main()
{
    cin >> word;
    vector<int> v;
    for (i = 0; i < word.length(); i++)
    {
        if (word[i] <= 57 && word[i] >= 48)
        {
            v.push_back(word[i] - '0');
        }
        else
        {
            v.push_back(solution(word.substr(i,word.length()-i)));
            i--;
        }
    }
    for (int j = 0; j < v.size(); j++)
    {
        cout<<v[j];
    }
}
