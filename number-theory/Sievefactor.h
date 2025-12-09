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
