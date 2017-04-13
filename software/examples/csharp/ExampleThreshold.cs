using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your Distance IR Bricklet

	// Callback function for distance reached callback (parameter has unit mm)
	static void DistanceReachedCB(BrickletDistanceIR sender, int distance)
	{
		Console.WriteLine("Distance: " + distance/10.0 + " cm");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletDistanceIR dir = new BrickletDistanceIR(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		dir.SetDebouncePeriod(10000);

		// Register distance reached callback to function DistanceReachedCB
		dir.DistanceReachedCallback += DistanceReachedCB;

		// Configure threshold for distance "smaller than 30 cm" (unit is mm)
		dir.SetDistanceCallbackThreshold('<', 30*10, 0);

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
