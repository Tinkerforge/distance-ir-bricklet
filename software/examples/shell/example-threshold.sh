#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# get threshold callbacks with a debounce time of 1 second (1000ms)
tinkerforge call distance-ir-bricklet $uid set-debounce-period 1000

# configure threshold for "smaller than 20cm" (unit is mm)
tinkerforge call distance-ir-bricklet $uid set-distance-callback-threshold smaller 200 0

# handle incoming distance-reached callbacks (unit is mm)
tinkerforge dispatch distance-ir-bricklet $uid distance-reached\
 --execute "echo Distance is smaller than 20cm: {distance} mm"
