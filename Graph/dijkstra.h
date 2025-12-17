/**
 * Author:  
 * Date:  
 * Source: 
 * Description:  
 */
vl dijkstra(const V<V<pll>> &g, int s) {
  int n =sz(g) ; assert(0 <= s && s < n);
  vl dist(n,ll(1e18));
  priority_queue<pll, V<pll>, greater<>> q;
  dist[s] = 0;
  q.emplace(dist[s], s);
  while (!q.empty()) {
    auto [expected,v] = q.top();
    q.pop();
    if (dist[v ] != expected ) continue;
    
      for(auto &[u,w]:g[v]){
            if(w+dist [v ]<dist[u]){ 
              dist[u]=w+dist[v ];
              q.emplace(dist[u],u);
            }
      }             

  }
  return dist;
  // returns inf if there's no path
}
