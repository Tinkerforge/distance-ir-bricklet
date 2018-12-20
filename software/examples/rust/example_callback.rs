use std::{error::Error, io, thread};
use tinkerforge::{distance_ir_bricklet::*, ip_connection::IpConnection};

const HOST: &str = "localhost";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Distance IR Bricklet.

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection.
    let dir = DistanceIrBricklet::new(UID, &ipcon); // Create device object.

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd.
                                          // Don't use device before ipcon is connected.

    let distance_receiver = dir.get_distance_callback_receiver();

    // Spawn thread to handle received callback messages.
    // This thread ends when the `dir` object
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for distance in distance_receiver {
            println!("Distance: {} cm", distance as f32 / 10.0);
        }
    });

    // Set period for distance receiver to 0.2s (200ms).
    // Note: The distance callback is only called every 0.2 seconds
    //       if the distance has changed since the last call!
    dir.set_distance_callback_period(200);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
