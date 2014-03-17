#include "stdafx.h"
#include "Server.h"


Server::Server()
{
}


Server::~Server()
{
}

bool Server::init()
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
	servAddr = { 0 };
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(PORT);
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	//바인드
	result = bind(hServSock, (SOCKADDR*)&servAddr, sizeof(SOCKADDR));

	if (result != 0)
	{
		printf("error");
		return false;
	}

	//연결 대기
	listen(hServSock, 10);

	clntAddr = { 0 };
	int size = sizeof(SOCKADDR_IN);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &size);

	if (hClntSock == SOCKET_ERROR)
	{
		printf("error");
		return false;
	}
	
	return true;
}

void Server::loop()
{
	while (true)
	{
		char buf1[] = "a";
		char buf2[] = "bcd";
		char buf3[] = "ef";
		char buf4[] = "ghijk";

		//문자열 길이 부터 송신
		int len = strlen(buf1) + strlen(buf2) + strlen(buf3) + strlen(buf4);
		send(hClntSock, (char*)&len, sizeof(int), 0);

		send(hClntSock, buf1, sizeof(buf1), 0);
		send(hClntSock, buf2, sizeof(buf2), 0);
		send(hClntSock, buf3, sizeof(buf3), 0);
		send(hClntSock, buf4, sizeof(buf4), 0);
	}
}
