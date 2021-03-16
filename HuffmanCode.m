clc;
clear all;
close all;
pkg load communications;

p = input('Enter the probabilities:');
n= length(p);
symbols = [1:n];
avglen=0;
dict=huffmandict(symbols,p);
temp = dict;
t=dict(:,2);
#for (i=1:length(temp))
#  temp(i,2) = num2str(temp(i,2)); 
#endfor

disp('Huffman Code: ');
disp(temp);
printf('Enter the symbols between 1 to %d',n);
sym = input(':');
encode= huffmanenco(sym,dict);
disp(encode);

H=0;
i=0;
L=0;
mul = p
for (k=1:n)
  H = (H - (p(k)*log2(p(k))));
endfor
fprintf('Entropy: %f bits/symbol',H);

for (k=1:symbols)
  #L = L + (p(k)*i(k)); 
endfor
fprintf('L: %f bits/symbol',L);

N=H/L;
fprintf('Efficiency: %f %',N*100);

Y=1-N;
fprintf('Code Redundancy: %f %',Y*100);