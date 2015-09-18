<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDistanceIR.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDistanceIR;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change to your UID

// Callback function for distance callback (parameter has unit mm)
function cb_distance($distance)
{
    echo "Distance: " . $distance/10.0 . " cm\n";
}

$ipcon = new IPConnection(); // Create IP connection
$dir = new BrickletDistanceIR(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Register distance callback to function cb_distance
$dir->registerCallback(BrickletDistanceIR::CALLBACK_DISTANCE, 'cb_distance');

// Set period for distance callback to 0.2s (200ms)
// Note: The distance callback is only called every 0.2 seconds
//       if the distance has changed since the last call!
$dir->setDistanceCallbackPeriod(200);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
