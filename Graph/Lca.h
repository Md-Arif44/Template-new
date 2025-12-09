/**
 * Description: add Rmq.h  . O(1) lca(a,b) 
 */
struct LCA {
  int T = 0;
  vi time, path, ret ,tour ;
  RMQ<int> rmq;
  LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
  void dfs(vector<vi>& C, int v, int par) {
    time[v] = T++; tour.pb(v) ;
    for (int y : C[v]) if (y != par) {
      path.pb(v), ret.pb(time[v]);
      dfs(C, y, v);
    }
    tour.pb(v) ;
  }
 
  int lca(int a, int b) {
    if (a == b) return a;
    tie(a, b) = minmax(time[a], time[b]);
    return path[rmq.query(a, b)];
  }
  //dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};
