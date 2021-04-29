#include <SparkFun_RV8803.h>


 // GPIO 22 => (SCL) 
 // GPIO 21 => (SDA)
 
RV8803 rtc;

void setup() {

  Wire.begin();

  Serial.begin(115200);
  Serial.println("Read Time from RTC Example");

  if (rtc.begin() == false) {
    Serial.println("Something went wrong, check wiring");
  }
  else
  {
    Serial.println("RTC online!");
  }
}

void loop() {

  if (rtc.updateTime() == false) //Updates the time variables from RTC
  {
    Serial.print("RTC failed to update");
  }

  String currentDate = rtc.stringDateUSA(); //Get the current date in mm/dd/yyyy format (we're weird)
  //String currentDate = rtc.stringDate(); //Get the current date in dd/mm/yyyy format
  String currentTime = rtc.stringTime(); //Get the time
  Serial.print(currentDate);
  Serial.print(" ");
  Serial.println(currentTime);

  delay(1000);
}
