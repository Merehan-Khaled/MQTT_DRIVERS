/*
 * MQTT.h
 *
 *  Created on: Feb 19, 2023
 *      Author: ELSERAG FOR LAPTOP
 */

#ifndef INC_MQTT_H_
#define INC_MQTT_H_

#define PROTOCOL_NAME		"MQTT"

typedef enum{
	MQTT_QOS0,
	MQTT_QOS1,
	MQTT_QOS2
}Mqtt_QosType;

typedef struct{
	u8* TopicName;
	u8* Msg;
	Mqtt_QosType Qos;
	u32 MsgLen;
}Mqtt_PublishType;

void Mqtt_Connect(u8* Client_ID);

void Mqtt_Publish(Mqtt_PublishType* Pub_Packet);

void Mqtt_Subscribe(u8* TopicName);

#endif /* INC_MQTT_H_ */
