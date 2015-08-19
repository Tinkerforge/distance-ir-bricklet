#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletDistanceIR;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $dir = Tinkerforge::BrickletDistanceIR->new(&UID, $ipcon); # Create device object

# Callback subroutine for distance smaller than 30 cm (parameter has unit mm)
sub cb_distance_reached
{
    my ($distance) = @_;

    print "Distance: " . $distance/10.0 . " cm\n";
}

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$dir->set_debounce_period(10000);

# Register threshold reached callback to subroutine cb_distance_reached
$dir->register_callback($dir->CALLBACK_DISTANCE_REACHED, 'cb_distance_reached');

# Configure threshold for "smaller than 30 cm" (unit is mm)
$dir->set_distance_callback_threshold('<', 30*10, 0);

print "Press any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
