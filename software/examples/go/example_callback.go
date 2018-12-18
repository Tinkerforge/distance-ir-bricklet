package main

import (
	"fmt"
	"github.com/tinkerforge/go-api-bindings/distance_ir_bricklet"
	"github.com/tinkerforge/go-api-bindings/ipconnection"
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

	dir.RegisterDistanceCallback(func(distance uint16) {
		fmt.Printf("Distance: %f cm\n", float64(distance)/10.0)
	})

	// Set period for distance receiver to 0.2s (200ms).
	// Note: The distance callback is only called every 0.2 seconds
	//       if the distance has changed since the last call!
	dir.SetDistanceCallbackPeriod(200)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

}
