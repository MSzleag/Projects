function V = trans_lena(A,X)
%skrypt obliczajacy widmo sygnalu oraz oddtwarajacy sygnal 
%na podstawie obliczonego widma
c=0;
for ii=1:length(A)
c=c+abs(A(ii,1))^2;
end

S=A*X;
S=S*A;
%S = vpa(S);
%S = double(S);
V = S;

Y=A*S;
Y=Y*A;
Y=Y/(c^2);
%Y = vpa(Y);
%Y = double(Y);
Y=abs(Y);
