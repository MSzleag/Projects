function [] = dft2_2()

x = [1 2 3 4];
N = length(x);
X = zeros(N,1);

for k = 0:N-1
    for n = 0:N-1
        X(k+1) = X(k+1) +x(n+1)*exp(-1j*pi/2*n*k);
    end
end

t = 0:N-1
figure(2)
subplot(311)
stem(t,x, 'r');
xlabel('Czas');
ylabel('Amplituda');
title('DFT')

subplot(312)
stem(t,abs(X), 'r')
xlabel('Czestotliwosc');
ylabel('|X(k)|');
title('|DFT|')

subplot(313)
stem(t,angle(X), 'r');
xlabel('Czestotliwosc');
ylabel('Faza');
title('Odpowiedz Fazowa')
x = [1 0 3 0];
N = length(x);
X = zeros(N,1);

for k = 0:N-1
    for n = 0:N-1
        X(k+1) = X(k+1) +x(n+1)*exp(-1j*pi/2*n*k);
    end
end

t = 0:N-1
figure(1)
subplot(311)
stem(t,x);
xlabel('Czas');
ylabel('Amplituda');
title('DFT po')

subplot(312)
stem(t,abs(X))
xlabel('Czestotliwosc');
ylabel('|X(k)|');
title('|DFT| po')

subplot(313)
stem(t,angle(X));
xlabel('Czestotliwosc');
ylabel('Faza');
title('Odpowiedz Fazowa po')


end