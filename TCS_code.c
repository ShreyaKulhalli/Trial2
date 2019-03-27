#define DRY_COBBLESTONE 6.2497
#define WET_COBBLESTONE 51.0124
#define WHEEL_RADIUSm 0.5588

float Terrain_selection(int );
float Ideal_slip_calc(float );
float Current_slip_calc(int ,int );
float Error_calc_range_signal(float , float ,int );

void setup()
{
  //Sensor inputs are all analog, thus need not be declared
  //Control signal outputs
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);//Electrohydraulic brake control for FL Wheel
  pinMode(10,OUTPUT);//Electrohydraulic brake control for FR Wheel
  pinMode(9,OUTPUT);//Electrohydraulic brake control for RL Wheel
  pinMode(6,OUTPUT);//Electrohydraulic brake control for RR Wheel
}

void loop()
{
  int Vx = analogRead(A0);//Vehicle speed
  int Vw_FL = analogRead(A1);//FL wheel speed
  int Vw_FR = analogRead(A2);//FR wheel speed
  int Vw_RL = analogRead(A3);//RL wheel speed
  int Vw_RR = analogRead(A4);//RR wheel speed
  int Terrain_input = analogRead(A5);//Terrain type
  
  String str="**";
  Serial.print(str);
  
  float p2 = Terrain_selection(Terrain_input);//Kiencke's constant for Terrain
  
  float slip_i = Ideal_slip_calc(p2);//Ideal slip for Terrain 
  
  float slip_c_FL = Current_slip_calc(Vx,Vw_FL);//Current slip for FL Wheel
  delay(100);
  float slip_c_FR = Current_slip_calc(Vx,Vw_FR);//Current slip for FR Wheel
  delay(100);
  float slip_c_RL = Current_slip_calc(Vx,Vw_RL);//Current slip for RL Wheel
  delay(100);
  float slip_c_RR = Current_slip_calc(Vx,Vw_RR);//Current slip for RR Wheel
  delay(100);
  
  // Calculation of error, checking if range of error is permissible and generating the corresponding
  Error_calc_range_signal(slip_i,slip_c_FL,11);
  Error_calc_range_signal(slip_i,slip_c_FR,10);
  Error_calc_range_signal(slip_i,slip_c_RL,9);
  Error_calc_range_signal(slip_i,slip_c_RR,6);
  
}

float Terrain_selection(int Terrain_input)
{
  float p2;
  if(Terrain_input<=511)
     p2 = DRY_COBBLESTONE;
  else 
     p2 = WET_COBBLESTONE;// print
  Serial.println("\np2");
  Serial.println(p2);
  return p2;
}
  

float Ideal_slip_calc(float p2)
{
  float slip_i = pow(p2,(-0.5));
  Serial.println("\nIdeal slip");
  Serial.println(slip_i);
  return slip_i; // print
}
  

float Current_slip_calc(int Vx,int Vw)
{
  float Vx_ms = float(Vx)/11.38; // Scaling sensor reading to actual value
  float Vw_rs = float(Vw)/6.36; // Scaling sensor reading to actual value
  
  float Slip = Vw_rs*WHEEL_RADIUSm;
  Slip = abs((Vx_ms - Slip)/Vx_ms);// Slip formula
  
  Serial.println("\nCurrent slip");
  Serial.println(Slip);
  return Slip;
  
}

float Error_calc_range_signal(float Slip_i, float Slip_c,int port)
{
  float e = abs(Slip_c-Slip_i);// Error signal
  
  //Serial.println(e);
  
  if(e>=0 && e<=0.1)// Error signal in permissible range
  {
    // No actuation necessary
    Serial.println("Error in permissible range\n");
    analogWrite(port,0);
  }
  else
  {
    
	if(Slip_c<Slip_i)
    {
     digitalWrite(13,HIGH);
    }
    else
    { // Send Pulse signal for Electrohydraulic brake control
     Serial.println("Error not in permissible range\n");
     analogWrite(port,128);
    }
    
  }
  
}
