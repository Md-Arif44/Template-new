
/**
 * Author: 
 * Date: 
 * License:  
 * Source: 
 */

/* Let n = p1^a1 * p2^a2 * ... * pk^ak
NOD: τ(n) = Π (ai + 1)
SOD:σ(n) = Π ( (pi^(ai+1) - 1) / (pi - 1) )
Euler Totient Function:φ(n) = n * Π (1 - 1/pi)
*/

int pclc=0;
vi least ,primes;
void RunSieve(int n) {
  least=vi(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (least[i] == 0) {
        least[i] = i;
        primes.pb(i);
    }
    for (int x : primes) {
      if (x > least[i] || i * x > n) {
        break;
      }
      least[i * x] = x;
    }
  }
  pclc = n;
}
vi facList(int x) {
  assert(x<=pclc);
    vi res;
    while (x >1) {
      res.pb(least[x]);
      x /= least[x];
    }
    return res;
}
