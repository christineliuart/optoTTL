// Manual button opto pulse generator with Arduino Uno

// sends single burst when BURST button is pressed
// starts continuous tonic stim when TONIC button is pressed
// stops tonic stim when STOP button is pressed

#define PULSE_OUT 11  //BNC red lead
#define BURST 2       //button
#define TONIC 3       //button
#define STOP 4        //button
#define LED A4        // optional LED with long lead connected to resistor, connected to A4, and short lead connected to ground

// STIM PARAMETERS
int tonic_pulse_width = 4;            //ms
int tonic_frequency = 4;              //Hz

int phasic_pulse_width = 4;           //ms
int phasic_frequency = 50;            //Hz
int phasic_burst_cycles = 25;         //num of pulses in single burst

// start with stim off
bool tonic = 0;

void setup() {
  pinMode(BURST, INPUT);
  pinMode(TONIC, INPUT);
  pinMode(STOP, INPUT);
  pinMode(PULSE_OUT,OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(PULSE_OUT,LOW); //ensures TTL pulse is set to LOW so laser is off before pulses are sent
  digitalWrite(LED_BUILTIN,LOW);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(BURST) == HIGH) {
    for (int cycles = 0; cycles < phasic_burst_cycles; cycles++) {
      digitalWrite(LED,HIGH);
      digitalWrite(PULSE_OUT,HIGH);
      delay(phasic_pulse_width);
      digitalWrite(PULSE_OUT,LOW);
      digitalWrite(LED,LOW);
      long phasic_temp_delay = (1000 / phasic_frequency) - phasic_pulse_width;
      if (phasic_temp_delay < 0) phasic_temp_delay = 0;
      delay(phasic_temp_delay);
    }
    Serial.println("BURST");
  }

  if (digitalRead(TONIC) == HIGH) {
    tonic = 1; //turn on tonic stim
    Serial.println("TONIC");
  }

  while (tonic == 1) {
    digitalWrite(LED,HIGH);
    digitalWrite(PULSE_OUT, HIGH);
    delay(tonic_pulse_width);
    digitalWrite(PULSE_OUT,LOW);
    digitalWrite(LED,LOW);
    long tonic_temp_delay = (1000 / tonic_frequency) - tonic_pulse_width;
    if (tonic_temp_delay < 0) tonic_temp_delay = 0;  //avoid crashing
    delay(tonic_temp_delay);    

    if (digitalRead(STOP) == HIGH) break; 
  }

  if (digitalRead(STOP) == HIGH) {
    tonic = 0; //turn off tonic stim
    Serial.println("STOP");
  }

}
