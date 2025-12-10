/**
* Description: include mint.h
* Status: Works
*/
V<mint> fct(1, 1), infct(1, 1);
 mint C(int n, int k) {
  if (k < 0 || k > n) return 0;
  
  while (sz(fct) < n + 1) {
    fct.pb(fct.back() * sz(fct) );
    infct.pb( mint(1) / fct.back());
  }
  return fct[n] * infct[k] * infct[n - k];
}
