#pragma once

class Server
{


private:

	//������ ���� ����
	WSADATA wsaData;
	//����
	SOCKET hServSock;
	//���� �ּ�
	SOCKADDR_IN servAddr;

	//Ŭ���̾�Ʈ ����
	SOCKET hClntSock;

	//Ŭ���̾�Ʈ ���� �ּ�
	SOCKADDR_IN clntAddr;

public:
	Server();
	~Server();

	bool init();
	void loop();
};

