#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Distance IR Bricklet

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
tinkerforge call distance-ir-bricklet $uid set-debounce-period 10000

# Handle incoming distance reached callbacks (parameter has unit mm)
tinkerforge dispatch distance-ir-bricklet $uid distance-reached &

# Configure threshold for distance "smaller than 30 cm" (unit is mm)
tinkerforge call distance-ir-bricklet $uid set-distance-callback-threshold smaller 300 0

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
