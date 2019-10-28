/* FILE:    HCAM2315_Library_Example
   DATE:    24/01/18
   VERSION: 0.1
   AUTHOR:  Andrew Davies
   
24/01/18 version 0.1: Original version

This example sketch uses the HCAM2315 library to read the current temperature and humidity
from a AM2315 device. The sketch repeatedly reads the sensor once a second and outputs the 
result to the serial UART. 

Hobby Components (HobbyComponents.com) products currently supported by this library:

Aosong AM2315 I2C Digital Temperature & Humidity Sensor (HCSENS0043)

More information about the library can be found in the software section of our support 
forum here:

http://forum.hobbycomponents.com/software


You may copy, alter and reuse this code in any way you like, but please leave
reference to HobbyComponents.com in your comments if you redistribute this code.
This software may not be used directly for the purpose of selling products that
directly compete with Hobby Components Ltd's own range of products.
THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS MAKES NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR LACK OF NEGLIGENCE.
HOBBY COMPONENTS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR ANY DAMAGES,
INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
REASON WHATSOEVER.
*/


#include <HCAM2315.h>       //Include the HCAM2315 library.

#define I2CADD 0x5C         //I2C address of the AM2315.

HCAM2315 HCAM2315(I2CADD);  //Create an instance of the library.

void setup() 
{
  Serial.begin(9600);       //Initiliase the Arduino serial library.
  
  HCAM2315.init();          //Initiliase the library.

}

void loop() 
{
  //Trigger a temperature & humidity measurement and read back the results.
  HCAM2315.Read();  

  //If there are no errors output the results to the serial UART.
  if(HCAM2315.CheckCRC())
  {
    Serial.print("Temp (oC): ");
    Serial.print(HCAM2315.Temp());
    Serial.print("\tHumidity (%RH): ");
    Serial.println(HCAM2315.Hum());
  }else
  {
    Serial.println("CRC ERROR!");
  }

  //Wait a second before taking another measurement.
  delay(1000);
}
