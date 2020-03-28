function  filtr
t = linspace(-pi,pi,100);

x = 2*sin(3*t) + 0.35*rand(size(t));

windowSize = 20; 
b = boxcar(windowSize);
a = 1;
y = filter(b,a,x);

plot(t,x,'-r')
hold on; grid on
plot(t,y)
legend('Na wejciu','Po filtracji')