function drugie
N= 50;
t= linspace(0,1,N);
x= sin(30*2*pi*t);
h = sinc(t);
z = conv(x,h);

figure (1)
plot (t,x);
L = length(z);
L2=0:1:L-1;
figure (2)
plot(L2,z)
