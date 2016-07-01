#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Distance IR Bricklet

# Get current distance (unit is mm)
tinkerforge call distance-ir-bricklet $uid get-distance
