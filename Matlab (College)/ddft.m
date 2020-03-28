function [] = ddft()
dt = 1/100;
T = 10 - dt;

N = (T + dt)/dt;
n = 1:N-1;
df = 1/(N*dt);

t = 0:dt:T;
s =  sin(2*pi*10*t) + sin(2*pi*30*t) + sin(2*pi*45*t);
s1 = sin(2*pi*10*t) + sin(2*pi*30*t) + sin(2*pi*45*t);

subplot(4,1,1)
plot(t,s1,'b')
title('Sygna³ pierwotny')

y = zeros(1,N);
ddft = zeros (1,N);


for k = 0:N-1;
    for n = 0:N-1;
    
        Wn = exp(-(1j*2*pi*k*n)/N);
        X1(k+1, n+1) = Wn;
    
    end
end
Xk = X1*s';

m =abs(Xk);

Xk(m<1e-4) = 0;
p = unwrap(angle(Xk));

f = (0:length(y)-1)/length(y);





subplot(4,1,2)
plot(f,m,'-r')
title('amplitudowe')


subplot(4,1,3)
plot(f,p*180/pi,'-r')
title('fazowe')

for k = 0:N-1;
    for n = 0:N-1;
    
        Wn = exp((1j*2*pi*k*n)/N);
        X1(k+1, n+1) = Wn;
    
    end
end

Xk = X1*Xk*1/N;

subplot(4,1,4)
plot(t,Xk,'g')
title('Po DFT i IDFT')
