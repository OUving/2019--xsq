#ifndef CRC16_H
#define CRC16_H

#include"common.h"
#ifdef __cplusplus
extern "C"{
#endif

    int crc16(uint8 *data, int len, uint8 *crc);


#ifdef __cplusplus
}
#endif

#endif // CRC16_H
