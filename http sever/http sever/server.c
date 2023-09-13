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
	//��������˵�socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);//�̶�
	if (-1 == socket_fd)
	{
		perror("socket");
		return -1;
	}
	//��ַ���˿ڰ�
	//struct sockaddrһ�㲻ʹ�ã�һ��ʹ�öԵȵ�sockaddr_in����netinet/in.h��
	struct sockaddr_in serverDressInfo;
	memset(&serverDressInfo, 0, sizeof(serverDressInfo));
	//Э���壬��socket�����ʹ��AF_INET
	serverDressInfo.sin_family = AF_INET;
	//��������ip
	serverDressInfo.sin_addr.s_addr = htonl(INADDR_ANY);
	//���ö˿�
	serverDressInfo.sin_port = htons(atol(argv[1]));
	//���а󶨣��ֱ�Ϊsock�ļ�������������Ϣ�ṹ��ĵ�ַ���Լ��ṹ���С
	int bind_rt = bind(socket_fd, (struct sockaddr_in*)&serverDressInfo, sizeof(serverDressInfo));
	if (-1 == bind_rt)
	{
		perror("bind");
		return -1;
	}
	//��socket����Ϊ����ģʽ
	//��һ������Ϊ�󶨺���ļ����������ڶ����������ڸ���
	int listen_stat = listen(socket_fd, 10);
	if (-1 == listen_stat)
	{
		perror("listen");
		return -1;
	}
	//���ӿͻ���
	printf("waiting client connection...");
	int done = 1;
	//���ܡ����ͱ���,����
	while (done)
	{
		struct sockaddr_in client;
		int clientSock_fd;
		int length;
		char clientIp[64];
		char buf[BUFSIZE];

		//����
		socklen_t clientAddrLen;
		clientAddrLen = sizeof(client);
		clientSock_fd = accept(socket_fd, (struct sockaddr_in*)&client, &clientAddrLen);
		if (-1 == clientSock_fd)
		{
			perror("accept");
			return -1;
		}
		//����ͻ�����Ϣ,��ӡ�ͷ���IP��ַ�Ͷ˿ں�
		printf("client ip: %s\t port : %d\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, clientIp, sizeof(clientIp)), ntohs(client.sin_port));
		//��ȡ�ͻ��˷�������
		client_data_processing(clientSock_fd);

		//�ر��ļ�
		close(clientSock_fd);
	}
	//�ر�socket���ͷ���Դ
	close(socket_fd);
}

int getLine(int fd, char* buf, int size)
{
	memset(buf, 0, size);
	int len = 0;
	char* flag;
	//ÿ��һ���ַ������ж�


#if 0 //windows�� 
	while (len < size - 1 && flag != '\n')
	{
		int rd_n = read(fd, flag, 1);
		if (1 == rd_n)
		{
			//�����س�ʱ������
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

#if 1 //linux��
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
	printf("���󷽷�Ϊ��%s", method);
	printf("urlΪ��%s", url);
	printf("Э��汾Ϊ��%s", http);
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
	//���Խ�����������
	printf("����Ϊ��%s", buf);
}
//�ͻ������ݴ���
void client_data_processing(int client_fd)
{
	char* buf[BUFSIZE];
	int len;
	len = getLine(client_fd, buf, sizeof(buf));
	printf("read info:\n%s\n", buf);
	//�����е���Ϣ����
	requestLineInfo(buf, len);
	do {
		//����ͷ����Ϣ����
		len = getLine(client_fd, buf, sizeof(buf));
		requestHeadInfo(buf, len);
	} while (len != 0);
	//�������ݴ���
	//Ӧ���ҵ�fd��ĩβ��Ϊ�ж�����
	len = getLine(client_fd, buf, sizeof(buf));
	requestData(buf, len);
}
