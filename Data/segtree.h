/**
 * Author: atcoder library
 * Date:
 * License: 
 * Source:
 * Description:
 * Status: Tested
 */
template <class T, T (*op)(T, T), T (*e)()> 
struct segtree {
  int n,size; V<T> d;
  segtree(const V<T>& v){
      n=sz(v),size=1; 
      while(size<n)size<<=1;
      d=V<T>(2 * size, e());
      
      rep(i,0,n)d[size + i] = v[i];

      for(int i=size-1;i>=1;i--) update(i);
    }
    void update(int k) { 
      d[k] = op(d[2 * k], d[2 * k + 1]); 
    }
    void set(int p, T x) {
        assert(0 <= p && p < n);
        p += size;  d[p] = x;
        while(p > 1)update(p >>=1);
    }
    T prod(int l, int r) const { // [l,r)
      assert(0 <= l && l <= r && r <= n);
        T sml = e(), smr = e();
        for(l += size ,r += size ; l<r ;  l>>=1,r>>=1 ){
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr); 
        }
      return op(sml, smr);
    }
};
