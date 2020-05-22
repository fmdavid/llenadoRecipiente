const int ledNivel = 10 ;
const int ledAuto = 11 ;
const int botonLlenadoManual = 6;
const int botonLlenadoAutomatico = 5;
const int bomba = 7;
const int sensor = 0;
const int limite = 380; // ajustar según convenga al caso

int encendido = 0;

void setup()
{   
	// iniciamos la comunicación serie con la placa
	Serial.begin(9600);
	// se inicializan los diferentes pines que utilizamos
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
	// verificamos la lectura con respecto a límite y manejamos el led en función de eso
	if(valorSensor < limite){
		digitalWrite( ledNivel, HIGH);
	}else{
		digitalWrite( ledNivel, LOW) ;  
	}
	
	// si estamos pulsando el botón de llenado manual, activamos la bomba
	if(digitalRead(botonLlenadoManual) == HIGH){ 
		digitalWrite( bomba, HIGH) ;  
    	}else{
		digitalWrite( bomba, LOW) ;
		
	// conmutamos el modo automático si el botón está pulsado
	if(digitalRead(botonLlenadoAutomatico) == HIGH){
		encendido = !encendido;
	}
	
	// en función de si está o no activado el modo automático, encendemos el led indicador de dicho modo
	digitalWrite( ledAuto, encendido) ;
	
	// si estamos en el modo automático y no superamos el límite, seguimos activando la bomba
	// si no está en modo automático, apagamos la bomba
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
	
    delay(500); // hacemos una espera hasta el siguiente ciclo
}
