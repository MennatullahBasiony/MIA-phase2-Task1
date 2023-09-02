//Initializing needed variables
int trigRight = 2, echoRight = 3, trigFront = 4, echoFront = 5, trigLeft = 6, echoLeft = 7, trigBack = 8, echoBack = 9;
float dx, dy, distanceRight = 0, distanceFront = 0, distanceLeft = 0, distanceBack = 0, time, kgVertical, kgHorizontal;

//Estimated variance for the four sensors to use latter in sensors fusion
float varLeft = 0.1, varRight = 0.14, varFront = 0.28, varBack = 0.08;

void setup()
{
  Serial.begin(9600);
  
  //Calculating kg value of each for each axis
  kgVertical = varFront /(varFront + varBack);
  kgHorizontal = varLeft / (varLeft + varRight);
}

void loop()
{
  //Getting right sensor reading
  distanceRight = calculateDistance(trigRight, echoRight);
  //constraining distance to given dimensions
  distanceRight = constrain(distanceRight, 0, 500);
  Serial.print("Distance from right wall (in cm): ");
  Serial.println(distanceRight);
  
  //Getting front sensor reading
  distanceFront = calculateDistance(trigFront, echoFront);
  //constraining distance to given dimensions
  distanceFront = constrain(distanceFront, 0, 600);
  Serial.print("Distance infront of the Robot (in cm): ");
  Serial.println(distanceFront);
  
  //Getting left sensor reading
  distanceLeft = calculateDistance(trigLeft, echoLeft);
  //constraining distance to given dimensions
  distanceLeft = constrain(distanceLeft, 0, 500);
  Serial.print("Distance from left wall (in cm): ");
  Serial.println(distanceLeft);
  
  //Getting back sensor reading
  distanceBack = calculateDistance(trigBack, echoBack);
  //constraining distance to given dimensions
  distanceBack = constrain(distanceBack, 0, 600);
  Serial.print("Distance from behind (in cm): ");
  Serial.println(distanceBack);
  
  //Using Kalman filter to fuse Horizontal sensors
  dx = distanceLeft + kgHorizontal * (distanceLeft - distanceRight);

  //Using Kalman filter to fuse Vertical sensors
  dy = distanceFront + kgVertical * (distanceFront - distanceBack);
  
  //printing position from x-axis and y-axis
  Serial.print("Location(x, y): (");
  Serial.print(dx);
  Serial.print(", ");
  Serial.print(dy);
  Serial.println(")");
  
  //seperate readings with delay and empty line
  delay(3000);
  Serial.println();
  
}

float calculateDistance(int trigPin, int echoPin)
{
  //initialize tringger pin as output
  pinMode(trigPin, OUTPUT);  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  //Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //initialize echo pin as input
  pinMode(echoPin, INPUT);
  //Reads the echo pin, and returns the sound wave travel time in microseconds
  time = pulseIn(echoPin, HIGH);
  
  //equation to return distance in cm/sec
  return ((time * 0.0343)/2);
}

  
