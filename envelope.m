% ADSR envelope

% returns: env = ADSR envelope, length (a + d + s + r) * fs;

function env = envelope(fs, a_time, d_time, s_level, s_time, r_time)

    % fs = sampling frequency

    % attack
    a_samples = a_time * fs;
    att = linspace(0, 1, a_samples);
    
    % decay
    d_samples = d_time * fs;
    dec = linspace(1, s_level, d_samples);
    
    % sustain
    s_samples = s_time * fs;
    sus = ones(1, round(s_samples)) * s_level;
    
    % release
    r_samples = r_time * fs;
    rel = linspace(s_level, 0, r_samples);
    
    env = [att dec sus rel];
    figure, plot(env)
    title('envelope');
    
end