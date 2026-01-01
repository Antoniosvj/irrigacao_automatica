// Definição dos pinos

// Pino analógico para o sensor
const int pinoSensorUmidade = A0; 

// Pino digital para o LED
const int led1 = 12;           
const int led2 = 10;           
const int led3 = 8;              

//leitura do limiar de úmidade do solo
const int limiteSeco = 850;       
const int limiteUmido = 550;       

// Pino digital para o Motor
const int pinoMot = 6;                 

void setup() {
  // Configura o pino do LED como Saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Configura o pino do Motor como saída
  pinMode (pinoMot, OUTPUT);
  
  // Inicia a comunicação Serial para imprimir no Monitor Serial
  Serial.begin(9600);
  Serial.println("Monitor de Umidade do Solo Iniciado!");
}

void loop() {
  // Lê o valor do sensor de umidade (0 a 1023)
  int leituraUmidade = analogRead(pinoSensorUmidade);
  
  // Imprime o valor da leitura no Monitor Serial
  Serial.print("Leitura do Sensor: ");
  Serial.println(leituraUmidade);
  
  // Verifica o nível de umidade e toma uma ação
  if (leituraUmidade > limiteSeco) {
    digitalWrite(led1, HIGH); // LED aceso
    digitalWrite(led2, LOW);  
    
    digitalWrite(led3, LOW); 

    Serial.println(">>> ALERTA: Solo Super Seco! Regue a planta. <<<");
    digitalWrite(pinoMot,LOW);
    
  } else if(leituraUmidade < limiteSeco && leituraUmidade > limiteUmido){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);  
    digitalWrite(led3, LOW);
    Serial.println("Status: Umidade ideal.");


    digitalWrite(pinoMot, HIGH); //liga o motor
    delay(10000); //aguarda 10 segundos
    digitalWrite(pinoMot, LOW); //desliga o motor


  }else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);  
    digitalWrite(led3, HIGH); 
    Serial.println("Status: Solo Encharcado.");
    digitalWrite(pinoMot, HIGH);
  }
  
  Serial.println("------------------------------------");
  
  // Pequena pausa antes da próxima leitura
  delay(600000); // Aguarda 10 min
  //delay(2000); // Aguarda 2 segundos

}