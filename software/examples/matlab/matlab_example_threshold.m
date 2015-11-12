function matlab_example_threshold()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletDistanceIR;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    dir = handle(BrickletDistanceIR(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 10 seconds (10000ms)
    dir.setDebouncePeriod(10000);

    % Register distance reached callback to function cb_distance_reached
    set(dir, 'DistanceReachedCallback', @(h, e) cb_distance_reached(e));

    % Configure threshold for distance "smaller than 30 cm" (unit is mm)
    dir.setDistanceCallbackThreshold('<', 30*10, 0);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for distance reached callback (parameter has unit mm)
function cb_distance_reached(e)
    fprintf('Distance: %g cm\n', e.distance/10.0);
end
