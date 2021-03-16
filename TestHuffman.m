clc;
clear all;
close all;
pkg load communications;

prob = input('Enter the probabilities:');
n = length(prob);
symbols = [1:n];

[dict] = huffmandict(symbols,sum(prob));

%disp(dict);

H = 0; % initialize entropy to 0
for k = 1:n
  H=H+prob(k)*log2(1/prob(k));
endfor




L=0; %initialize length to 0
for j=1:n
  L=L+prob(j)*length(dict{j});
endfor

disp(dict);

fprintf('Total entropy %d bits/symbol\n\n',H);
fprintf('Average length of codeword is %d\n\n',L);

eff = H/L*100;
fprintf('Effieciency of Huffman Code is %f \n\n',eff);
r = 100-eff;
fprintf('Redundancy of Huffman Code is %f \n\n',r);