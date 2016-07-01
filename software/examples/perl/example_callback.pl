#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletDistanceIR;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Distance IR Bricklet

# Callback subroutine for distance callback (parameter has unit mm)
sub cb_distance
{
    my ($distance) = @_;

    print "Distance: " . $distance/10.0 . " cm\n";
}

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $dir = Tinkerforge::BrickletDistanceIR->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Register distance callback to subroutine cb_distance
$dir->register_callback($dir->CALLBACK_DISTANCE, 'cb_distance');

# Set period for distance callback to 0.2s (200ms)
# Note: The distance callback is only called every 0.2 seconds
#       if the distance has changed since the last call!
$dir->set_distance_callback_period(200);

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
