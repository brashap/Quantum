n =175; # turns (originally 25 turns)
r = 2.25*2.54/100; #m; Radius of coils
I = 4.5; #A; Current through wire
d = 2.25*2.54/100; #m; distance between coils
#z = [-1*d:.001:1*d]; #m distance from middle of coils
z = [-.005:.001:.005];
z1 = -d/2; #m; location of coil 1
z2 = +d/2; #m; location of coil 2
pi = 3.141529; #pi
mu0 = 4*pi*10^-7; #Tm/A; mag permittivity?

Bz_l = 10000*mu0*r^2*n*I./(2*((z-z1).^2+r^2).^(3/2)); #G
Bz_r = -10000*mu0*r^2*n*I./(2*((z-z2).^2+r^2).^(3/2)); #G
Bz = Bz_l+Bz_r; #G
offset = min(Bz);

figure;
plot(z,Bz_l); hold on;
plot(z,Bz_r);
plot(z,Bz);
legend("Bz1", "Bz2", "Bz")
#legend("Bz")

Grad = (max(Bz)-min(Bz)); #G difference over 1 cm

circ = pi*2*r; #meters, circumference = pi * diameter
length = circ*n*3.28; #feet, length = circumference * n * convert-to-ft

#50 feet
#5A, 50 turns = 8 G/cm
#10A, 50 turns = 16 G/cm
#10A, 25 turns = 8 G/cm
