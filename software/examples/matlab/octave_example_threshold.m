function octave_example_threshold
    more off;
    
    HOST = "localhost";
    PORT = 4223;
    UID = "hJw"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    dist = java_new("com.tinkerforge.BrickletDistanceIR", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don"t use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 10 seconds (10000ms)
    dist.setDebouncePeriod(10000);

    % Register threshold reached callback to function cb_reached
    dist.addDistanceReachedListener("cb_reached");

    % Configure threshold for "smaller than 20cm" (unit is mm)
    dist.setDistanceCallbackThreshold("<", 200, 0);

    input("\nPress any key to exit...\n", "s");
    ipcon.disconnect();
end

% Callback for distance smaller than 20cm
function cb_reached(distance)
    fprintf("Distance is smaller than 20cm: %g cm\n", distance/10),
end
