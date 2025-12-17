/**
 * Author:  
 * Date:  
 * License: 
 * Source:  
 */

V<vl>  PrefixSums2D(V<vl> &a) {
  // ...1 base
    int  n = sz(a) ,m = sz(a[0]) ;
    V<vl> pre(n + 1, vl(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + a[i][j];
        }
    }
    return pre;
}
ll get(int rx,int ry,int lx,int ly,V<vl> &pre){
  // ... 1 base l to r inclusive
  lx--,--ly;
  return pre[rx][ry]+pre[lx][ly]-pre[rx][ly]-pre[lx][ry];

}
