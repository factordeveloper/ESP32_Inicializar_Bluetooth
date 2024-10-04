#include "BluetoothSerial.h"  // Incluir la librería BluetoothSerial

BluetoothSerial SerialBT;     // Crear un objeto BluetoothSerial

void setup() {
  Serial.begin(115200);       // Inicializar la comunicación serial
  SerialBT.begin("ESP32_BT"); // Inicializar el Bluetooth con el nombre "ESP32_BT"
  Serial.println("El dispositivo ahora es visible para emparejamiento.");
}

void loop() {
  if (Serial.available()) {          // Si hay datos en la conexión serial por USB
    SerialBT.write(Serial.read());   // Enviar datos al Bluetooth
  }

  if (SerialBT.available()) {        // Si hay datos recibidos por Bluetooth
    Serial.write(SerialBT.read());   // Mostrar los datos en el monitor serial
  }

  delay(20); // Evitar sobrecargar el procesador
}
