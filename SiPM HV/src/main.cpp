#include "Wire.h"
#include "MCP4725.h"

MCP4725 MCP(0x60);

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("MCP4725_VERSION: ");
  Serial.println(MCP4725_VERSION);

  Wire.begin();

  MCP.begin();
  MCP.setValue(0);
  MCP.setMaxVoltage(5);
}

void loop()
{
  // wait for number input
  if (Serial.available() > 0)
  {
    float value = Serial.parseFloat();
    float percentage = value / 5 * 100;
    Serial.println(MCP.getValue());
    MCP.setPercentage(percentage);
    Serial.print("Setting DAC to: ");
    Serial.println(value);
  }
}