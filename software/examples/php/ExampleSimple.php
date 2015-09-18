<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDistanceIR.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDistanceIR;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$dir = new BrickletDistanceIR(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current distance (unit is mm)
$distance = $dir->getDistance();
echo "Distance: " . $distance/10.0 . " cm\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
