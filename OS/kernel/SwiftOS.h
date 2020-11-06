/*******************************************************************************
**                                          Swift_OS 
**                                    The Real-Time Kernel
**
**
**
**  Copyright(c) :  2020 Swift. All right reserved.
**  Filename     :  SwiftOS.h
**  Author       :  zhengqili        
**  Version      :  V0.01   
**          
**  LICENSING TERMS:   
**          
**    Swift_OS is provided in source form for FREE evaluation, for educational use or for peaceful research.
**  If you plan on using  Swift_OS  in a commercial product you need to contact SWIFT to properly license
**  its use in your product.       
**              
**          
**     
*******************************************************************************/

#ifndef __SWIFTOS_H__
#define __SWIFTOS_H__


/*
*********************************************************************************************************
*                                       Swift OS version
*********************************************************************************************************
*/

#define  SOS_VERSION                 001u              

/*
*********************************************************************************************************
*                                        Include head files
*********************************************************************************************************
*/
#include <os_cfg.h>
#include <os_cpu.h>

/*
*********************************************************************************************************
*                                        global variable    
*********************************************************************************************************
*/

#ifndef  SOS_TRUE
#define  SOS_TRUE         1u
#endif

#ifndef  SOS_FALSE
#define  SOS_FALSE        0u
#endif

#define  OS_EVENT_EN           (((OS_Q_EN > 0u) && (OS_MAX_QS > 0u)) || (OS_MBOX_EN > 0u) || (OS_SEM_EN > 0u) || (OS_MUTEX_EN > 0u))

/*
*********************************************************************************************************
*                                        SOS task staus  
*********************************************************************************************************
*/
#define  SOS_TASK_STAT_READY            0x00u;    //task is ready to run
#define  SOS_TASK_STAT_SUSPEND          0x01u;    //task is suspended
#define  SOS_TASK_STAT_EVENT            0x01u;    //task is waitting for event flag


/*
*********************************************************************************************************
*                                        SOS event types   
*********************************************************************************************************
*/
typedef enum
{
	SOS_EVENT_TYPE_UNUSED    = 0,
	SOS_EVENT_TYPE_MBOX,            
    SOS_EVENT_TYPE_Q,           
    SOS_EVENT_TYPE_SEM,              
    SOS_EVENT_TYPE_MUTEX,            
    SOS_EVENT_TYPE_FLAG,           
}SOS_EVENT_TYPE;

/*
*********************************************************************************************************
*                                          SOS TASK CONTROL STRUCT
*********************************************************************************************************
*/
typedef	struct sos_tcs {

    SOS_STK        *SOSTCSStkPtr;        //Pointer to current top of stack


    struct sos_tcs *SOSTCSNext;          //Pointer to the next task control struct
	struct sos_tcs *SOSTCSPrev;          //Pointer to the previous task control struct

#if (OS_EVENT_EN)
    OS_EVENT		*OSTCSEventPtr; 	 //Pointer to		   event control block
#endif



	INT8U           SOSTASKPrio;         //task priority
	INT8U           SOSTASkStat;         //task state
	INT8U           SOSTCSStatPend; 		 //Task PEND status   
    INT32U          SOSTASKDly;		     //ticks used for delay task 

    INT8U           OSTCBX;             /* Bit position in group  corresponding to task priority   */
    INT8U           OSTCBY;             /* Index into ready table corresponding to task priority   */
    OS_PRIO         OSTCBBitX;          /* Bit mask to access bit position in ready table          */
    OS_PRIO         OSTCBBitY;          /* Bit mask to access bit position in ready group          */	

} SOS_TASK_STRUCT;















#endif






















































