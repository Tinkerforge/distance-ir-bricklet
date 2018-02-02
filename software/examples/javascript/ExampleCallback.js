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
        // Set period for distance callback to 0.2s (200ms)
        // Note: The distance callback is only called every 0.2 seconds
        //       if the distance has changed since the last call!
        dir.setDistanceCallbackPeriod(200);
    }
);

// Register distance callback
dir.on(Tinkerforge.BrickletDistanceIR.CALLBACK_DISTANCE,
    // Callback function for distance callback
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
