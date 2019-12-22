inline bool printNos(int n) { return n && (!(n-1) || printNos(n-1)) && printf("%d ", n); }
