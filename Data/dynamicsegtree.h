struct node{
  int sum ;
  node *lc;
  node *rc;
  node(){
    rc= lc=NULL ; 
     sum =0 ;
  }
};
const int LL=1 ,RR =int(1e9);
 
 
int quary (node *me, int a,int b, int L,int R){
    
   if(a>R  || b< L )return 0 ;
    if(L>= a && R<=b )return me-> sum ;
     int m=(L+R)>>1 ; 
 
    ll p1 =0 ,q1 =0 ;
    if(me-> lc != NULL ) p1 =quary(me->lc ,a,b ,L,m);
    if(me->rc != NULL) q1 =quary(me-> rc ,a,b ,m+1,R);
    return p1+ q1 ;
}
void update(node *me ,int i,int val ,int L,int R){
   if(L==R ){
      me ->sum += val ;
     return  ;
   }
   int m=(L+R)>>1 ;
   if( i<= m ){
    if(me-> lc == NULL )me->lc =new node() ;
       update(me->lc, i,val,L,m  ); 
       
   }else{
      if(me-> rc == NULL )me->rc =new node() ;
       update(me->rc, i,val ,m+1,R ) ;
   }
    if(me->lc  && me-> rc ){
       me->sum =me->lc -> sum + me->rc-> sum ;
    }else if(me->lc ){
        me->sum =me->lc -> sum ;
    }else{
        me->sum =me->rc -> sum;
    }
}
