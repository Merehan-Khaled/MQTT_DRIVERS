/*
 * MQTT.c
 *
 *  Created on: Feb 19, 2023
 *      Author: ELSERAG FOR LAPTOP
 */

#include <std_types.h>
#include <Usart.h>
#include "MQTT.h"
#include <string.h>

u8 Packet[127]={0};
u8 Index=0;
u8 RemLen=0;
u8 ID=0;

void Mqtt_Connect(u8* Client_ID)
{
	/*****Fixed header*****/

	//FIRST_BYTE--> The type is 1 and the flags are reserved
	Packet[Index++]=0x10;

	//BYTE (2 TO 5) --> REMANING LENTH
	RemLen= 2 + 10 + strlen(Client_ID);
	Packet[Index++]=RemLen;

	/*****Variable Header*****/

	//BYTES[1:2] --> The protocol name size
	Packet[Index++]=0x00;
	Packet[Index++]=0x04;

	//BYTES[3:6] --> The protocol name
	strcpy((Packet+Index),PROTOCOL_NAME);
	/*for(u8 i=0; i<strlen(PROTOCOL_NAME); i++){
		Packet[Index++]=PROTOCOL_NAME[i];
	}*/

	//TO POINT TO THE NEXT PLACE AFTER ADDING THE PROTOCOL NAME
	Index+=strlen(PROTOCOL_NAME);

	//BYTE 7 --> THE PROTOCOL VERSION
	Packet[Index++]=0x04;

	//BYTE 8 --> THE CONNECT FLAGS
	Packet[Index++]=0x02;

	//BYTES[9:10] --> KEEP ALIVE
	Packet[Index++]=0xff;
	Packet[Index++]=0xff;

	/*****Payload UTF-8 encoded the client id*****/

	//BYTES[1:2] --> the length of the client id
	Packet[Index++]=0x00;					//MSB OFTEN 00
	Packet[Index++]=strlen(Client_ID);		//LSB strlen(ID)

	//BYTES[3:n] --> the client id string
	strcpy((Packet+Index),Client_ID);
	Index+=strlen(Client_ID);

	USART_u8SendBytesSynch(Packet,Index);
}

void Mqtt_Publish(Mqtt_PublishType* Pub_Packet)
{
	RemLen=2+strlen(Pub_Packet->TopicName)+Pub_Packet->MsgLen;

	/*****Fixed header*****/

	//FIRST BYTE --> The frame type and use the QoS as 0 - 1
	if(Pub_Packet->Qos==0)
	{
		Packet[Index++]=0x30;
	}
	else
	{
		Packet[Index++]=0x32;
		RemLen+=2;
	}

	//BYTE 2 --> THE REMAINING LENGTH
	Packet[Index++]=RemLen;

	/*****Variable header*****/
	/*UTF-8 encoded the topic name*/

	//BYTE[[1:2] --> The topic name length
	Packet[Index++]=0x00;								//MSB OFTEN 00
	Packet[Index++]=strlen(Pub_Packet->TopicName);		//LSB strlen(Topic Name)

	//BYTE[3:n] --> The topic name
	strcpy((Packet+Index),Pub_Packet->TopicName);

	//TO POINT TO THE NEXT PLACE AFTER ADDING THE TOPIC NAME
	Index+=strlen(Pub_Packet->TopicName);

	/*Send Packet id if QoS>0*/
	if(Pub_Packet->Qos>0)
	{
		ID++;
		Packet[Index++]=0x00;
		Packet[Index++]=ID;
	}
	/*Payload --> the message to be published*/
	for(u8 i=0; i<Pub_Packet->MsgLen ;i++)
	{
		Packet[Index++]= Pub_Packet->Msg[i];
	}
	USART_u8SendBytesSynch(Packet,Index);
}

void Mqtt_Subscribe(u8* TopicName)
{
	RemLen= 2+2+strlen(TopicName)+1;

	/*****Fixed Header*****/

	//FIRST_BYTE--> The frame type and the flags are reserved
	Packet[Index++]=0x82;

	//byte 2 --> THE REMAINING LENGTH
	Packet[Index++]=RemLen;

	/*****Variable Header*****/
	ID++;
	Packet[Index++]=0x00;
	Packet[Index++]=ID;

	/*****Payload*****/
	/*UTF-8 encoded the topic name*/

	//BYTE[1:2] --> THE LENGTH OF THE TOPIC NAME
	Packet[Index++]=0x00;					//MSB OFTEN 0
	Packet[Index++]=strlen(TopicName);		//LSB strlen(Topic Name)

	////BYTE[3:n] --> The topic name
	strcpy((Packet+Index),TopicName);

	//TO POINT TO THE NEXT PLACE AFTER ADDING THE TOPIC NAME
	Index+=strlen(TopicName);

	//BYTE n+1
	Packet[Index++]=0x01;

	USART_u8SendBytesSynch(Packet,Index);
}

