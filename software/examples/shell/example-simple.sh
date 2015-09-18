#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change to your UID

# Get current distance (unit is mm)
tinkerforge call distance-ir-bricklet $uid get-distance
