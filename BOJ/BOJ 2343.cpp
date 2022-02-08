#include <iostream>
#include <vector>
using namespace std;

int n, m, maxVal;
vector<int> times;

bool check(int mid)
{
	int cnt = 1, sum = 0;
	for ( int i = 0; i < n; i++ )
	{
		sum += times[i];
		if ( times[i] > mid ) return false;
		if ( sum > mid )
		{
			sum = times[i];
			cnt++;
		}
	}
	if ( cnt <= m ) return true;
	else return false;
}

int main()
{
	cin >> n >> m;
	times.resize(n);
	for ( int i = 0; i < n; i++ )
	{
		cin >> times[i];
		maxVal += times[i];
	}
	// ��緹�� ũ�Ⱑ lo�� ���, m���� ��緹�̷δ� ��ȭ �Ұ���
	// ��緹�� ũ�Ⱑ hi�� ���, m���� ��緹�̷� ��ȭ ����
	int lo = 0, hi = maxVal;
	while ( lo + 1 < hi )
	{
		int mid = (lo + hi) / 2;
		if ( check(mid) ) hi = mid;
		else lo = mid;
	}
	cout << hi << '\n';
	return 0;
}