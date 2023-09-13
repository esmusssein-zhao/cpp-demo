#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 256

void client_data_processing(int  client_fd);
int getLine(int fd, char* buf, int size);
void requestLineInfo(char* buf, int len);
void requestHeadInfo(char* buf, int len);
void requestData(char* buf, int len);


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("input error!");
		return -1;
	}
	//创建服务端的socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);//固定
	if (-1 == socket_fd)
	{
		perror("socket");
		return -1;
	}
	//地址、端口绑定
	//struct sockaddr一般不使用，一般使用对等的sockaddr_in（在netinet/in.h）
	struct sockaddr_in serverDressInfo;
	memset(&serverDressInfo, 0, sizeof(serverDressInfo));
	//协议族，在socket编程中使用AF_INET
	serverDressInfo.sin_family = AF_INET;
	//设置任意ip
	serverDressInfo.sin_addr.s_addr = htonl(INADDR_ANY);
	//设置端口
	serverDressInfo.sin_port = htons(atol(argv[1]));
	//进行绑定，分别为sock文件描述符，绑定信息结构体的地址，以及结构体大小
	int bind_rt = bind(socket_fd, (struct sockaddr_in*)&serverDressInfo, sizeof(serverDressInfo));
	if (-1 == bind_rt)
	{
		perror("bind");
		return -1;
	}
	//把socket设置为监听模式
	//第一个参数为绑定后的文件描述符，第二个参数过于复杂
	int listen_stat = listen(socket_fd, 10);
	if (-1 == listen_stat)
	{
		perror("listen");
		return -1;
	}
	//连接客户端
	printf("waiting client connection...");
	int done = 1;
	//接受、发送报文,处理
	while (done)
	{
		struct sockaddr_in client;
		int clientSock_fd;
		int length;
		char clientIp[64];
		char buf[BUFSIZE];

		//接受
		socklen_t clientAddrLen;
		clientAddrLen = sizeof(client);
		clientSock_fd = accept(socket_fd, (struct sockaddr_in*)&client, &clientAddrLen);
		if (-1 == clientSock_fd)
		{
			perror("accept");
			return -1;
		}
		//输出客户端信息,打印客服端IP地址和端口号
		printf("client ip: %s\t port : %d\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, clientIp, sizeof(clientIp)), ntohs(client.sin_port));
		//读取客户端发送内容
		client_data_processing(clientSock_fd);

		//关闭文件
		close(clientSock_fd);
	}
	//关闭socket，释放资源
	close(socket_fd);
}

int getLine(int fd, char* buf, int size)
{
	memset(buf, 0, size);
	int len = 0;
	char* flag;
	//每次一个字符，并判断


#if 0 //windows下 
	while (len < size - 1 && flag != '\n')
	{
		int rd_n = read(fd, flag, 1);
		if (1 == rd_n)
		{
			//遇到回车时，结束
			if (*flag == '\r')
			{
				buf[len] = '\0';
				break;
			}
			else
			{
				buf[len] = *flag;
				++len;
			}
		}
		else if (-1 == rd_n)
		{
			perror("read");
		}
		else
			break;
	}
#endif

#if 1 //linux下
	while (len < size - 1 && *flag != '\n')
	{
		int rd_n = read(fd, flag, 1);
		if (1 == rd_n)
		{
			buf[len] = *flag;
			++len;
			continue;
		}
		if (-1 == rd_n)
		{
			perror("read");
		}
		else
		{
			break;
		}

	}
	buf[len] = '\0';
#endif
	return len;
}


void requestLineInfo(char* buf, int len)
{
	int flagLen = 0;
	int flag = 0;
	char* method[5];
	char* url[128];
	char* http[10];
	int i = 0;
	memset(method, 0, sizeof(method));
	memset(url, 0, sizeof(url));
	memset(http, 0, sizeof(http));
	while (flagLen != len)
	{
		if (buf[flagLen] == ' ')
		{
			++flagLen;
			++flag;
			i = 0;
			continue;
		}
		else
		{
			if (flag == 0)
			{
				m[flagLen] = buf[flagLen];
				flagLen++;
			}
			else if (flag == 1)
			{
				u[i++] = buf[flagLen];
				flagLen++;
			}
			else
			{
				h[i++] = buf[flagLen];
				flagLen++;
			}
		}
	}
	printf("请求方法为：%s", method);
	printf("url为：%s", url);
	printf("协议版本为：%s", http);
}


void requestHeadInfo(char* buf, int len)
{
	int flag = 0;
	while (*buf != ' ')
	{
		++flag;
	}
	char* name[50];
	memcpy(name, buf, flag);
	name[flag] = '\0';
	char* value[1024];
	for (int i = 0; i < len - flag; i++)
	{
		value[i] = buf[++flag];
	}
	value[++flag] = '\0';
}


void requestData(char* buf, int len)
{
	//可以进行其他处理
	printf("数据为：%s", buf);
}
//客户端数据处理
void client_data_processing(int client_fd)
{
	char* buf[BUFSIZE];
	int len;
	len = getLine(client_fd, buf, sizeof(buf));
	printf("read info:\n%s\n", buf);
	//请求行的信息处理
	requestLineInfo(buf, len);
	do {
		//请求头部信息处理
		len = getLine(client_fd, buf, sizeof(buf));
		requestHeadInfo(buf, len);
	} while (len != 0);
	//请求数据处理
	//应该找到fd的末尾作为判断条件
	len = getLine(client_fd, buf, sizeof(buf));
	requestData(buf, len);
}
