function [] = porownanie()

T = 10 - 1/100;
dt = 1/100;
N = (T+ dt)/dt;

t = 0:dt:T;
signal = sin(2*pi*15*t) + sin(2*pi*40*t);

X1 = zeros (1,N);
tic;

for k = 0:N-1
    suma=0;
    for n = 0:N-1
        suma = suma + (sin(2*pi*15*(n+1)*dt) + sin(2*pi*40*(n+1)*dt)).*exp(-(1j*2*pi*k*n)/N);
    end
    xdft(k+1) = suma;
end
m = abs(xdft);
f = (0:N-1)*100/N;
czasdft = toc
tic
fft(X1);
czasfft=toc

%subplot(2,1,1)
%stem(f,m)
%title ('Magnitude')

%subplot(2,1,2)
%plot(f,angle(xdft))
%title ('Phase')
dczas = czasdft - czasfft
end