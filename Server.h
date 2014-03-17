#pragma once

class Server
{


private:

	//소켓의 버전 정보
	WSADATA wsaData;
	//소켓
	SOCKET hServSock;
	//서버 주소
	SOCKADDR_IN servAddr;

	//클라이언트 소켓
	SOCKET hClntSock;

	//클라이언트 소켓 주소
	SOCKADDR_IN clntAddr;

public:
	Server();
	~Server();

	bool init();
	void loop();
};

