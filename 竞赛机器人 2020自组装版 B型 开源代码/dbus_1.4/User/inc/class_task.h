#ifndef __CLASS_TASK_H__
#define __CLASS_TASK_H__

#ifdef __cplusplus
extern "C"
{
#endif


#include "sys.h"


void communicate_task(void const *argu);

void motor_task(void const *argu);


#ifdef __cplusplus
}
#endif

#endif
