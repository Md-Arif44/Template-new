/**
* Description: Operators for modular arithmetic. You need to set {\tt mod} to
* Status: Works
*/

const int mod=1e9+7;
 struct mint{
  ll x;
  mint(ll x_=0):x(x_ % mod){if (x < 0) x += mod;}
  mint power(ll e) const {
      mint r = 1,b =*this;
      for (;e;e>>=1,b=b*b) if(e&1)r=r*b;
    return r;
  }
  mint inv(){return power(mod - 2);}
  mint operator+(mint b) { return mint((x + b.x) % mod); }
  mint operator-(mint b) { return mint((x - b.x + mod) % mod); }
  mint operator*(mint b) { return mint((x * b.x) % mod); }
  mint operator/(mint b) { return *this * b.power(mod - 2); }
 };
