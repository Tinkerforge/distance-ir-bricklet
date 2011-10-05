import com.tinkerforge.BrickletDistanceIR;
import com.tinkerforge.IPConnection;

public class ExampleSimple {
	private static final String host = new String("localhost");
	private static final int port = 4223;
	private static final String UID = new String("ABC"); // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		// Create connection to brickd
		IPConnection ipcon = new IPConnection(host, port); // Can throw IOException

		BrickletDistanceIR dir = new BrickletDistanceIR(UID); // Create device object

		// Add device to ip connection
		ipcon.addDevice(dir); // Can throw IPConnection.TimeoutException
		// Don't use device before it is added to a connection
		

		// Get current distance (unit is mm)
		int distance = dir.getDistance(); // Can throw IPConnection.TimeoutException

		System.out.println("Distance: " + distance/10.0 + " cm");
		
		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}