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

# Get current distance (unit is mm)
distance = dir.get_distance / 10.0
puts "Distance: #{distance} cm"

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
