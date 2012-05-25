#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_distance_ir'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = '6Vw' # Change to your UID

ipcon = IPConnection.new HOST, PORT # Create IP connection to brickd
dir = BrickletDistanceIR.new UID # Create device object
ipcon.add_device dir # Add device to IP connection
# Don't use device before it is added to a connection

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
dir.set_debounce_period 10000

# Register threshold reached callback for distance smaller than 20cm
dir.register_callback BrickletDistanceIR::CALLBACK_DISTANCE_REACHED, do |distance|
  puts "Distance is smaller than 20cm: #{distance/10.0} cm"
end

# Configure threshold for "smaller than 20cm" (unit is mm)
dir.set_distance_callback_threshold '<', 200, 0

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
