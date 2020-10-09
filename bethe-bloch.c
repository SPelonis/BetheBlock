#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define pi 3.14159265358979323846
#define c 2.997925*pow(10,8) /* in m/s  */
#define epsilon_0 55.263
#define m_e 0.510998
#define e 1.602*pow(10,-19)
#define N_A 6.022*pow(10,23)

int main(){

FILE *fp; 
fp = fopen("bethe_bloch_data", "w"); 
fprintf(fp,"Distance [μm] TKE [MeV]\n");

double result[1000];   /* the result of the Bethe-Block formula in eV  */
double charge = 0; 
double energy = 0, energy_t[1000];
double density = 0; /* the electron density of the material */
double beta = 0, beta_t[1000];
double velocity = 0;
double A_t = 0;  /* of the target */
double Z_t = 0; /* of the target */
double Z_p = 0; /* of the projectile */
double A_p = 0; /* of the projectile */
int x = 0, loop_n = 0;
double i = 0, thickness = 0;
double d = 0; /* this is the distance that the projectile will travel in the target */
double m_p; /* this is the mass of the projectile in ev/c^2 */


printf("\n Define the atomic number of the target : ");
scanf("%lf", &Z_t);
printf("\n Define the mass number of the target : ");
scanf("%lf", &A_t);
printf("\n Define the atomic number of the projectile : ");
scanf("%lf", &Z_p);
printf("\n Define the mass number of the projectile : ");
scanf("%lf", &A_p);
printf("\n Define the total charge of the projectile : ");
scanf("%lf", &charge);
printf("\n Define the density of the target (in g/cm^3) : ");
scanf("%lf", &density);
printf("\n Define the thickness of the target (in mg/cm^2) : ");
scanf("%lf", &thickness);
printf("\n Define the kinetic energy of the beam (in MeV): ");
scanf("%lf", &energy);
printf("\n Define the number of iterations : ");
scanf("%d", &loop_n);

d = (thickness * pow(10,1)) / density ; /* in μm */
m_p = Z_p * 938.272 + A_p * 939.565; /* in MeV/c^2 */

double step = d/loop_n;
printf("\n The target is : %lf μm thick. \n",d);

energy_t[0] = energy;

while(i<=d) {
    
beta_t[x] = sqrt( 1 - 1/pow((energy_t[x]/m_p) +1,2) );
printf(" The beta factor is :  %lf. \n", beta_t[x]);

result[x] = (d/loop_n) 
* ( density * Z_t * N_A * pow(charge,2) * pow(10,-18) ) 
/ ( A_t * 4 * pi * pow(beta_t[x],2) * m_e * pow(epsilon_0,2) ) 
* ( log(  (   pow(10,6) * pow(beta_t[x],2) * m_e   ) / ( 5*(1 - pow(beta_t[x],2)) * Z_t ) ) - pow(beta_t[x],2)  ); 

/* the value of result[x] is in eV/μm and the various powers of 10 are included in the term 10^(-18)  */

printf(" Result[%d] =  %lf eV \n", x , result[x]);

energy_t[x+1] = energy_t[x] - result[x] * pow(10,-6);
printf(" TKE is : %lf MeV \n", energy_t[x+1]);

fprintf(fp,"%lf   \t  %lf \n", i, energy_t[x]);

i += step;
x++;
}

fclose(fp); 
 
return 0;    
}
