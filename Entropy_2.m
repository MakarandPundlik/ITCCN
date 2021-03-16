clc;
close all;
clear all;

prob = input('Enter the probabilities:');
n = length(prob);

%initialize entropy to 0
H = 0;
for k = 1:n
  H+=prob(k)*log2(1/prob(k)); 
endfor

fprintf('Total entropy %d bits/symbol\n\n',H);
