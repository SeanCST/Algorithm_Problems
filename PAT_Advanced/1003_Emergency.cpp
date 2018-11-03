/* https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376 */

#include <iostream>
#include <algorithm>
using namespace std;

#define MX 510

int main() {
  // N-城市数目 M-路的数目 C1-你目前所在城市 C2-你需要救援的城市
  int N, M, C1, C2; 
  /* 
  dis[i]：从出发点到i结点最短路径的路径长度，
  num[i]：从出发点到i结点最短路径的条数，
  w[i]：从出发点到i点救援队的数目之和 
  */
  int e[MX][MX], weight[MX], dis[MX], num[MX], w[MX]; 
  bool visit[MX];
  const int inf = 99999999;
  
  cin >> N >> M >> C1 >> C2;
  for(int i = 0; i < N; i++)
    cin >> weight[i]; // 输入每个城市当前救援队数目
    
  fill(e[0], e[0] + MX * MX, inf);
  fill(dis, dis + 510, inf);
  int a, b, c;
  for(int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    e[a][b] = e[b][a] = c; // 路径长度，用邻接矩阵表示
  }
  
  dis[C1] = 0;
  w[C1] = weight[C1];
  num[C1] = 1;
  
  for(int i = 0; i < N; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < N; j++) {
      if(visit[j] == false && dis[j] < minn) {
        u = j;
        minn = dis[j];
      }
    }
    
    if(u == -1) break;
    visit[u] = true;
    for(int v = 0; v < N; v++) {
      if(visit[v] == false && e[u][v] != inf) {
        if(dis[u] + e[u][v] < dis[v]) {
          dis[v] = dis[u] + e[u][v];
          num[v] = num[u];
          w[v] = w[u] + weight[v];
        } else if(dis[u] + e[u][v] == dis[v]) {
          num[v] = num[v] + num[u];
          if(w[u] + weight[v] > w[v])
          w[v] = w[u] + weight[v];
        }
      }
    }
  }
  
  cout << num[C2] << " " << w[C2];
  return 0;
  
}