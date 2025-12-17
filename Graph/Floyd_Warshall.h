/**
 * Author: 
 * Date:  
 * License:  
 * Source: 
 */
// inf means has no path  
const ll inf = 2e18;
void Floyd_Warshall (V<vl> &dis){
  int n = sz(dis) ;
  rep(i,0,n )dis[i][i]=0;    
   rep(k,0,n ){
     rep(i,0,n){
       rep(j,0,n){
          if(dis[i][k]!=inf && dis[k][j]!=inf ){
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
          }
       }
     }
  }
}
