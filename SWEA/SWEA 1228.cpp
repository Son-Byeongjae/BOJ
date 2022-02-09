#include <iostream>
#include <list>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T = 10;
	
	//cin >> T;
	
	for ( test_case = 1; test_case <= T; ++test_case )
	{
		list<int> l;
		int n;
		cin >> n;
		while ( n-- )
		{
			int num;
			cin >> num;
			l.push_back(num);
		}

		cin >> n;

		// ���1 insert ���.
		while ( n-- )
		{
			char cmd;
			cin >> cmd;

			int x, y, num;
			cin >> x >> y;
			while ( y-- )
			{
				cin >> num;
				auto iter = l.begin();
				advance(iter, x);
				l.insert(iter, num);
				x++;
			}
		}

		// ���2 splice ���.
		/*list<int> list2;
		while ( n-- )
		{
			char cmd;
			cin >> cmd;

			int x, y, num;
			cin >> x >> y;

			while ( y-- )
			{
				cin >> num;
				list2.push_back(num);
			}
			auto iter = l.begin();
			advance(iter, x);
			l.splice(iter, list2);
		}*/

		
		cout << "#" << test_case << " ";
		int cnt = 1;
		for ( int num : l )
		{
			cout << num << " ";
			if ( cnt++ == 10 ) break;
		}
		cout << '\n';
	}
	return 0;
}