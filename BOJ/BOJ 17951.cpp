#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> num;

bool check(long long mid)
{
	int cnt = 0;
	long long sum = 0;
	for ( int i = 0; i < n; i++ )
	{
		sum += num[i];
		if ( sum >= mid )
		{
			sum = 0;
			cnt++;
		}
	}
	if ( cnt >= k ) return true;
	else return false;
}

int main()
{
	cin >> n >> k;
	num.resize(n);

	for ( int i = 0; i < n; i++ )
		cin >> num[i];
	// �ּ� ������ lo�� k�� �̻� �׷����� ���� �� �ִ�. => �׷쳢�� ���� k�� �׷��� ���� �� ����.
	// �ּ� ������ hi�� k���� �׷����� ���� �� ����.
	long long lo = 0, hi = *max_element(num.begin(), num.end()) * n + 1;
	while ( lo + 1 < hi )
	{
		long long mid = (lo + hi) / 2;
		if ( check(mid) ) lo = mid;
		else hi = mid;
	}
	cout << lo << '\n';
	return 0;
}