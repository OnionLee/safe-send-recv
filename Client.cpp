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
	//버전 생성
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0)
	{
		printf("error");
		return false;
	}

	//소켓 설정(TCP 할지 UDP할지)
	hServSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//아이피 설정
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
	//얼마나 받을지 먼저 확인
	while (count != len)
	{
		count += recv(hServSock, (char *)&sended + count, len - count, 0);
		printf("받을 데이터는 %d\n", len);
	}
	printf("전송 성공\n");

	count = 0;
	while (count != sended)
	{
		char buf[256];
		count += recv(hServSock, buf + count, sended - count, 0);
		printf("%s", buf);
	}

}
