Simple Arduino waveform generator for optogenetic experiments

**Materials needed:**
- Arduino Uno (or any other microcontroller with Arduino IDE compatibility and at least 4 pinouts.
- Breadboard
- 3 push buttons
- female BNC test leads (https://www.digikey.com/en/products/detail/pomona-electronics/5069/737135)
- 3 10k ohm resistors
- several wires

**Wiring**

If you plan to use the plastic shield as pictured, snap off the indented tab that allows you to press the Reset button on the Arduino to avoid accidentally resetting the Arduino when the buttons are pressed.
![photo of optoTTL device](https://github.com/christineliuart/optoTTL/blob/main/optoTTLdevice.png?raw=true)

**How to Use**
1) Set the laser to TTL and adjust the light power before connecting the optoTTL device.
2) When the optoTTL is plugged into the BNC port on the laser, the laser output should stop.
3) Press the BURST button to deliver a single burst of 25 4ms pulses at 50Hz (total duration 500ms).
4) Press the TONIC button to initate continuous delivery of 4ms pulses at 4Hz.
5) Press the STOP button to stop the tonic stimulation.

6) Edit the code and flash to the device to edit the stimulation parameters

**Troubleshooting**
Connect all wires and resistors as shown in the diagram to avoid potential problems. 

Make sure to put 10k ohm resistors between the button and ground. Setting pinMode to INPUT_PULLUP is insufficient and will cause laser power to "leak" when it should be off.
Make sure to connect the resistor/ground, power, and pin wires to the buttons as shown, otherwise the button may be LOW when pressed when the code is configured for the button to be HIGH when pressed.


