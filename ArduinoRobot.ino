#include <AFMotor.h>

AF_DCMotor MotorEsquerda(1);
AF_DCMotor MotorDireita(2);

bool ReAtiva = false;
char Command;

void setup() {
  Serial.begin(9600);  
}

void Frente(){
  VerRe();
  
  MotorEsquerda.setSpeed(255);
  MotorDireita.setSpeed(255);
  MotorEsquerda.run(FORWARD); 
  MotorDireita.run(FORWARD);  
}

void Direita(){
  VerRe();
  
  MotorEsquerda.setSpeed(255);  
  MotorEsquerda.run(FORWARD); 
  MotorDireita.run(RELEASE);   
}

void Esquerda(){
  VerRe();
    
  MotorDireita.setSpeed(255);  
  MotorDireita.run(FORWARD); 
  MotorEsquerda.run(RELEASE);   
}

void Parar(){
  VerRe();
  
  MotorEsquerda.run(RELEASE);  
  MotorDireita.run(RELEASE);  
}

void Re(){
  Parar();
  
  MotorEsquerda.setSpeed(255);
  MotorDireita.setSpeed(255);
  MotorEsquerda.run(BACKWARD); 
  MotorDireita.run(BACKWARD);   

  ReAtiva = true;
}

void VerRe(){
  if (ReAtiva) {
    Parar();
    ReAtiva = false;
  }
}

void loop() {
  while (Serial.available() > 0) {
    Command = Serial.read();

    if (Command == 'W') {
      Frente();
    }
    if (Command == 'S') {
      Re();
    }  
    if (Command == 'A') {
      Direita();
    }    
    if (Command == 'D') {
      Esquerda();
    }      
    if (Command == 'P') {
      Parar();
    }      
  } 
}
