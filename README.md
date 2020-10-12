# BetheBlock
This code calculates the energy loss of particles traveling through materials. You specify your beam type by identifying the atomic, mass and electron number. The two former also apply to the material of the target.

The value d in the code refers to how thick the targer is and is computed by its definition : target density / target thickness.

The number of iterations defines the number of loops computed and the arrays displayed show the remaining TKE after traveling through a distance of d / (number of iterations).

The results defer from similar programms like LISE++ in terms of hundred of keV, but lead to the same conclusion: particles having smaller TKE have a higher cross section of interaction, thus resulting in bigger energy losses. The However, the Bethe formula is not recommended for acurate measurements.
