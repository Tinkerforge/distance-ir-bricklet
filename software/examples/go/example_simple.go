package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/distance_ir_bricklet"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your Distance IR Bricklet.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	dir, _ := distance_ir_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	// Get current distance.
	distance, _ := dir.GetDistance()
	fmt.Printf("Distance: %f cm\n", float64(distance)/10.0)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
