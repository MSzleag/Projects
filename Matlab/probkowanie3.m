function [] = probkowanie3()

N = 60; 
n = 0:1:N-1; 

dt = 1/N;
t = dt * n; 

x = sin(2*pi*10*t);
X = fft(x); 

df = 1 / (N*dt); 
f = df * n; 

figure(2) 
    subplot(2,1,1); 
    plot(f,abs(X)); subplot(2,1,2); 
    plot(f(1:N/2+1),abs(X(1:N/2+1) / N/2)); 

figure(1) 
    f_axis = linspace(-N/2,N/2-1,N); 
    plot(f_axis,abs(fftshift(X)));

end