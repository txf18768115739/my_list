#include<iostream>
#include<list>
#include<string>
using namespace std;

int main()
{
	list<int> s;
	list<int>::iterator it=s.begin();
	string a;
	while (cin >> a) 
	{
		for (int i=0; i < a.length(); i++)
		{
			char ch = a[i];
			if (ch == '[') it = s.begin();
			else if (ch == ']') it = s.end();
			else {
				s.insert(it, ch);
			}
			for (it = s.begin(); it != s.end(); it++)
			{
				cout << *it;
			}
			cout << endl;
			s.clear();
		}
	}
	system("pause");
	return 0;
}