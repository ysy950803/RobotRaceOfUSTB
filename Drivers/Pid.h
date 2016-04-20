
#ifndef __PID_H__
#define __PID_H__

#include "Global.h"

typedef struct PID			//����������������
{
    s32 vi_Ref;		//�ٶ�PID���ٶ��趨ֵ
    s32 vi_FeedBack;		//�ٶ�PID���ٶȷ���ֵ


    s32 vi_PreError;	  	//�ٶ�PID��ǰһ�Σ��ٶ����,,vi_Ref - vi_FeedBack
    s32 vi_PreDerror;	//�ٶ�PID��ǰһ�Σ��ٶ����֮�d_error-PreDerror;

    u32 v_Kp;		//�ٶ�PID��Ka = Kp
    u32 v_Ki;		//�ٶ�PID��Kb = Kp * ( T / Ti )
    u32 v_Kd;		//�ٶ�PID��

    s32 vl_PreU;  //�������
    s32 motor_PreU;

} PID;

extern PID   L_PID;
extern PID   R_PID;
extern PID 	 POSE_PID;
extern PID 	 TURN_PID;
extern s32 V_PIDCalc(PID *pp);
extern s32 TURN_PIDCalc( PID *pp);
extern s32 POSE_PIDCalc( PID *pp);
extern void V_PIDInit(void);

#endif