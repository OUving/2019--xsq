#include "RS485_de.h"
#include<stdio.h>      /*标准输入输出定义*/
#include<stdlib.h>     /*标准函数库定义*/
#include<unistd.h>     /*Unix 标准函数定义*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>      /*文件控制定义*/
#include<termios.h>    /*PPSIX 终端控制定义*/
#include<errno.h>      /*错误号定义*/
#include<string.h>






#define SYSFS_GPIO_RST_VAL "/sys/class/gpio/gpio960/value"
#define SYSFS_GPIO_RST_VAL_H "1"
#define SYSFS_GPIO_RST_VAL_L "0"



int gpio960_high()
{
    int fd;


    //输出复位信号: 拉高>100ns
    fd = open(SYSFS_GPIO_RST_VAL, O_RDWR);
    if(fd == -1)
    {
    printf("ERR: Radio hard reset pin value open error.\n");
    return EXIT_FAILURE;
    }

    write(fd, SYSFS_GPIO_RST_VAL_H, sizeof(SYSFS_GPIO_RST_VAL_H));

    close(fd);
    return 0;
}

int gpio960_low()
{
    int fd;


    //输出复位信号: 拉高>100ns
    fd = open(SYSFS_GPIO_RST_VAL, O_RDWR);
    if(fd == -1)
    {
    printf("ERR: Radio hard reset pin value open error.\n");
    return EXIT_FAILURE;
    }

    write(fd, SYSFS_GPIO_RST_VAL_L, sizeof(SYSFS_GPIO_RST_VAL_L));

    close(fd);
    return 0;
}
