#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define PIN_0 0
#define PIN_7 7

enum status_motor
{
	Repouso = 0,
	Horario = 1,
	AntiHorario = 2
};

void 
inicializar(void)
{
	if (wiringPiSetup() == -1)
		exit(1);

	pinMode(PIN_0, OUTPUT);	
	pinMode(PIN_7, OUTPUT);	
}

void
setar_motores(enum status_motor statusMotor, int periodo)
{
	switch (statusMotor)
	{
		case Repouso:
			digitalWrite(PIN_0, 0);
			digitalWrite(PIN_7, 0);
			break;	
		case Horario:
			digitalWrite(PIN_0, 0);
			digitalWrite(PIN_7, 1);
			break;
		case AntiHorario:
			digitalWrite(PIN_0, 1);
			digitalWrite(PIN_7, 0);
			break;
	}

	if (periodo > 0)
		delay(periodo);	
}

int 
main(void)
{	
	inicializar();
	
	while (TRUE)
	{
		printf("Polarizando os motores no sentido antihorário.\n\n\n");
		setar_motores(AntiHorario, 5000);
		printf("Polarizando os motores em sentido horário. \n\n\n");
		setar_motores(Horario, 5000);
		printf("Definindo os motores em estado de repouso. \n\n\n");
		setar_motores(Repouso, 2000);
	}

	return (0);
}
