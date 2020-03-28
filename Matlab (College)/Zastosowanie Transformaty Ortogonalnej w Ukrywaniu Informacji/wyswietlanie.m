clear all;
close all;

B1 = porownanie_macierz(0.1,5,5);
B2 = porownanie_macierz(0.2,5,5);
B3 = porownanie_macierz(0.5,5,5);
B4 = porownanie_macierz(0.7,5,5);
B5 = porownanie_macierz(0.9,5,5);
B6 = porownanie_macierz(1,5,5);
B7 = porownanie_macierz(1.2,5,5);
B8 = porownanie_macierz(0.1,7,7);
B9 = porownanie_macierz(0.2,7,7);
B10 = porownanie_macierz(0.5,7,7);
B11 = porownanie_macierz(0.7,7,7);
B12 = porownanie_macierz(0.9,7,7);
B13 = porownanie_macierz(1,7,7);
B14 = porownanie_macierz(1.2,7,7);

g1 = 'lena512.jpg';
g2 = 'lena_64.jpg';
g3 = 'lena_32.jpg';
g4 = 'lena_128.jpg';
g5 = 'lena_16.jpg';

W1 = obraz(512,g1);
W2 = obraz(64,g2);
W3 = obraz(32,g3);
W4 = obraz(128,g4);
W5 = obraz(16,g5);

V1 = trans_lena(B1,W3);
V2 = trans_lena(B2,W3);
V3 = trans_lena(B3,W3);
V4 = trans_lena(B4,W3);
V5 = trans_lena(B5,W3);
V6 = trans_lena(B6,W3);
V7 = trans_lena(B7,W3);
V8 = trans_lena(B8,W4);
V9 = trans_lena(B9,W4);
V10 = trans_lena(B10,W4);
V11 = trans_lena(B11,W4);
V12 = trans_lena(B12,W4);
V13 = trans_lena(B13,W4);
V14 = trans_lena(B14,W4);

Z1 = trans_wyj(B1,W3);
Z2 = trans_wyj(B2,W3);
Z3 = trans_wyj(B3,W3);
Z4 = trans_wyj(B4,W3);
Z5 = trans_wyj(B5,W3);
Z6 = trans_wyj(B6,W3);
Z7 = trans_wyj(B7,W3);
Z8 = trans_wyj(B8,W4);
Z9 = trans_wyj(B9,W4);
Z10 = trans_wyj(B10,W4);
Z11 = trans_wyj(B11,W4);
Z12 = trans_wyj(B12,W4);
Z13 = trans_wyj(B13,W4);
Z14 = trans_wyj(B14,W4);


figure(1)

subplot(1,3,1)
imshow(W3)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V1)
title('Spectrum for a = 0.1','fontsize',10)
subplot(1,3,3)
imshow(Z1)
title('Image after reconstruction','fontsize',10)


figure(2)

subplot(1,3,1)
imshow(W3)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V2)
title('Spectrum for a = 0.2','fontsize',10)
subplot(1,3,3)
imshow(Z2)
title('Image after reconstruction','fontsize',10)


figure(3)

subplot(1,3,1)
imshow(W3)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V3)
title('Spectrum for a = 0.5','fontsize',10)
subplot(1,3,3)
imshow(Z3)
title('Image after reconstruction','fontsize',10)


figure(4)

subplot(1,3,1)
imshow(W3)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V4)
title('Spectrum for a = 0.7','fontsize',10)
subplot(1,3,3)
imshow(Z4)
title('Image after reconstruction','fontsize',10)


figure(5)

subplot(1,3,1)
imshow(W3)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V5)
title('Spectrum for a = 0.9','fontsize',10)
subplot(1,3,3)
imshow(Z5)
title('Image after reconstruction','fontsize',10)


figure(6)

subplot(1,3,1)
imshow(W3)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V6)
title('Spectrum for a = 1','fontsize',10)
subplot(1,3,3)
imshow(Z6)
title('Image after reconstruction','fontsize',10)


figure(7)

subplot(1,3,1)
imshow(W3)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V7)
title('Spectrum for a = 1.2','fontsize',10)
subplot(1,3,3)
imshow(Z7)
title('Image after reconstruction','fontsize',10)


figure(8)

subplot(1,3,1)
imshow(W4)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V8)
title('Spectrum for a = 0.1','fontsize',10)
subplot(1,3,3)
imshow(Z8)
title('Image after reconstruction','fontsize',10)


figure(9)

subplot(1,3,1)
imshow(W4)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V9)
title('Spectrum for a = 0.2','fontsize',10)
subplot(1,3,3)
imshow(Z9)
title('Image after reconstruction','fontsize',10)


figure(10)

subplot(1,3,1)
imshow(W4)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V10)
title('Spectrum for a = 0.5','fontsize',10)
subplot(1,3,3)
imshow(Z10)
title('Image after reconstruction','fontsize',10)


figure(11)

subplot(1,3,1)
imshow(W4)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V11)
title('Spectrum for a = 0.7','fontsize',10)
subplot(1,3,3)
imshow(Z11)
title('Image after reconstruction','fontsize',10)


figure(12)

subplot(1,3,1)
imshow(W4)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V12)
title('Spectrum for a = 0.9','fontsize',10)
subplot(1,3,3)
imshow(Z12)
title('Image after reconstruction','fontsize',10)


figure(13)

subplot(1,3,1)
imshow(W4)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V13)
title('Spectrum for a = 1','fontsize',10)
subplot(1,3,3)
imshow(Z13)
title('Image after reconstruction','fontsize',10)


figure(14)

subplot(1,3,1)
imshow(W4)
title('Original Image','fontsize',10)
subplot(1,3,2)
imshow(V14)
title('Spectrum for a = 1.2','fontsize',10)
subplot(1,3,3)
imshow(Z14)
title('Image after reconstruction','fontsize',10)

