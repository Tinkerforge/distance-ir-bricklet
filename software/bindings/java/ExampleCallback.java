import com.tinkerforge.BrickletDistanceIR;
import com.tinkerforge.IPConnection;

public class ExampleCallback {
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
		

		// Set Period for distance callback to 1s (1000ms)
		// Note: The distance callback is only called every second if the 
		//       distance has changed since the last call!
		dir.setDistanceCallbackPeriod(1000);

		// Add and implement distance listener (called if distance changes)
		dir.addListener(new BrickletDistanceIR.DistanceListener() {
			public void distance(int distance) {
				System.out.println("Distance: " + distance/10.0 + " cm");
			}
		});
		
		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}
