using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback for distance smaller than 20 cm
	static void ReachedCB(ushort distance)
	{
		System.Console.WriteLine("Distance is smaller than 20 cm: " + distance/10.0 + " cm");
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletDistanceIR dir = new BrickletDistanceIR(UID); // Create device object
		ipcon.AddDevice(dir); // Add device to ip connection
		// Don't use device before it is added to a connection


		// Get threshold callbacks with a debounce time of 1 seconds (1000ms)
		dir.SetDebouncePeriod(1000);

		// Register threshold reached callback to function ReachedCB
		dir.RegisterCallback(new BrickletDistanceIR.DistanceReached(ReachedCB));

		// Configure threshold for "smaller than 20 cm" (unit is mm)
		dir.SetDistanceCallbackThreshold('<', 200, 0);

		System.Console.WriteLine("Press ctrl+c to exit");
		ipcon.JoinThread();
    }
}
