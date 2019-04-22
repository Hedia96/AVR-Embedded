/***********************************************************
 * LED_interface.h                                         *
 * Created on: Jan 31, 2019                                *
 * Author: AyetAllah                                       *
 ***********************************************************/


/*INCLUDE LIBRARY */
#include"STD_TYPES.h"
#include"BIT_CALC.h"
/*INCLUDE BELOW LAYERS IN STATIC ARCHITECTURE*/
#include"DIO_interface.h"
#include"DIO_private.h"
/*INCLUDE OWNER DRIVERS*/
#include"SSD_interface.h"
#include"SSD_private.h"
#include"SSD_config.h"
static u8 Value;

/*
NAME       : u8SetOn
DESCRIPTION: THIS FUNCTION ENABLE REQUIRED SSD ACCORDING TO ITS TYPE
ARGUMENTS  : INDEX OF WHICH SSD IE ENABLED ACCORDING TO ITS TYPE.
RETURN     : ERROR STATE

*/
u8 SSD_u8SetOn(u8 Copy_u8IndexSsd)
{
  u8 Local_u8Error=ERROR_NO;
    if(Copy_u8IndexSsd <= NUM_SSD)
    {
      switch(SSD_ASNUM[Copy_u8IndexSsd].u8TypeAnodeCathode_)
      {
        case CATHODE:
             //SSD_ASNUM[Copy_u8IndexSsd].enable_ =DIO_PIN_LOW;
             DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].enable_ ,DIO_PIN_LOW);
             break;
        case ANODE :
             //SSD_ASNUM[Copy_u8IndexSsd].enable_ =DIO_PIN_HIGH;
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].enable_ ,DIO_PIN_HIGH);
             break;
        default:
        Local_u8Error=ERROR_NOK;


      }
      SSD_ASNUM[Copy_u8IndexSsd].u8StateOnOff_ =ON;
      SSD_u8SetValue(Value,Copy_u8IndexSsd);
    }
    else
      Local_u8Error=ERROR_NOK;


  return Local_u8Error;
}

/*****************************************************************/


/*
NAME       : SSD_u8SetValue
DESCRIPTION: THIS SHOW THE REQUIRED PATTERN ACCORDING TO ITE TYPE COMMON ANODE OR CATHODE
ARGUMENTS  : REQUIRED VALUE TO BE SHOWN ON SSD
RETURN     : ERROR STATE

*/



u8 SSD_u8SetValue(u8 Copy_u8ValuePattern,u8 Copy_u8IndexSsd)
{ u8 Local_u8Error=ERROR_NO;
  if(Copy_u8IndexSsd <= NUM_SSD)
  {
          DIO_u8SetPinDirection(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_OUTPUT);
          DIO_u8SetPinDirection(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_OUTPUT);
          DIO_u8SetPinDirection(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_OUTPUT);
          DIO_u8SetPinDirection(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_OUTPUT);
          DIO_u8SetPinDirection(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_OUTPUT);
          DIO_u8SetPinDirection(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_OUTPUT);
          DIO_u8SetPinDirection(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_OUTPUT);
          DIO_u8SetPinDirection(SSD_ASNUM[Copy_u8IndexSsd].enable_,DIO_PIN_OUTPUT);
          if(SSD_ASNUM[Copy_u8IndexSsd].u8StateOnOff_ == ON &&(SSD_ASNUM[Copy_u8IndexSsd].u8TypeAnodeCathode_==CATHODE))
          {
            switch(Copy_u8ValuePattern)
            {
              case 0:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
              break;
              case 1:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
              break;
              case 2:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
              break;
              case 3:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
              break;
              case 4:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
              break;
              case 5:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
              break;
              case 6:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
              break;
              case 7:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
              break;
              case 8:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
              break;
              case 9:
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
              DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
              break;
              default:
            	  Local_u8Error=ERROR_NOK;


            }
          }
          else if(SSD_ASNUM[Copy_u8IndexSsd].u8StateOnOff_ == ON &&(SSD_ASNUM[Copy_u8IndexSsd].u8TypeAnodeCathode_==ANODE))
          {
                  switch(Copy_u8ValuePattern)
                  {
                    case 0:
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
                    break;
                    case 1:
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
                    break;
                    case 2:
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
                    break;
                    case 3:
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
                    break;
                    case 4:
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
                    break;
                    case 5:
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
                    break;
                    case 6:
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
                    break;
                    case 7:
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_HIGH);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_HIGH);
                    break;
                    case 8:
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
                    DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
                    break;
                    case 9:
                   DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].a_,DIO_PIN_LOW);
                   DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].b_,DIO_PIN_LOW);
                   DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].c_,DIO_PIN_LOW);
                   DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].d_,DIO_PIN_LOW);
                   DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].e_,DIO_PIN_HIGH);
                   DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].f_,DIO_PIN_LOW);
                   DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].g_,DIO_PIN_LOW);
                  break;
                    default:
                    Local_u8Error=ERROR_NOK;

                  }

          }
          if(SSD_ASNUM[Copy_u8IndexSsd].u8StateOnOff_ ==ON)
          {
           SSD_ASNUM[Copy_u8IndexSsd].u8Value_ =Copy_u8ValuePattern;
          Value=SSD_ASNUM[Copy_u8IndexSsd].u8Value_;
          }
   }
  else
    {
       Local_u8Error=ERROR_NOK;
    }
  return Local_u8Error;
}

/********************************************************************************/


/*
NAME       : SSD_u8SetOff
DESCRIPTION: THIS FUNCTION DISABLE REQUIRED SSD ACCORDING TO ITS TYPE
ARGUMENTS  : INDEX OF WHICH SSD IE ENABLED ACCORDING TO ITS TYPE
RETURN     : ERROR STATE

*/
u8 SSD_u8SetOff(u8 Copy_u8IndexSsd)
{ u8 Local_u8Error=ERROR_NO;
if(Copy_u8IndexSsd <= NUM_SSD)
   {
	if( SSD_ASNUM[Copy_u8IndexSsd].u8StateOnOff_  == ON)
	{
		 SSD_ASNUM[Copy_u8IndexSsd].u8StateOnOff_ =OFF;

	     switch(SSD_ASNUM[Copy_u8IndexSsd].u8TypeAnodeCathode_)
	     {
	       case CATHODE:
	            //SSD_ASNUM[Copy_u8IndexSsd].enable_ =DIO_PIN_LOW;
	            DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].enable_ ,DIO_PIN_HIGH);
	            break;
	       case ANODE :
	            //SSD_ASNUM[Copy_u8IndexSsd].enable_ =DIO_PIN_HIGH;
	             DIO_u8SetPinValue(SSD_ASNUM[Copy_u8IndexSsd].enable_ ,DIO_PIN_LOW);
	            break;
	       default:
	       Local_u8Error=ERROR_NOK;
	     }
	}


   }
   else
     Local_u8Error=ERROR_NOK;



 return Local_u8Error;
}
