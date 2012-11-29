<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDistanceIR.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDistanceIR;

$host = 'localhost';
$port = 4223;
$uid = '6Vw'; // Change to your UID

// Callback function for distance callback (parameter has unit mm)
function cb_distance($distance)
{
    echo "Distance: " . $distance / 10.0 . " cm\n";
}

$ipcon = new IPConnection(); // Create IP connection
$dist = new BrickletDistanceIR($uid, $ipcon); // Create device object

$ipcon->connect($host, $port); // Connect to brickd
// Don't use device before ipcon is connected

// Set Period for distance callback to 0.2s (200ms)
// Note: The callback is only called every 200ms if the 
//       distance has changed since the last call!
$dist->setDistanceCallbackPeriod(200);

// Register illuminance callback to function cb_illuminance
$dist->registerCallback(BrickletDistanceIR::CALLBACK_DISTANCE, 'cb_distance');

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
