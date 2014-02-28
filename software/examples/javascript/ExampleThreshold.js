var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'hHE'; // Change to your UID

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var dist = new Tinkerforge.BrickletDistanceIR(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function(error) {
        console.log('Error: '+error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function(connectReason) {
        // Get threshold callbacks with a debounce time of 10 seconds (10000ms)
        dist.setDebouncePeriod(10000);
        // Configure threshold for "smaller than 20cm" (unit is mm)
        dist.setDistanceCallbackThreshold('<', 200, 0);
    }
);

// Register threshold reached callback
dist.on(Tinkerforge.BrickletDistanceIR.CALLBACK_DISTANCE_REACHED,
    // Callback for distance smaller than 20cm
    function(distance) {
        console.log('Distance is smaller than 20cm: '+distance/10+' cm');
    }
);

console.log("Press any key to exit ...");
process.stdin.on('data',
    function(data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
