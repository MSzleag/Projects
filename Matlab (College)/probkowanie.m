function [a]=probkowanie()

fs = 60;

dt = ((1/fs)*linspace(0,4*pi,60))';

f1 = 5;
f2 = 40;
f3 = 65;

y1 = sin(2*pi*f1*dt);

y2 = sin(2*pi*f2*dt);

y3 = sin(2*pi*f3*dt);

figure(1)
    subplot(311)
 plot(dt,y1,'b-o')
 xlabel('czas')
    ylabel('1 sinus')
 
figure(1)
    subplot(312)
 plot(dt,y2,'r-o')
 xlabel('czas')
    ylabel('2 sinus')

 figure(1)
    subplot(313)
 plot(dt,y3,'k-o')
 xlabel('czas')
    ylabel('3 sinus')


 

 