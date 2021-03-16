clc;
close all;
clear all;
pkg load communications;


n = input("Enter length of codeword : ");
k = input("Enter length of data word : ");

%define matrix G with all zeros to get identity matrix
G = zeros(k,n);
for i = 1:k
    for j = 1:n
       if i==j
       G(i,j) = 1;
     elseif j>n-k+1
       fprintf("i = %d,j = %d,",i,j);
       G(i,j) = input(" Enter the element in parity matrix : ");
       end
    endfor
endfor
fprintf("\n");
disp("The generator matrix is : ");
disp(G);




L = 0: (2^k)-1; 
u = fliplr(de2bi(L));
c = rem(u*G,2);
disp("Codewords");
c

weight = sum(c,2);
weight