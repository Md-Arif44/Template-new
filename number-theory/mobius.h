l/**
 * Author: 
 * Date:  
 * License:  
 * Source: 
 * Description: 
 * Count x in [L, R], gcd(x, m) = k:
 *   sum d|(m/k) mu[d] *
 *   (R/(k*d) - (L-1)/(k*d))
 * Count pairs (i, j), gcd(i, j) = k:
 *   sum d<=min(r1/k, r2/k) mu[d] *
 *   (r1/(k*d) - (l1-1)/(k*d)) *
 *   (r2/(k*d) - (l2-1)/(k*d))
 * Count pairs in array a[], gcd(a[i], a[j]) = k:
 *   cnt[x] = # of elements divisible by x
 *   sum d<=Max/k mu[d] * cnt[d*k]^2
 */


const int N = 5e5 + 9;
int mob[N];
void mobius() {
  mob[1] = 1;
  for (int i = 2; i < N; i++){
    mob[i]--;
    for (int j = i + i; j < N; j += i) {
      mob[j] -= mob[i];
    }
  }
}
