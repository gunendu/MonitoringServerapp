/* 
 * File:   defines.h
 * Author: Gunendu das
 *
 * Created on 10 September, 2012, 6:14 PM
 */

#ifndef DEFINES_H
#define	DEFINES_H

#define SUCCESS                 1
#define FAILURE                 0
#define MAXIMUM_TIME_SEND_BLOCKED    5
#define SYSTEM_CALL_ERROR      -1
#define THREAD_API_SUCCESS      0
#define POSIX_YEAR_OFFSET       1900
#define MICROSECOND_TO_MILLISECOND(_nMicrosecond) (_nMicrosecond > 1000) ?\
                                                  (_nMicrosecond / 1000) : 0
#define LOG_LOCATION            __FILE__, __FUNCTION__, __LINE__
#define ERROR_STRING                            255
#define LOG_TIME_STAMP_BUF_SIZE			15	
#define MSG_Q_MAX_DEPTH				2700

#define MSG_Q_NAME_LEN  			255
#define MSG_Q_MSG_SIZE                          8024   

#define PMODE_FOR_POSIX_MQ			0777


#define ESCAPE_CHARACTER_LEN  1
#define MAX_DIRECTORY_LEN     254 + ESCAPE_CHARACTER_LEN
#define MAX_LOG_FILE_NAME_LEN 256
#define MAX_PATH_LEN          MAX_DIRECTORY_LEN + MAX_LOG_FILE_NAME_LEN
#define IP_ADDRESS_LEN        32

#define MAX_SOCKET_SEND_BUFFER       2048
#define MAX_SOCKET_RECV_BUFFER       5860 
#define MAX_SOCKET_CONNECTION        50
#define CONTROLLER_POLL_SIZE MAX_SOCKET_CONNECTION
#define MAX_LISTENER_EVENTS					1
#define LISTENER_POLL_SIZE					5

#define LISTENER_EPOLL_WAIT_TIME			1000
#define TCP_KEEP_ALIVE						1
#define TCP_KEEP_INTERVAL					30
#define CONNECTION_BACKLOG_DEFAULT			-1

#define DEFAULT_CONNECTION_BACKLOG			(-1)
#define SYSTEM_CALL_ERROR					-1
#define LINGER_ONOFF_STATUS					1
#define LINGER_VALUE						10
#define AUTOTUNE_SEND_RECV_BUFF				-1
#define MAX_GROUP_COUNT						8


#define MEGA_BYTES					       (1048576)
#define CONTROLLER_EPOLL_WAIT_TIME                             1000

#define COND_WAIT_TIME_INTERVAL                 (50000000)       //100 nano seconds
#define SEC_IN_NANO_SEC                         (1000000000L)
#define SEC_IN_MICRO_SEC                        (1000000L)
#define MILLI_IN_NANO_SEC                       (1000000L)

#define MAX_USER_THREADS                        7
#define USER_NAME                               20
#define PASS_WORD                               20
#define PROCESSNAME_LEN                         64
#define MAX_DIR_LENGTH                          32
#define PORT_LENGTH                             6


#endif	/* DEFINES_H */

