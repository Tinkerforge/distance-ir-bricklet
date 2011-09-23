using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback function for distance callback (parameter has unit mm)
	static void DistanceCB(ushort distance)
	{
		System.Console.WriteLine("Distance: " + distance/10.0 + " cm");
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletDistanceIR dir = new BrickletDistanceIR(UID); // Create device object
		ipcon.AddDevice(dir); // Add device to ip connection
		// Don't use device before it is added to a connection


		// Set Period for distance callback to 1s (1000ms)
		// Note: The distance callback is only called every second if the 
		//       distance has changed since the last call!
		dir.SetDistanceCallbackPeriod(1000);

		// Register distance callback to function DistanceCB
		dir.RegisterCallback(new BrickletDistanceIR.Distance(DistanceCB));

		System.Console.WriteLine("Press ctrl+c to exit");
		ipcon.JoinThread();
    }
}
