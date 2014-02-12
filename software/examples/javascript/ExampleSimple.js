var IPConnection = require('Tinkerforge/IPConnection');
var BrickletDistanceIR = require('Tinkerforge/BrickletDistanceIR');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'hHE';// Change to your UID

var ipcon = new IPConnection();// Create IP connection
var dist = new BrickletDistanceIR(UID, ipcon);// Create device object

ipcon.connect(HOST, PORT,
    function(error) {
        console.log('Error: '+error);        
    }
);// Connect to brickd

// Don't use device before ipcon is connected
ipcon.on(IPConnection.CALLBACK_CONNECTED,
    function(connectReason) {
        // Get current distance (unit is mm)
        dist.getDistance(
            function(distance) {
                console.log('Distance: '+distance/10+' cm');
            },
            function(error) {
                console.log('Error: '+error);
            }
        );
    }
);

console.log("Press any key to exit ...");
process.stdin.on('data',
    function(data) {
        ipcon.disconnect();
        process.exit(0);
    }
);

