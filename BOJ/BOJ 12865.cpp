#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int collection[100][2];
int cache[100][100001]; // n�� max, k�� max.
// ���� �賶�� ���� �� �ִ� �ִ� �ѵ��� limit�̰�, here��° ������ pick�ؾ����� ����ϰ� ���� ��, 
// �賶�� ���� �� �ִ� �ִ� ��ġ ���� ��ȯ.
int findMaxValueSum(int here, int limit)
{
	if ( here == n - 1 ) return (limit >= collection[here][0] ? collection[here][1] : 0);

	int& ret = cache[here][limit];
	if ( ret != -1 ) return ret;

	if ( limit >= collection[here][0] )
		return ret = max(findMaxValueSum(here + 1, limit), collection[here][1] + findMaxValueSum(here + 1, limit - collection[here][0]));
	else
		return ret = findMaxValueSum(here + 1, limit);
}

int main()
{
	cin >> n >> k;
	for ( int i = 0; i < n; i++ )
	{
		memset(cache[i], -1, sizeof(cache[i]));
		cin >> collection[i][0] >> collection[i][1];
	}
	cout << findMaxValueSum(0, k) << '\n';
			
	return 0;
}