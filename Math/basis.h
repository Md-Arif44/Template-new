// basis
vector<int > bit(32) ;
int Sz=0 ;
void Insert(int x){
   for(int i=30;i>=0 ;i--){
       
       if((x>>i& 1) == 0 )continue ;
       
       if(bit[i] )  x^=bit[i] ;
       else {
        bit[i]=x ;
        Sz++ ;
        break ;
     }
   }
}
