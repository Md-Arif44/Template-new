/**
 * Description: Scc    
 * usage : SCC( g,rg) g in garph and  reverse graph
 * return  was has scc node with same val
*/
pair<vi,vi> Fun (const V<vi> &g ,const vi &order  ){
     vi topo ,vis(sz(g)),was(sz(g))  ;
     int attempt=0;
     auto dfs=[&](auto dfs,int v)-> void {
             vis[v]=1;
             was[v]=attempt ;
            for(auto u: g[v]){
               if(vis[u]==0)
                  dfs(dfs, u);
            }
        topo.pb(v);
     };
     rep(i ,0,sz(order) ) {
           if(vis[order[i]] ==0 ){
                attempt++ ;
              dfs(dfs, order[i] ) ;
           }
     }
    reverse(all(topo))  ;
    return make_pair(topo,was) ;
}
vi SCC(const V<vi> &g ,V <vi>&rg){
    vi ord(sz(g)) ; iota(all(ord),0) ;
    auto [topo,_ ]= Fun(g, ord);
    auto [__,was]= Fun(rg,topo);   
  return was; 
}
