%% sinusoid oscillator because of FM synthesis. but it can be expanded

% input: give the frequency of the wave, duration in seconds and sampling
% rate. 

function [wave, t] = myoscillator(f, duration, fs)

    % f = perus taajuus
    % duration = kesto sekunteina
    % fs = naytteenottotaajuus. suurempi, sita tarkempi kuvaaja

    t = 0:1/fs:duration;

    wave = sin(2*pi*f*t);
    
    % tarkista plot(t, wave);

end