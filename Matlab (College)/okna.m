function okna

L = 100;
a = blackman(L);
c = boxcar(L);
d = gausswin(L);
e = flattopwin(L);
f = hamming(L);
wvtool(a,c,d,e,f);
