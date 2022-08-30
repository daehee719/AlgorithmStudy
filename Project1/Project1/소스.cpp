#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;


int main()
{
	string text = "i love c++";

	for (int i = 0; i < text.size(); i++)
	{
		cout << text<<endl;
		text.push_back(text[0]);
		text.erase(text[0]);
	}

	/*for (int i = 0; i < text.size(); i++)
	{
		string text1 = text.substr(1, text.size()-1);
		cout << text1 << text[i];
		text.push_back(text[i]);
	}*/
}