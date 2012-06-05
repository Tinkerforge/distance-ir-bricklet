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

# Set Period for distance callback to 0.2s (200ms)
# Note: The callback is only called every 200ms if the 
#       distance has changed since the last call!
dir.set_distance_callback_period 200

# Register distance callback (parameter has unit mm)
dir.register_callback(BrickletDistanceIR::CALLBACK_DISTANCE) do |distance|
  puts "Distance: #{distance/10.0} cm"
end

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
