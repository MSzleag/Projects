%skrypt obliczaj¹cy macierz transformaty ortogonalnej

clear;
close all;
N=4;    
n=2^N;      %rozmiar macierzy gdzie N=wykladnik 
M=4;
el=2^M;       %rozmiar podmacierzy transformaty zmodyfikowanej

A=ones(n);
a=0.1;   %wspolczynnik a rzeczywisty

for iterator=1:n
 if  iterator<=el
   A(1,iterator)=A(1,iterator)*a^iterator;
 else 
   A(1,iterator)=0;
 end
end

k=2;
for o=2:N
  k=[k 2^o k];
end

for  iterator=2:n/4
  for j=1:k(iterator-1):n
  A(iterator,j:j+k(iterator-1)-1)=flip(A((iterator-1),j:j+k(iterator-1)-1));
  end
end

A(n/2,1:n/2)=flip(A(1,1:n/2));
A(n/2,(n/2+1):end)=flip(A(1,(n/2+1):end));
p=n/2-1;
iterator=1;

while  p>n/4
  for j=1:k(iterator):n
  A(p,j:j+k(iterator)-1)=flip(A((p+1),j:j+k(iterator)-1));
  end
iterator=iterator+1;
p=p-1;
end

A(n/2+1:n,1:n/2)=A(1:n/2,n/2+1:n);
A(n/2+1:n, n/2+1:end)=A(1:n/2,1:n/2);

A=A.*hadamard(n);
A = vpa(A);
A = double(A);
   