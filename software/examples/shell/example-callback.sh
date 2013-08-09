#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# set period for distance callback to 0.2s (200ms)
# note: the distance callback is only called every 200ms if the
#       distance has changed since the last call!
tinkerforge call distance-ir-bricklet $uid set-distance-callback-period 1000

# handle incoming distance callbacks (unit is mm)
tinkerforge dispatch distance-ir-bricklet $uid distance
