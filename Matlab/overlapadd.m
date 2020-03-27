close All
clear All
clc

x=[1,2,5,3];		
h=[2,2,-1];
L=10;
lx=length(x);
lh=length(h);
x2=[x zeros(1,mod(-lx,L))];
lx2=length(x2);
h2=[h zeros(1,L-1)];
H=fft(h2,L+lh-1);
lx2=lx2/L;
index=1:L;
X=[zeros(lh-1)];

for stage=1:lx2
    xm=[x2(index) zeros(1,lh-1)];		
    X1=fft(xm,L+lh-1);
    Y=X1.*H;
    Y=ifft(Y);
    Z=X((length(X)-lh+2):length(X))+Y(1:lh-1);
    X=[X(1:(stage-1)*L) Z Y(lh:lh+L-1)];
    index=stage*L+1:(stage+1)*L;
end

i=1:lx+lh-1;
X=X(i);

similarity=corrcoef(X,convolution);		

figure()
stem(X,'r');
title('Overlap Add')
xlabel('n');
ylabel('y(n)');
