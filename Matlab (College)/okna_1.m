function okna_1
L = 64;

w1 = ones(L,1);
wvtool(w1);

N = L-1;
for n=1:N
    w2(n) = 0.54 - 0.46*cos(2*pi*n/N);
end
wvtool(w2);

for n=1:N
    w3(n) = 0.42 - 0.5*cos((2*pi*n)/(L-1)) + 0.08*cos((4*pi*n)/(L-1));
end
wvtool(w3);

for n=1:N
    w4(n) = 0.5*(1-cos(2*pi*n/N));
end
wvtool(w4);
end