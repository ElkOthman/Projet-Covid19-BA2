#include <math.h>


//Program starts here

const int zout = 27; // z-axis of the accelerometer
const int yout = 26; // y-axis
const int xout = 25; // x-axis

#define x 2*(3.3/4095)*analogRead(xout)-3.3
#define y 2*(3.3/4095)*analogRead(yout)-3.3
#define z 2*(3.3/4095)*analogRead(zout)-3.3

void setup() {
// put your setup code here, to run once:
//initialize serial communication at 9600 bps
  Serial.begin(115200);


}

void loop() {
  // put your main code here, to run repeatedly:
  // print the sensor values:

  #define norm  sqrt(pow(x,2) + pow(y,2) + pow(z,2)) //faire une fonction norme
  Serial.print(2*(3.3/4095)*analogRead(xout)-3.3);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(2*(3.3/4095)*analogRead(yout)-3.3);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(2*(3.3/4095)*analogRead(zout)-3.3);
  Serial.print("\t");
  Serial.print(norm);


  Serial.println();
  // 3 sec delay before next reading:
  delay(1000);

}

// Program ends here
