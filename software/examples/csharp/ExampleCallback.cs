using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change to your UID

	// Callback function for distance callback (parameter has unit mm)
	static void DistanceCB(BrickletDistanceIR sender, int distance)
	{
		System.Console.WriteLine("Distance: " + distance/10.0 + " cm");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletDistanceIR dir = new BrickletDistanceIR(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Set period for distance callback to 0.2s (200ms)
		// Note: The distance callback is only called every 0.2 seconds
		//       if the distance has changed since the last call!
		dir.SetDistanceCallbackPeriod(200);

		// Register distance callback to function DistanceCB
		dir.Distance += DistanceCB;

		System.Console.WriteLine("Press enter to exit");
		System.Console.ReadLine();
		ipcon.Disconnect();
	}
}
