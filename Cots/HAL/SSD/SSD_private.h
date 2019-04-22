/***********************************************************
 * LED_interface.h                                         *
 * Created on: Jan 31, 2019                                *
 * Author    : AyetAllah                                       *
 ***********************************************************/

#ifndef SEVENSEG_PRIVATE_H_
#define SEVENSEG_PRIVATE_H_


#define CATHODE  1
#define ANODE    0

#define NAN      0

#define ON       1
#define OFF      0


//u8 u8ACathodePattern[10]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
//u8 u8AAnodePattern[10]={(u8)~0x3f,(u8)~0x06,(u8)~0x5B,(u8)~0x4F,(u8)~0x66,(u8)~0x6D,(u8)~0x7D,(u8)~0x07,(u8)~0x7F,(u8)~0x6F};
//u8 u8ANumCathodePatterns[10][7]={{},{},{},{},{},{},{},{},{},{},};
typedef struct
{//  u8 u8Apins[7];
  u8 a_;
  u8 b_;
  u8 c_;
  u8 d_;
  u8 e_;
  u8 f_;
  u8 g_;
  u8 enable_;
  u8 u8TypeAnodeCathode_;
  u8 u8StateOnOff_      ;
  u8  u8Value_;
  //u8 Dot_=MIN_U8;

}ssdunit;





#endif /* SEVENSEG_PRIVATE_H_ */
