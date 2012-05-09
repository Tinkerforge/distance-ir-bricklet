<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDistanceIR.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDistanceIR;

$host = 'localhost';
$port = 4223;
$uid = '6Vw'; // Change to your UID

// Callback for distance smaller than 20cm
function cb_reached($distance)
{
    echo "Distance is smaller than 20cm: " . $distance / 10.0 . " cm\n";
}

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$dist = new BrickletDistanceIR($uid); // Create device object

$ipcon->addDevice($dist); // Add device to IP connection
// Don't use device before it is added to a connection

// Get threshold callbacks with a debounce time of 1 second (1000ms)
$dist->setDebouncePeriod(1000);

// Register threshold reached callback to function cb_reached
$dist->registerCallback(BrickletDistanceIR::CALLBACK_DISTANCE_REACHED, 'cb_reached');

// Configure threshold for "smaller than 20cm" (unit is mm)
$dist->setDistanceCallbackThreshold('<', 200, 0);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
