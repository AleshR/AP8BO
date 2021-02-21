#include <string.h>

#define BUFFER_LENGTH         16

void process_secret_data(void)
{
  char buffer[64];
  int ssn = 555555555; // Should NOT be leaked
  snprintf(buffer, 64, "SSN: %i", ssn);

  // Do something with SSN...
}

void do_something_else(void)
{
  char buffer[64];

  Serial.println("Enter your Name");

  int start = millis();
  int index = 0;
  while((millis() - start) < 5000)
  {
    if(Serial.available())
    {
      buffer[index++] = Serial.read();
    }
  }
  
  Serial.print("Your name: ");
  Serial.println(buffer);
}


void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Booting...");
  delay(100);
}

void loop() {
  delay(5000);
  Serial.println("Loop still running");

  process_secret_data();
  do_something_else();

}
