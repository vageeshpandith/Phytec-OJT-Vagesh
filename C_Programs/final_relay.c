#include<errno.h>                                                              
#include<fcntl.h>                                                              
#include<stdio.h>                                                              
#include<stdlib.h>                                                    
#include<string.h>                                                             
#include<termios.h>                                                            
#include<unistd.h>                                                             
int set_interface_attribs(int fd, int speed)                                    
{                                                                               
        struct termios tty;                                                     
                                                                                
        if (tcgetattr(fd, &tty) < 0)                                            
        {                                                                       
                printf("Error from tcgetattr: %s\n", strerror(errno));          
                return -1;                                                      
        }                                                                       
                                                                                
        cfsetispeed(&tty, (speed_t)speed);                             
        tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
        tty.c_cflag &= ~CSIZE;                                        
        tty.c_cflag |= CS8;         /* 8-bit characters */            
        tty.c_cflag &= ~PARENB;     /* no parity bit */          
        tty.c_cflag &= ~CSTOPB;     /* only need 1 stop bit */   
	tty.c_cflag &= ~CRTSCTS;    /* no hardware flowcontrol */ 
                                                                  
                                                                  
        tty.c_iflag = IGNPAR;                                     
        tty.c_lflag = 0;                                          
                                                                  
                                                                  
        tty.c_cc[VMIN] = 1;                                       
        tty.c_cc[VTIME] = 1;                                      
                                                                  
        if (tcsetattr(fd, TCSANOW, &tty) != 0)                    
        {                                                         
                printf("Error from tcsetattr: %s\n", strerror(err;
                return -1;                                        
        }                                                         
        return 0;                                                 
}                                                                 
                                                                  
int main()                                                        
{                                                                 
    char *portname = "/dev/ttyS3";                                
    int fd;                    
      int wlen;                                                     
    int rdlen;                                                    
    int ret;                                                      
                                                                  
    char res[5];                                                  
    char arr1[] = "CMD+RESET\r\n";                                
    char arr2[] = "CMD+WIFIMODE=1\r\n";                           
    char arr[] = "CMD+CONTOAP=\"realme X7 Max\",\"0987654321\"\r\;
    char arr3[] = "CMD+MQTTNETCFG=dev.rightech.io,1883\r\n";      
    char arr4[] = "CMD+MQTTCONCFG=3,mqtt-vageshradhya-oawdww,,,,,;
    char arr5[] = "CMD+MQTTSTART=1\r\n";                          
    char arr6[] = "CMD+MQTTSUB=base/relay/led1\r\n";              
    unsigned char buf[100];                                       
                                                                  
    fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);              
    if (fd < 0)                                                   
    {                                                             
        printf("Error opening %s: %s\n", portname, strerror(errno;
        return -1;                                                
    }                                                             
    set_interface_attribs(fd, B38400);           
    printf("%s", arr1);                                           
    wlen = write(fd, arr1, sizeof(arr1) - 1);                     
    sleep(3);                                                     
                                                                  
    printf("%s", arr2);                                           
    wlen = write(fd, arr2, sizeof(arr2) - 1);                     
    sleep(3);                                                     
                                                                  
    printf("%s", arr);                                            
    wlen = write(fd, arr, sizeof(arr) - 1);                       
    sleep(3);                                                     
                                                                  
    printf("%s", arr3);                                           
    wlen = write(fd, arr3, sizeof(arr3) - 1);                     
    sleep(3);                                                     
                                                                  
    printf("%s", arr4);                                           
    wlen = write(fd, arr4, sizeof(arr4) - 1);                     
    sleep(3);                                                     
                                                                  
    printf("%s", arr5);                                           
    wlen = write(fd, arr5, sizeof(arr5) - 1);                     
    sleep(3); 
    
     printf("%s", arr6);                                           
    wlen = write(fd, arr6, sizeof(arr6) - 1);                     
    sleep(3);                                                     
    char buffer[100];                                             
    while(1){                                                     
        rdlen = read(fd, buf, sizeof(buf));                       
        buf[rdlen]='\0';                                          
        if (rdlen > 0) {                                          
                 //printf("%s\n", buf);                           
                 //sleep(3);                                      
        } else {                                                  
                printf("No data received\n");                     
        }                                                         
        ret = snprintf(buffer, sizeof(buffer), "CMD+MQTTPUB=readin
                                                                  
        if (ret < 0) {                                            
                // Handle the error if snprintf fails             
        } else {                                                  
                ssize_t wlen = write(fd, buffer, ret);            
                //sleep(3);                                       
        if (wlen == -1) {                                         
            // Handle the write error if needed  
                    }                                                         
    }                                                             
//}                                                               
}                                                                 
                                                                  
                                                                  
                                                                  
    close(fd);                                                    
    return 0;                                                     
}                   
