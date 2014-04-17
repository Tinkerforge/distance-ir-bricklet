function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletDistanceIR;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'hJw'; % Change to your UID
    
    ipcon = IPConnection(); % Create IP connection
    dist = BrickletDistanceIR(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current distance (unit is mm)
    distance = dist.getDistance();
    fprintf('Distance: %g cm\n', distance/10.0);

    input('Press any key to exit...\n', 's');
    ipcon.disconnect();
end
