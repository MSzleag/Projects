function Z = trans_wyj(A,X)
c=0;
for ii=1:length(A)
c=c+abs(A(ii,1))^2;
end

S=A*X;
S=S*A;
%S = vpa(S);
%S = double(S);

Y=A*S;
Y=Y*A;
Y=Y/(c^2);
Y=abs(Y);
%Y = vpa(Y);
%Y = double(Y);
Z = Y;
