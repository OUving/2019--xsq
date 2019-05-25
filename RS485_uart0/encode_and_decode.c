#include"encode_and_decode.h"
#include"crc16.h"
#include<string.h>

typedef struct
{
    uint8 id;				//id存放机器设备号
    uint8 cmd;				//cmd存放功能码：03H或06H-----功能码
    uint8 addr[2];			//addr[0]存放地址H，addr[1]存放地址L
    uint8 data[2];
    uint8 checksum[2];				//校验字节
}s_frame;			//上位机写数据的指令

/*
 *get status frame
 */
typedef struct
{
    uint8 id;
    uint8 cmd;
    uint8 data_lenth;				//数据长度
    uint8 data[2];				//数据H和数据L
    uint8 checksum[2];				//校验字节
}g_frame;			//上位机读取数据的指令


int return_read(uint8 *ptr,uint8 *data)
{
    g_frame frame;
    memset(&frame, 0, sizeof(g_frame));

    frame.id = data[0];
    frame.cmd = 0x03;
    frame.data_lenth = 0x02;
    frame.data[0] = data[4];
    frame.data[1] = data[5];

    crc16((uint8 *)&frame,sizeof(g_frame) - 2, frame.checksum);
    memcpy(ptr,(uint8 *)&frame,sizeof(g_frame));
    return DL_RET_ACT;  //0x0002
}

int return_write(uint8 *ptr, uint8 *data)
{
    s_frame frame;		//写数据的指令存放在frame中

    if (data[1] == 0x03)		//功能码是03代表从机返回读数据操作
        {
            return return_read(ptr,data);
        }

    frame.id = data[0];
    frame.cmd = 0x06;
    frame.addr[0] = data[2];
    frame.addr[1] = data[3];
    frame.data[0] = data[4];
    frame.data[1] = data[5];

    crc16((uint8 *)&frame , sizeof(s_frame) - 2 , frame.checksum);
    memcpy(ptr,(uint8 *)&frame,sizeof(s_frame));

    return DL_RET_ACT;

}

int decode(uint8 *ptr, uint8 *recv_data)
{
    if(recv_data[0] == 0x01)
    {
        return_write(ptr,recv_data);
    }

    return DL_RET_RPT;
}






