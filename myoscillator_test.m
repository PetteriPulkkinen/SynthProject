%% testing myoscillator.m

clc;
close all;
clear all;
addpath('/Users/petteripulkkinen/DSP/SynthProject')



% [wave, t] = myoscillator(f, duration, fs)
% f = perus taajuus
% duration = kesto sekunteina
% fs = naytteenottotaajuus

% https://en.wikipedia.org/wiki/Frequency_modulation_synthesis
% FM(t) ~ A*sin(w_c*t + beta*sin(w_m*t) )
% jossa w_c = f_c*2*pi ja alkuperainen modulaatiosignaali B*sin(f_m*2*pi*t)
% beta on modulaatioindeksi


f_c = 300;
f_m = 400;
fs = 321;
[sig, t] = myoscillator(f_c,1,fs);     % olkoon carrier signal, kesto 1s 
[sig2, t2] = myoscillator(f_m, 1,fs);   % olkoon modulation signal

%let's keep t=t2 for simplicity

% olkoon FM signal, amplitudi = 1 ja modulaatioindeksi beta = 1
sig3 = sin(2*pi*f_c*t2 + sin(2*pi*f_m*t2));


subplot(3, 1, 1);
plot(t,sig); 
title('carrier')
subplot(3, 1, 2);
plot(t2,sig2);
title('modulation')
subplot(3, 1, 3);
plot(t2,sig3);
title('FM signal')


    

















