#!/usr/bin/env python
# -*- coding: utf-8 -*-  

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_distance_ir import DistanceIR

# Callback for distance smaller than 20cm
def cb_reached(distance):
    print('Distance is smaller than 20cm: ' + str(distance/10.0) + ' cm')

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    dist = DistanceIR(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Get threshold callbacks with a debounce time of 10 seconds (10000ms)
    dist.set_debounce_period(10000)

    # Register threshold reached callback to function cb_reached
    dist.register_callback(dist.CALLBACK_DISTANCE_REACHED, cb_reached)

    # Configure threshold for "smaller than 20cm" (unit is mm)
    dist.set_distance_callback_threshold('<', 200, 0)

    raw_input('Press key to exit\n') # Use input() in Python 3
    ipcon.disconnect()
