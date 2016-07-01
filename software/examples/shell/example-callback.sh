#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Distance IR Bricklet

# Handle incoming distance callbacks (parameter has unit mm)
tinkerforge dispatch distance-ir-bricklet $uid distance &

# Set period for distance callback to 0.2s (200ms)
# Note: The distance callback is only called every 0.2 seconds
#       if the distance has changed since the last call!
tinkerforge call distance-ir-bricklet $uid set-distance-callback-period 200

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
