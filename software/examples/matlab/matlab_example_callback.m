function matlab_example_callback()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletDistanceIR;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    dir = handle(BrickletDistanceIR(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register distance callback to function cb_distance
    set(dir, 'DistanceCallback', @(h, e) cb_distance(e));

    % Set period for distance callback to 0.2s (200ms)
    % Note: The distance callback is only called every 0.2 seconds
    %       if the distance has changed since the last call!
    dir.setDistanceCallbackPeriod(200);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for distance callback (parameter has unit mm)
function cb_distance(e)
    fprintf('Distance: %g cm\n', e.distance/10.0);
end
