#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> parent; // �θ� ���
vector<vector<int>> children; // �ڽ� ��� ����Ʈ
vector<vector<int>> adj; // ��������Ʈ
int N;

// bfs�� graph -> tree �����
void makeTree(int root)
{
	vector<bool> visited(N + 1, false);
	queue<int> q;

	visited[root] = true;
	q.push(root);
	while ( !q.empty() )
	{
		int curr = q.front();
		q.pop();
		for ( int next : adj[curr] )
		{
			if ( !visited[next] )
			{
				q.push(next);
				visited[next] = true;
				parent[next] = curr;
				children[curr].push_back(next);
			}
		}
	}
}

int main()
{
	int u, v;
	cin >> N;
	adj.resize(N + 1);
	parent.resize(N + 1);
	children.resize(N + 1);
	for ( int i = 1; i < N; i++ )
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	makeTree(1);
	for ( int num = 2; num <= N; num++ )
		cout << parent[num] << '\n';
	return 0;
}