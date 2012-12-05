using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletDistanceIR dir = new BrickletDistanceIR(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get current distance (unit is mm)
		int distance = dir.GetDistance();

		System.Console.WriteLine("Distance: " + distance/10.0 + " cm");

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
	}
}
