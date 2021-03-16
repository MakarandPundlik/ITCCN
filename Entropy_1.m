clc;
close all;
clear all;
p=0:0.001:1;
h=-(p.*log2(p))-((1-p).*log2((1-p)));
plot(p,h);
title('entropy vs probability curve');
xlabel('probability');
ylabel('entropy');