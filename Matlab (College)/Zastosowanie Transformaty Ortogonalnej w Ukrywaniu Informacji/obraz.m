function W = obraz(n,g)

X=imread(g);
X=X(1:n,1:n,1);
X=im2double(X);
W = X;