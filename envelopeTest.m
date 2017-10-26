clc
clear all
close all
addpath('/Users/petteripulkkinen/DSP/SynthProject');

fs = 44100;
f = 440;
n = 1:4*fs;
test = sin(2*pi*f/fs*n);
A = 1;
D = 1;
S = 0.2;
R = 1;

E = envelope(fs,A,D,S,1,R);

soundsc(E.*test,fs)
