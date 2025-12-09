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
