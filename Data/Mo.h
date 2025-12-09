// Mo  quary 0 base  time: O((N + Q)√N) , block size  is sqrt(n) , 
  int n =0 , q=0; 
  const int Block = 335 ; 
   struct  MO{
       int l,r , id ;
       bool operator<(const MO &e )const {
         return  make_pair(l/Block , r)< make_pair(e.l/Block ,e.r) ;
       }
  };
    vector<MO> quary(q) ; 
    // in quary
    auto add=[&] (int id){ };
    auto rem=[&](int id){ };
    auto clc=[&]()->int { return ; };
    
    sort(all(quary));
    int cl  = 0 ,cr=  -1 ;
    vi ans (q) ;
    for (int i=0;i<q;i++) {
      auto &[l,r , id ]  = quary[i];     
        while (cl > l)add( --cl);
        while (cr < r)add(++cr );
        while (cl < l)rem(cl++ );
        while (cr > r)rem (cr-- );
        ans[id]= clc () ;
    }
/*

   Mo tree quary  make 2n tour vec 
   for path u to v  if(in[u]> in[v] )swap(u,v) 
   if  u == lca(u,v) then quary = in[u] to in [v ] ;
   else quary  out[u] to in[v] then add lca node  
   all are 0 base   
 */
 
   vi tour , in(n),out(n) ;
   auto dfs=[&](auto dfs,int v,int pa)-> void {
        in[v]=sz(tour);
        tour.pb(v) ;
        for(auto u: G[v]){
           if(u!= pa ){
             dfs(dfs,u,v) ;
           }
        }
       out[v]=sz(tour);
       tour.pb(v);
    }; dfs(dfs,0,-1);
  //-----
