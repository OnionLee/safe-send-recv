#pragma once
class Client
{
private:
	//������ ���� ����
	WSADATA wsaData;
	//����
	SOCKET hServSock;
	//���� �ּ�
	SOCKADDR_IN servAddr;


public:
	Client();
	~Client();

	bool init();
	void loop();

};

