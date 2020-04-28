#ifndef __CONFIG_H__
#define __CONFIG_H__

// wheel pinName    pin
#define  DIR_LATCH   12
#define  PWM2A       11
#define  PWM1B       10
#define  PWM1A        9
#define  DIR_SER      8
#define  DIR_EN       7
#define  PWM0A        6
#define  PWM0B        5
#define  DIR_CLK      4
#define  PWM2B        3

//setup wheelways
#define  Forward         0b11010001
#define  Backward        0b00101110
#define  Right           0b00011011
#define  Left            0b11100100
#define  LeftForward     0b11000000
#define  RightForward    0b00010001
#define  LeftBackward    0b00100100
#define  RightBackward   0b00001010
#define  Clockwisespin               0b01010110
#define  Counterclockwisespin        0b10101001


#endif
