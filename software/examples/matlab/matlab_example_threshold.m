function matlab_example_threshold
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletDistanceIR;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'hJw'; % Change to your UID
    
    ipcon = IPConnection(); % Create IP connection
    dist = BrickletDistanceIR(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 10 seconds (10000ms)
    dist.setDebouncePeriod(10000);

    % Register threshold reached callback to function cb_reached
    set(dist, 'DistanceReachedCallback', @(h, e) cb_reached(e));

    % Configure threshold for "smaller than 20cm" (unit is mm)
    dist.setDistanceCallbackThreshold('<', 200, 0);

    input('Press any key to exit...\n', 's');
    ipcon.disconnect();
end

% Callback for distance smaller than 20cm
function cb_reached(e)
    fprintf('Distance is smaller than 20cm: %g cm\n', e.distance/10.0),
end
