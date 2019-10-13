#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int main(){ 
	// Solving the formula Gm/r*r
const double grav_const = 6.6742e-11; // The "G" in the formula
const double earth_mass = 5.975e24; // The "m" in the formula double radius = 6.37814e6; // The "r" in the formula
double grav_accel = 0; // The "a" in the formula
double vel = 0;
long double radius;
cin>>radius;
while (radius)// < 10000)
{
grav_accel = grav_const * (earth_mass / pow(radius, 2)); // The blunt gladius
//usleep(1000000); // Pause for a second
vel = vel + grav_accel; // Cause the velocity to be increased each second by
// the gravity acceleration
radius = radius - vel; // Reduce the radius by the velocity each second
cout<<"\nAccelartion: "<<grav_accel<<" Radius: "<<radius;
}
//return 0;
}