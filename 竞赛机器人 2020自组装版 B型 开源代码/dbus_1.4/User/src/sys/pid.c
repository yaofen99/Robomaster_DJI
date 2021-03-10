#include "pid.h"

void abs_limit(float *a, float ABS_MAX)
{
  if (*a > ABS_MAX)
    *a = ABS_MAX;
  if (*a < -ABS_MAX)
    *a = -ABS_MAX;
}

static void pid_param_init(
    m_pid_t *pid,
    uint32_t maxout,
    uint32_t inte_limit,
    float kp,
    float ki,
    float kd)
{

  pid->inte_limit = inte_limit;
  pid->max_out = maxout;

  pid->p = kp;
  pid->i = ki;
  pid->d = kd;
}
/**
  * @brief     modify pid parameter when code running
  * @param[in] pid: control pid struct
  * @param[in] p/i/d: pid parameter
  * @retval    none
  */
static void pid_reset(m_pid_t *pid, float kp, float ki, float kd)
{
  pid->p = kp;
  pid->i = ki;
  pid->d = kd;

  pid->pout = 0;
  pid->iout = 0;
  pid->dout = 0;
  pid->out = 0;
}

/**
  * @brief     calculate delta PID and position PID
  * @param[in] pid: control pid struct
  * @param[in] get: measure feedback value
  * @param[in] set: target value
  * @retval    pid calculate output
  */
float pid_calculate(m_pid_t *pid, float get, float set)
{
  pid->get = get;
  pid->set = set;
  pid->err = set - get;
  if ((pid->input_max_err != 0) && (fabs(pid->err) > pid->input_max_err))
    return 0;

  pid->pout = pid->p * pid->err;
  pid->iout += pid->i * pid->err;
  pid->dout = pid->d * (pid->err - pid->last_err);

  abs_limit(&(pid->iout), pid->inte_limit);
  pid->out = pid->pout + pid->iout + pid->dout;
  abs_limit(&(pid->out), pid->max_out);

  return pid->out;
}
/**
  * @brief     initialize pid parameter
  * @retval    none
  */
void pid_struct_init(
    m_pid_t *pid,
    uint32_t maxout,
    uint32_t inte_limit,

    float kp,
    float ki,
    float kd)
{
  pid->f_param_init = pid_param_init;
  pid->f_pid_reset = pid_reset;

  pid->f_param_init(pid, maxout, inte_limit, kp, ki, kd);
  pid->f_pid_reset(pid, kp, ki, kd);
}

