#include <Arduino_LSM9DS1.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Iniciando!");

  if (!IMU.begin()) {
    Serial.println("Iniciação do IMU falhou!");
    while (1);
  }
  Serial.print("Taxa de amostragem do giroscópio =");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Giroscópio em graus / segundo");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);

    if(x>200){
      Serial.println("Carro capotou.");
    }
    else if(y>200){
      Serial.println("Carro empinou.");
    }
    else if(z>200){
      Serial.println("Carro fez um cavalo de pau.");
    }

    //Serial.print(x);
    //Serial.print('\t');
    //Serial.print(y);
    //Serial.print('\t');
    //Serial.println(z);
  }
  
}
