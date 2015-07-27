#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_distance_ir'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change to your UID

ipcon = IPConnection.new # Create IP connection
dir = BrickletDistanceIR.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Get current distance (unit is mm)
distance = dir.get_distance
puts "Distance: #{distance/10.0} cm"

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
