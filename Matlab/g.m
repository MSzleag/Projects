function [] = g;
N= 300;
t = linspace(0,1,N)
x=sin(2*pi*t*10000) +sin(2*pi*3000*t);
h = fir;
z = conv(x,h);
figure(1)
plot(t,x);
L = length(z)
L2 = 0:1:L-1;
figure(2)
plot(L2,z)
end
