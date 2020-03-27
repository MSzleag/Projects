function [] = dft2_1()

x = [2 3 -1 4 -2 5 -3 6];
N = length(x);
X = zeros(N,1);

for k = 0:N-1
    for n = 0:N-1
        X(k+1) = X(k+1)+x(n+1)*exp(-j*pi/1*n*k)
    end
end

t = 0:N-1;

figure(3)
subplot (611)
stem(t,x,'r');

ylabel('Amplituda');
title('DFT bez zer');


subplot (613)
stem(t,abs(X),'r');

ylabel('|X(k)|');
title('|DFT| bez zer');

subplot (615)
stem(t,angle(X), 'r');

ylabel('|X(k)|');
title('arctg|DFT| bez zer');

x = [2 3 -1 4 -2 5 -3 6 0 0 0 0 0 0 0 0 0 0 ];
N= length(x);
X = zeros(N,1);
for k = 0:N-1
    for n = 0:N-1
        X(k+1) = X(k+1) + x(n+1)*exp(-j*pi/2*n*k);
    end
end
t = 0:N-1;


subplot (612)
stem(t,x);

ylabel('Amplituda');
title('DFT z zerami');


subplot (614)
stem(t,abs(X));

ylabel('|X(k)|');
title('|DFT| z zerami');

subplot (616)
stem(t,angle(X));

ylabel('|X(k)|');
title('arctg|DFT| z zerami');

