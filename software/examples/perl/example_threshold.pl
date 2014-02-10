#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletDistanceIR;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'hJY'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $dist = Tinkerforge::BrickletDistanceIR->new(&UID, $ipcon); # Create device object

# Callback function for distance callback (parameter has unit mm)
sub cb_reached
{
    my ($distance) = @_;
    print "\nDistance is smaller than 20cm: ".$distance/10.0." cm\n";
}
$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$dist->set_debounce_period(10000);

# Register threshold reached callback to function cb_reached
$dist->register_callback($dist->CALLBACK_DISTANCE_REACHED, 'cb_reached');

# Configure threshold for "smaller than 20cm" (unit is mm)
$dist->set_distance_callback_threshold('<', 200, 0);

print "\nPress any key to exit...\n";
<STDIN>;
$ipcon->disconnect();

