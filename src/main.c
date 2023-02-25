/*
 * main.c
 *
 *  Created on: Feb 25, 2023
 *      Author: ELSERAG FOR LAPTOP
 */

#include <Macros.h>
#include <std_types.h>
#include <Registers.h>
#include <Dio.h>
#include <Usart.h>
#include <MQTT.h>
#include <util/delay.h>

int main(void)
{
	Mqtt_PublishType Pub={"Shopping/grocery/suger","123",MQTT_QOS0,3};
	//PORT_voidInit();
	Usart_Init ();
	Mqtt_Connect("Shopping");
	_delay_ms(1000);
	Mqtt_Subscribe("Shopping/groc/tea");
	while(1)
	{
		Mqtt_Publish(&Pub);
		_delay_ms(5000);
	}
}

