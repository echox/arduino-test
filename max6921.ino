//quick vfd tube driver test
// MAX6921
// datasheet: http://datasheets.maximintegrated.com/en/ds/MAX6921-MAX6931.pdf

int clk = 2;
int load = 1;
int din = 0;
int led = 13;
int blank = 7;

void setup() {                
  pinMode(din, OUTPUT);
  pinMode(load, OUTPUT);
  pinMode(clk, OUTPUT);  
  
  pinMode(blank, OUTPUT);
  digitalWrite(blank, LOW);
  
  digitalWrite(clk, LOW);
  digitalWrite(load, LOW);
  digitalWrite(din, LOW);
}

// the loop routine runs over and over again forever:
void loop() {

  // toggle LED to mark start
  digitalWrite(led, HIGH);  
  delay(500);              
  digitalWrite(led, LOW);    
  delay(500); 
  digitalWrite(led, HIGH);  
  delay(500);               
  digitalWrite(led, LOW);    
  delay(500);   
  
  // wait 3 seconds for setting up logic analyzer
  delay(3000);

 // write OUT19 with first clock signal
    digitalWrite(din, HIGH);
    delay(10);
    digitalWrite(clk, HIGH);
    delay(5);
 // turn off the other OUTs
    digitalWrite(din, LOW);
    delay(5);
    
 // clock 0 to other loads
    for(int i=0;i<19;i++) {
     digitalWrite(clk, LOW);
     delay(10);
     digitalWrite(clk, HIGH);
     delay(10);
    }
    digitalWrite(clk, LOW);
    
  // load the changes
    digitalWrite(load, HIGH);
    delay(10);
    digitalWrite(load, LOW);
    
    digitalWrite(din, LOW);

  // do nothing more
  for(;;) {};
  
}
