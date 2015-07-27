using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change to your UID

	// Callback function for distance smaller than 30 cm (parameter has unit mm)
	static void DistanceReachedCB(BrickletDistanceIR sender, int distance)
	{
		System.Console.WriteLine("Distance: " + distance/10.0 + " cm");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletDistanceIR dir = new BrickletDistanceIR(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		dir.SetDebouncePeriod(10000);

		// Register threshold reached callback to function DistanceReachedCB
		dir.DistanceReached += DistanceReachedCB;

		// Configure threshold for "smaller than 30 cm" (unit is mm)
		dir.SetDistanceCallbackThreshold('<', 30*10, 0);

		System.Console.WriteLine("Press enter to exit");
		System.Console.ReadLine();
		ipcon.Disconnect();
	}
}
