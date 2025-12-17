
/**
 * Author: 
 * Date:  
 * License: 
 * Description: Decomposes a tree into vertex disjoint heavy paths and light
 * edges such that the path from any leaf to the root contains at most log(n)
 * light edges. Code does additive modifications and max queries, but can
 * support commutative segtree modifications/queries on paths and subtrees.
 * Takes as input the full adjacency list. VALS\_EDGES being true means that
 * values are stored in the edges, as opposed to the nodes. All values
 * initialized to the segtree default. Root must be 0.
 * build  ord[ Id(i) ] =  a[i] for  segtree 
 * querySubtree(u)  return [l,r)    
 * Path( u,v)  return vec of [l,r)  
 * Time: O((\log N)^2)
 */
 
template <bool VALS_EDGES = false >
struct HLD {
  int N, tim = 0;
  vector<vi> adj;
  vi par, siz, rt, pos;

  HLD(vector<vi> adj_)
    : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1),
      rt(N),pos(N) { dfsSz(0); dfsHld(0); }
  void dfsSz(int v) {
    for (int& u : adj[v]) {
      adj[u].erase(find(all(adj[u]), v));
      par[u] = v;
      dfsSz(u);
      siz[v] += siz[u];
      if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
    }
  }
  void dfsHld(int v) {
    pos[v] = tim++;
    for (int u : adj[v]) {
      rt[u] = (u == adj[v][0] ? rt[v] : u);
      dfsHld(u);
    }
  }
  void process(int u, int v, V<pii> &op) {
    for (;; v = par[rt[v]]) {
      if (pos[u] > pos[v]) swap(u, v);
      if (rt[u] == rt[v]) break;
      op.pb({pos[rt[v]], pos[v] + 1});
    }
     op.pb({pos[u] + VALS_EDGES, pos[v] + 1});
  }
  V<pii> Path(int u, int v) {   
   V<pii> op ; process(u, v,op); return op ;
  }
  int Id (int v){  return pos[v]; }
  pii querySubtree(int v) {   
    return  {pos[v] + VALS_EDGES, pos[v] + siz[v]} ;
  }
};
