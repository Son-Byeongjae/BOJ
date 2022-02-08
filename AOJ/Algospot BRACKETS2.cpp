#include <iostream>
#include <stack>
using namespace std;

bool isMatched(string& input)
{
	char match_bracktes[3][2] = { {'(', ')'},
							 {'{','}'} ,
							 {'[',']'} };

	stack<char> brackets;
	for ( int i = 0; i < input.size(); i++ )
	{
		int type = 0;
		bool isClosed = false;
		for ( ; type < 3; type++ )
		{
			// �ݴ� ��ȣ�� ���
			if ( input[i] == match_bracktes[type][1] )
			{
				// ���� ���� �� ���� �ִ� ��ȣ�� ���� type�� ���� ��ȣ ���� Ȯ���Ѵ�.
				if ( brackets.empty() || brackets.top() != match_bracktes[type][0] ) return false;
				brackets.pop();
				isClosed = true;
			}
		}
		if ( !isClosed ) brackets.push(input[i]);
	}
	if ( brackets.empty() ) return true;
}

int main()
{
	int C;
	string input;

	cin >> C;
	while ( C-- )
	{
		cin >> input;
		if ( isMatched(input) ) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}