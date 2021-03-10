/*
 * uart.c
 *
 *  Created on: 2018年10月21日
 *      Author: brody.zhang
 */

#include "dev.h"
#include "tutorial_lib.h"

rc_info_t my_rc;

void uart4_mesg_handler(uint8_t data)
{
	static uint8_t buff_data[20];
	static int index = 0;

	if(index != 0)
	{
		buff_data[index] = data;
	}
	if(data == 0xA6)
	{
		buff_data[0] = 0xA6;
		index = 1;
		return;
	}
	if(index == 19)
	{
		uint8_t sum = 0;
		for(int i=0; i<19;i++)
		{
			sum += buff_data[i];
		}
		if(sum == buff_data[19])
		{
			rc_info_t *rc = &my_rc;
			uint8_t *buff = buff_data + 1;

			rc->ch1 = (buff[0] | buff[1] << 8) & 0x07FF;
			rc->ch1 -= 1024;
			rc->ch2 = (buff[1] >> 3 | buff[2] << 5) & 0x07FF;
			rc->ch2 -= 1024;
			rc->ch3 = (buff[2] >> 6 | buff[3] << 2 | buff[4] << 10) & 0x07FF;
			rc->ch3 -= 1024;
			rc->ch4 = (buff[4] >> 1 | buff[5] << 7) & 0x07FF;
			rc->ch4 -= 1024;

			/* prevent remote control zero deviation */
			if(rc->ch1 <= 5 && rc->ch1 >= -5)
			rc->ch1 = 0;
			if(rc->ch2 <= 5 && rc->ch2 >= -5)
			rc->ch2 = 0;
			if(rc->ch3 <= 5 && rc->ch3 >= -5)
			rc->ch3 = 0;
			if(rc->ch4 <= 5 && rc->ch4 >= -5)
			rc->ch4 = 0;

			rc->sw1 = ((buff[5] >> 4) & 0x000C) >> 2;
			rc->sw2 = (buff[5] >> 4) & 0x0003;

			if ((abs(rc->ch1) > 660) || \
			  (abs(rc->ch2) > 660) || \
			  (abs(rc->ch3) > 660) || \
			  (abs(rc->ch4) > 660))
			{
			memset(rc, 0, sizeof(rc_info_t));
			return ;
			}

			rc->mouse.x = buff[6] | (buff[7] << 8); // x axis
			rc->mouse.y = buff[8] | (buff[9] << 8);
			rc->mouse.z = buff[10] | (buff[11] << 8);

			rc->mouse.l = buff[12];
			rc->mouse.r = buff[13];

			rc->kb.key_code = buff[14] | buff[15] << 8; // key borad code
		}
		index = 0;
	}
	index++;
}

void uart5_mesg_handler(uint8_t data)
{

}

void uart6_mesg_handler(uint8_t data)
{

}

void uart7_mesg_handler(uint8_t data)
{

}




