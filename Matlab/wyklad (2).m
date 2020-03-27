function [] = wyklad()
dt = 1/100;
T = 10 - dt;
fpr = 1/dt;
N = (T + dt)/dt;
n = 1:N-1;
df = 1/(N*dt);

t = 0:dt:T;
signal = @(t) sin(2*pi*15*t) + sin(2*pi*40*t);
cc = sin(2*pi*15*t) + sin(2*pi*40*t);

%u = fft(signal(t));
v = fft(cc);
y = zeros(1,N);
xdft = zeros(1,N);

%f = df*N

for k = 0:N-1
    for n = 0:N-1
        %y(k+1) = signal((k+1)*dt).*exp(-(1j*2*pi*k*n)/N);
        Wn = exp(-(1j*2*pi*k*n)/N);
        Xl(k+1, n+1) = Wn;
    end
    %xdft(k+1) = sum(y)
end

Xk = Xl*signal(t)';

m = abs(Xk);

Xk(m<1e-4) = 0;
p = unwrap(angle(Xk));
X = Xk;
df1=1/(N*(1/fpr));
pom=Xk;
if mod(N,2)==0
    fmax=X((N/2)+1);
    f=[(-N/2)*df+df:df:(N/2)*df];
    pom=[X((N/2)+2:end);X(1:(N/2)+1)];
else
    fmax=X(((N-1)/2)+1);
    f=[-((N-1)/2)*df:df:((N-1)/2)*df];
    pom=[X(((N-1)/2)+2:end);X(1:((N-1)/2)+1)];
end

p1 = unwrap(angle(pom));
figure(1);
stem(f,abs(pom));grid on;
title('Charakterystka Amplituda')

figure(2)
stem(f,p1*(180/pi));grid on;
title('Charakterystka Fazowa')

end

