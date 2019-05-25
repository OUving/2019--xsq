#ifndef LINUX_UART_C_H
#define LINUX_UART_C_H


#ifdef __cplusplus
extern "C"{
#endif

    int UART0_Open(int fd,char* port);   //打开串口并返回串口文件描述符
    void UART0_Close(int fd);           //关闭串口
    int UART0_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity); //设置波特率、数据流控制、数据位、停止位、校验类型
    int UART0_Init(int fd, int speed,int flow_ctrl,int databits,int stopbits,int parity); //初始化串口
    int UART0_Recv(int fd, char *rcv_buf,int data_len);     //串口接收
    int UART0_Send(int fd, char *send_buf,int data_len);    //串口发送

#ifdef __cplusplus
}
#endif

#endif // LINUX_UART_C_H
