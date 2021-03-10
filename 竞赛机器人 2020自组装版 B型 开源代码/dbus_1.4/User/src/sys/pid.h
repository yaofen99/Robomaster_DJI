#ifndef __PID_H__
#define __PID_H__

#ifdef PID_H_GLOBAL
  #define PID_H_EXTERN
#else
  #define PID_H_EXTERN extern
#endif

#include "stdio.h"
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct pid m_pid_t;

/**
  * @brief     底盘控制模式枚举
  */
typedef enum
{
  CHASSIS_RELAX,         //底盘失能
  CHASSIS_STOP,          //底盘停止
  CHASSIS_NORMAL,        //底盘正常
  CHASSIS_AVOID,         //底盘避障
} chassis_mode_e;

typedef struct
{
  /* 底盘控制模式相关 */
  chassis_mode_e  mode;       //当前底盘控制模式
  chassis_mode_e  last_mode;  //上次底盘控制模式
  /* 底盘移动速度相关数据 */
  float           vx;         //底盘前后速度
  float           vy;         //底盘左右速度
  float           vw;         //底盘旋转速度
  int16_t speed[4];
} chassis_t;

struct pid
{
    float p;
    float i;
    float d;

    float set;
    float get;
    float err;
    float last_err;

    float pout;
    float iout;
    float dout;
    float out;

    float input_max_err;

    uint32_t max_out;
    uint32_t inte_limit;

    void (*f_param_init)(m_pid_t *pid,
                         uint32_t max_output,
                         uint32_t inte_limit,
                         float p,
                         float i,
                         float d);
    void (*f_pid_reset)(m_pid_t *pid, float p, float i, float d);

};

void pid_struct_init(
    m_pid_t *pid,
    uint32_t maxout,
    uint32_t intergral_limit,

    float kp,
    float ki,
    float kd);

float pid_calculate(m_pid_t *pid, float fdb, float ref);

#endif // __PID_H__
