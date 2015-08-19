#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletDistanceIR;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $dir = Tinkerforge::BrickletDistanceIR->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current distance (unit is mm)
my $distance = $dir->get_distance();
print "Distance: " . $distance/10.0 . " cm\n";

print "Press any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
