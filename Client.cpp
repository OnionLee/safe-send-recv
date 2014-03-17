#include "stdafx.h"
#include "Client.h"


Client::Client()
{
}


Client::~Client()
{
}

bool Client::init()
{
	//���� ����
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0)
	{
		printf("error");
		return false;
	}

	//���� ����(TCP ���� UDP����)
	hServSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//������ ����
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(PORT);
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	result = connect(hServSock, (SOCKADDR*)&servAddr, sizeof(SOCKADDR));
	if (result == SOCKET_ERROR)
	{
		printf("connect() Error\n");
		return false;
	}


	return true;
}

void Client::loop()
{
	int count = 0;
	int len = 4;
	int sended = 0;
	//�󸶳� ������ ���� Ȯ��
	while (count != len)
	{
		count += recv(hServSock, (char *)&sended + count, len - count, 0);
		printf("���� �����ʹ� %d\n", len);
	}
	printf("���� ����\n");

	count = 0;
	while (count != sended)
	{
		char buf[256];
		count += recv(hServSock, buf + count, sended - count, 0);
		printf("%s", buf);
	}

}
