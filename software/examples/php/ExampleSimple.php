<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDistanceIR.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDistanceIR;

const HOST = 'localhost';
const PORT = 4223;
const UID = '6Vw'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$dist = new BrickletDistanceIR(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current distance (unit is mm)
$distance = $dist->getDistance() / 10.0;

echo "Distance: $distance cm\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
