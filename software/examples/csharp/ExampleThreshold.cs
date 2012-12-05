using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback for distance smaller than 20 cm
	static void ReachedCB(object sender, int distance)
	{
		System.Console.WriteLine("Distance is smaller than 20 cm: " + distance/10.0 + " cm");
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletDistanceIR dir = new BrickletDistanceIR(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 1 seconds (1000ms)
		dir.SetDebouncePeriod(1000);

		// Register threshold reached callback to function ReachedCB
		dir.DistanceReached += ReachedCB;

		// Configure threshold for "smaller than 20 cm" (unit is mm)
		dir.SetDistanceCallbackThreshold('<', 200, 0);

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
	}
}
