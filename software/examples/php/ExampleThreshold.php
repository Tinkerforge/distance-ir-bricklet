<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDistanceIR.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDistanceIR;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Distance IR Bricklet

// Callback function for distance reached callback (parameter has unit mm)
function cb_distanceReached($distance)
{
    echo "Distance: " . $distance/10.0 . " cm\n";
}

$ipcon = new IPConnection(); // Create IP connection
$dir = new BrickletDistanceIR(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$dir->setDebouncePeriod(10000);

// Register distance reached callback to function cb_distanceReached
$dir->registerCallback(BrickletDistanceIR::CALLBACK_DISTANCE_REACHED,
                       'cb_distanceReached');

// Configure threshold for distance "smaller than 30 cm" (unit is mm)
$dir->setDistanceCallbackThreshold('<', 30*10, 0);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
