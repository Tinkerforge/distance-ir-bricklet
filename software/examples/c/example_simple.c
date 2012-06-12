
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_distance_ir.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

int main() {
	// Create IP connection to brickd
	IPConnection ipcon;
	if(ipcon_create(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not create connection\n");
		exit(1);
	}

	// Create device object
	DistanceIR dist;
	distance_ir_create(&dist, UID); 

	// Add device to IP connection
	if(ipcon_add_device(&ipcon, &dist) < 0) {
		fprintf(stderr, "Could not connect to Bricklet\n");
		exit(1);
	}
	// Don't use device before it is added to a connection

	// Get current distance (unit is mm)
	uint16_t distance;
	if(distance_ir_get_distance(&dist, &distance) < 0) {
		fprintf(stderr, "Could not get value, probably timeout\n");
		exit(1);
	}

	printf("Distance: %f cm\n", distance/10.0);

	printf("Press ctrl+c to close\n");
	ipcon_join_thread(&ipcon); // Join mainloop of IP connection
}
