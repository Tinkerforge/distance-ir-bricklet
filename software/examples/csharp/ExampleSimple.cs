using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletDistanceIR dir = new BrickletDistanceIR(UID); // Create device object
		ipcon.AddDevice(dir); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Get current distance (unit is mm)
		ushort distance = dir.GetDistance();

		System.Console.WriteLine("Distance: " + distance/10.0 + " cm");

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
		ipcon.Destroy();
	}
}
