import com.tinkerforge.BrickletDistanceIR;
import com.tinkerforge.IPConnection;

public class ExampleThreshold {
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
		

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		dir.setDebouncePeriod(10000);

		// Configure threshold for "smaller than 20 cm" (unit is mm)
		dir.setDistanceCallbackThreshold('<', (short)200, (short)0);

		// Add and implement distance reached listener 
		// (called if distance is smaller than 20 cm)
		dir.addListener(new BrickletDistanceIR.DistanceReachedListener() {
			public void distanceReached(int distance) {
				System.out.println("Distance is smaller than 20cm: " + distance/10.0 + " cm");
			}
		});
		
		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}
