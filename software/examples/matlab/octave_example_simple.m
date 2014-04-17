function octave_example_simple()
    more off;
    
    HOST = "localhost";
    PORT = 4223;
    UID = "hJw"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    dist = java_new("com.tinkerforge.BrickletDistanceIR", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don"t use device before ipcon is connected

    % Get current distance (unit is mm)
    distance = dist.getDistance();
    fprintf("Distance: %g cm\n", distance/10.0);

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end
