function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletDistanceIR;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Distance IR Bricklet

    ipcon = IPConnection(); % Create IP connection
    dir = handle(BrickletDistanceIR(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current distance (unit is mm)
    distance = dir.getDistance();
    fprintf('Distance: %g cm\n', distance/10.0);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end
