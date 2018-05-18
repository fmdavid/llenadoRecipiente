const int ledNivel = 10 ;
const int ledAuto = 11 ;
const int botonLlenadoManual = 6;
const int botonLlenadoAutomatico = 5;
const int bomba = 7;
const int sensor = 0;
const int limite = 380;

int encendido = 0;

void setup()
{   
	Serial.begin(9600);  
	pinMode( ledNivel, OUTPUT) ;
	pinMode( ledAuto, OUTPUT) ;
	pinMode( botonLlenadoManual  , INPUT) ;
	pinMode( botonLlenadoAutomatico  , INPUT) ;
	pinMode(bomba, OUTPUT);  
}

void loop()
{
	int valorSensor = analogRead(sensor); // obtenemos la medida del sensor
	Serial.println(valorSensor);
	if(valorSensor < limite){
		digitalWrite( ledNivel, HIGH);
	}else{
		digitalWrite( ledNivel, LOW) ;  
	}
	
	if(digitalRead(botonLlenadoManual) == HIGH){ // modo manual
		digitalWrite( bomba, HIGH) ;  
    }else{
		digitalWrite( bomba, LOW) ;  
		if(digitalRead(botonLlenadoAutomatico) == HIGH){
			encendido = !encendido;
		}
		digitalWrite( ledAuto, encendido) ;
		if(encendido == 1){
			if(valorSensor < limite){
				digitalWrite( bomba, HIGH) ;  
			}else{
				digitalWrite( bomba, LOW) ;  
			}
		}else{
			digitalWrite( bomba, LOW) ;  
		}
    }
	
    delay(500);
}
