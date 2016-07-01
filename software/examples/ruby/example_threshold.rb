#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_distance_ir'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your Distance IR Bricklet

ipcon = IPConnection.new # Create IP connection
dir = BrickletDistanceIR.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
dir.set_debounce_period 10000

# Register distance reached callback (parameter has unit mm)
dir.register_callback(BrickletDistanceIR::CALLBACK_DISTANCE_REACHED) do |distance|
  puts "Distance: #{distance/10.0} cm"
end

# Configure threshold for distance "smaller than 30 cm" (unit is mm)
dir.set_distance_callback_threshold '<', 30*10, 0

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
