import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletDistanceIR;

public class ExampleCallback {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your Distance IR Bricklet
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletDistanceIR dir = new BrickletDistanceIR(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Add distance listener (parameter has unit mm)
		dir.addDistanceListener(new BrickletDistanceIR.DistanceListener() {
			public void distance(int distance) {
				System.out.println("Distance: " + distance/10.0 + " cm");
			}
		});

		// Set period for distance callback to 0.2s (200ms)
		// Note: The distance callback is only called every 0.2 seconds
		//       if the distance has changed since the last call!
		dir.setDistanceCallbackPeriod(200);

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
