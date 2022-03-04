#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<int> m;
// 0~k��° ������ ���� �� ������ ��ĥ �� �ִ� ���� �ִ� 

// 0��° ���� �о����� n-1��° ���� ���� ����.
int cache1[1000001];
int solve1(int k)
{
    memset(cache1, -1, sizeof(cache1));
    cache1[0] = m[0]; cache1[1] = 0; cache1[2] = max(cache1[1], cache1[0] + m[2]);

    for ( int i = 3; i <= k; i++ )
    {
        cache1[i] = max(cache1[i - 1], max(cache1[i - 2], cache1[i - 3]) + m[i]);
    }

    return cache1[k];
}


// 0��° ���� �� �о����� n-1��° ���� �� �� ����.
int cache2[1000001];
int solve2(int k)
{
    memset(cache2, -1, sizeof(cache2));
    cache2[0] = 0; cache2[1] = m[1]; cache2[2] = max(cache2[1], cache2[0] + m[2]);

    for ( int i = 3; i <= k; i++ )
    {
        cache2[i] = max(cache2[i - 1], max(cache2[i - 2], cache2[i - 3]) + m[i]);
    }

    return cache2[k];
}

int solution(vector<int> money)
{
    m = money;
    int n = money.size();
    int answer = max(solve1(n - 2), solve2(n - 1));
    return answer;
}