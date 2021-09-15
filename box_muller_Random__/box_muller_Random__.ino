
void box_muller(double sigma, double *r1, double *r2);

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop(){
  double r1, r2;
  box_muller(2, &r1, &r2);
  Serial.print(r1);
  Serial.print("; "); 
  Serial.println(r2); 
  delay(1000);
}


/* generate a pair of normally distributed random numbers
* using a Box-Muller transformation. The mean is 0 -- numbers
* are equally likely to be + or -.  The required stdev is
* given in 'sigma'.  Either result pointers can be NULL, if
* you want just one number.
*/
void box_muller(double sigma, double *r1, double *r2)
{
  double
     u1, u2,
     v1, v2, s,
     z1, z2;

  for (;;) {

     /* get two uniform random numbers from 0 to .999...
      */
     u1 = (float) random(RAND_MAX) / ((float) RAND_MAX + 1);
     u2 = (float) random(RAND_MAX) / ((float) RAND_MAX + 1);


     v1 = 2.0L*u1 - 1.0L;
     v2 = 2.0L*u2 - 1.0L;
     s = v1 * v1 + v2 * v2;

     if (s <= 1.0L && s != 0.0L)
        break;

  }

  z1 = sqrt (-2.0L * log(s) /  s) * v1;
  z2 = sqrt (-2.0L * log(s) / s) * v2;

  if (r1 != NULL) *r1 = (z1*sigma);
  if (r2 != NULL) *r2 = (z2*sigma);

  return;
}
