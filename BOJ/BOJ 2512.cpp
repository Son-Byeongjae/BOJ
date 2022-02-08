#include <iostream>
#include <vector>
using namespace std;

int n, m, maxVal;
vector<int> budget;

bool check(int mid)
{
	int sum = 0;
	for ( int i = 0; i < n; i++ )
	{
		if ( budget[i] <= mid ) sum += budget[i];
		else sum += mid;
	}
	if ( sum <= m ) return true;
	else return false;
}

int main()
{
	cin >> n;
	budget.resize(n);
	int sum = 0;
	for ( int i = 0; i < n; i++ )
	{
		cin >> budget[i];
		sum += budget[i];
		if ( maxVal < budget[i] ) maxVal = budget[i];
	}
	cin >> m;
	if ( sum <= m ) cout << maxVal << '\n';
	else
	{
		long long low = 0, high = maxVal;
		// ���Ѿ��� low�� ���, ���� �������� ��簡��.
		// ���Ѿ��� high�� ���, ���� ������ ����.
		while ( low + 1 < high )
		{
			long long mid = (low + high) / 2;
			if ( check(mid) ) low = mid;
			else high = mid;
		}
		cout << low << '\n';
	}
	return 0;
}