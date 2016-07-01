#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletDistanceIR;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Distance IR Bricklet

# Callback subroutine for distance reached callback (parameter has unit mm)
sub cb_distance_reached
{
    my ($distance) = @_;

    print "Distance: " . $distance/10.0 . " cm\n";
}

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $dir = Tinkerforge::BrickletDistanceIR->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$dir->set_debounce_period(10000);

# Register distance reached callback to subroutine cb_distance_reached
$dir->register_callback($dir->CALLBACK_DISTANCE_REACHED, 'cb_distance_reached');

# Configure threshold for distance "smaller than 30 cm" (unit is mm)
$dir->set_distance_callback_threshold('<', 30*10, 0);

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
