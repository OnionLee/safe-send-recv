#pragma once
class Client
{
private:
	//소켓의 버전 정보
	WSADATA wsaData;
	//소켓
	SOCKET hServSock;
	//서버 주소
	SOCKADDR_IN servAddr;


public:
	Client();
	~Client();

	bool init();
	void loop();

};

