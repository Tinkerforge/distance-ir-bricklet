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

# Register distance callback (parameter has unit mm)
dir.register_callback(BrickletDistanceIR::CALLBACK_DISTANCE) do |distance|
  puts "Distance: #{distance/10.0} cm"
end

# Set period for distance callback to 0.2s (200ms)
# Note: The distance callback is only called every 0.2 seconds
#       if the distance has changed since the last call!
dir.set_distance_callback_period 200

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
