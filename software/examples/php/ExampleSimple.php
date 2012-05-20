<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDistanceIR.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDistanceIR;

$host = 'localhost';
$port = 4223;
$uid = '6Vw'; // Change to your UID

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$dist = new BrickletDistanceIR($uid); // Create device object

$ipcon->addDevice($dist); // Add device to IP connection
// Don't use device before it is added to a connection

// Get current distance (unit is mm)
$distance = $dist->getDistance() / 10.0;

echo "Distance: $distance cm\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->destroy();

?>
