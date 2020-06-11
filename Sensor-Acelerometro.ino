#include <Arduino_LSM9DS1.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Iniciando!");

  if (!IMU.begin()) {
    Serial.println("Iniciação do IMU falhou!");
    while (1);
  }
  Serial.print("Taxa de amostragem do acelerômetro =");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Giroscópio em g's: ");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    if ( (x<(-1.0))||(y<(-1.0))||(z<(-1.0)) ){
      Serial.println("Atenção o idoso caiu!");
    }
    /*
    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);*/
  }
  
}
