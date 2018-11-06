use std::{error::Error, io, thread};
use tinkerforge::{distance_ir_bricklet::*, ipconnection::IpConnection};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Distance IR Bricklet

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let distance_ir_bricklet = DistanceIRBricklet::new(UID, &ipcon); // Create device object

    ipcon.connect(HOST, PORT).recv()??; // Connect to brickd
                                        // Don't use device before ipcon is connected

    //Create listener for distance events.
    let distance_listener = distance_ir_bricklet.get_distance_receiver();
    // Spawn thread to handle received events. This thread ends when the distance_ir_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in distance_listener {
            println!("Distance: {}{}", event as f32 / 10.0, " cm");
        }
    });

    // Set period for distance listener to 0.2s (200ms)
    // Note: The distance callback is only called every 0.2 seconds
    //       if the distance has changed since the last call!
    distance_ir_bricklet.set_distance_callback_period(200);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
