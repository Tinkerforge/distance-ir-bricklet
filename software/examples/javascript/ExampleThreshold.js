var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change XYZ to the UID of your Distance IR Bricklet

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var dir = new Tinkerforge.BrickletDistanceIR(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function (connectReason) {
        // Get threshold callbacks with a debounce time of 10 seconds (10000ms)
        dir.setDebouncePeriod(10000);

        // Configure threshold for distance "smaller than 30 cm"
        dir.setDistanceCallbackThreshold('<', 30*10, 0);
    }
);

// Register distance reached callback
dir.on(Tinkerforge.BrickletDistanceIR.CALLBACK_DISTANCE_REACHED,
    // Callback function for distance reached callback
    function (distance) {
        console.log('Distance: ' + distance/10.0 + ' cm');
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
