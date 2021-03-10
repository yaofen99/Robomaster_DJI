/****************************************************************************
 *  Copyright (C) 2018 RoboMaster.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of鑱�
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.鑱� See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

/**
  *********************** (C) COPYRIGHT 2018 DJI **********************
  * @update
  * @history
  * Version     Date           Author           Modification
  * V1.0.0      June-26-2018   ric.luo
  * @verbatim
  *********************** (C) COPYRIGHT 2018 DJI **********************
  */

#include "dev.h"
#include "pid.h"
#include "tutorial_lib.h"

void communicate_task(void const *argu)
{

  while(1)
  {

    task_delay(20);
  }
}

void motor_task(void const *argu)
{

  while(1)
  {

    task_delay(300);
  }
}

void u4_printf(const char * format, ...)
{
  char buffer[128];
  int output_len;

  va_list args;
  va_start (args, format);

  output_len = vsnprintf (buffer,128, format, args);

  if(output_len > 128)
  {
    output_len = 128;
  }

  uart_send_buff(4, (uint8_t *)(buffer), output_len);

  va_end (args);
}
