%skrypt obliczajacy widmo sygnalu oraz oddtwarajacy sygnal 
%na podstawie obliczonego widma
c=0;
for ii=1:length(A)
c=c+abs(A(ii,1))^2;
end

S=A*X;
S=S*A;
S=vpa(S);
S=double(S);

Y=A*S;
Y=Y*A;
Y=Y/(c^2);
Y = vpa(Y);
Y = double(Y);
Y=abs(Y);
blad=immse(X,Y);

figure(1)
subplot(1,2,1)
imshow(X);
title('obraz oryginalny ','fontsize',10)   

subplot(1,2,2)
imshow(Y);
title(['blad sredniokwadratowy= ' ,num2str(blad)], 'fontsize',10)   
 
figure(2)
imshow(S);
