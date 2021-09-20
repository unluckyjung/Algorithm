#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 2;
struct Edge {
    int from, to;
    int cost;
};

bool cmp(const Edge &e1, const Edge &e2) {
  return e1.cost < e2.cost;
}

int parent[MAX];

vector<Edge> edges;

int n, m;


int find(int node) {
  if (parent[node] < 0) return node;
  return parent[node] = find(parent[node]);
}

void merge(int node1, int node2) {
  node1 = find(node1);
  node2 = find(node2);

  if (node1 == node2) return;
  parent[node1] = node2;
}

bool isSameGroup(int node1, int node2) {
  return find(node1) == find(node2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(parent, -1, sizeof(parent));

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    edges.push_back({from, to, cost});
  }

  sort(edges.begin(), edges.end(), cmp);

  int answer = 0;
  int edgeCount = 0;
  for (Edge edge : edges) {
    if (isSameGroup(edge.from, edge.to)) continue;
    merge(edge.from, edge.to);
    answer += edge.cost;
    edgeCount++;
    if (edgeCount == n - 1) break;
  }

  cout << answer << "\n";

  return 0;
}

