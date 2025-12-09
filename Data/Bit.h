/*
 * Description: \texttt{update(i,x): a[i] += x;}\\
 * \texttt{query(i): sum in [0, i);}\\
 * \texttt{lower\_bound(sum): min pos st sum of [0, pos] >= sum, returns n if all < sum, or -1 if empty sum.
 */
struct FT {
  int n; V<ll> s;
  FT(int _n) : n(_n), s(_n) {}
  void update(int i, ll x) { 
    for (; i < n; i |= i + 1) s[i] += x; }
  ll query(int i, ll r = 0) { 
    for (; i > 0; i &= i - 1) r += s[i-1]; return r; }
  int lower_bound(ll sum) {
    if (sum <= 0) return -1; int pos = 0;
    for (int pw = 1 << (31 - __builtin_clz(n)) ; pw; pw >>= 1){
      if (pos+pw <= n && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    }
    return pos;
  }
}; 

/*
 * Description: for range add  and sum ..
*/
FT f1(n), f2(n);
// a[l...r] += v; 0 <= l <= r < n
auto upd = [&](int l, int r, ll v) {
  f1.update(l, v), f1.update(r + 1, -v);
  f2.update(l, v*(l-1)), f2.update(r+1, -v*r);
}; // a[l] + ... + a[r]; 0 <= l <= r < n
auto sum = [&](int l, int r) { ++r;
  ll sub = f1.query(l) * (l-1) - f2.query(l);
  ll add = f1.query(r) * (r-1) - f2.query(r);
  return add - sub;
};
