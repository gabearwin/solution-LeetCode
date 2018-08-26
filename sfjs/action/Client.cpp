#include<iostream>
//#include<stdio.h>
#include<WinSock2.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
const char *SERVERIPADDRESS = "127.0.0.1";
int main()
{
	bool bSuccess = FALSE;
	SOCKET socketClient = INVALID_SOCKET;//客户端的套接字
	do
	{
		WSADATA wsaData;
		if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))//叫醒
				break;
		//判断
		if (2 != LOBYTE(wsaData.wVersion) ||2 != HIBYTE(wsaData.wVersion))
				break;


		//创建套接字
		socketClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (INVALID_SOCKET == socketClient)
				break;


		//服务器地址
		sockaddr_in addrServ = { 0 };
		addrServ.sin_family = AF_INET;
		addrServ.sin_port = htons(7000);
		addrServ.sin_addr.S_un.S_addr = inet_addr(SERVERIPADDRESS);
		if (SOCKET_ERROR == connect(socketClient, (SOCKADDR*)&addrServ, sizeof(addrServ)))
				break;
		char szRecvMessage[MAXBYTE] = { 0 };
		char szSendMessage[MAXBYTE] = { 0 };
		while (true)
		{
			int nResult = recv(socketClient, szRecvMessage, MAXBYTE, 0);
			if (nResult > 0)//接收到信息
			{
				cout << "Receive Messages:：" << szRecvMessage << endl;
				cout << "Reply：";
				cin >> szSendMessage;
				if (SOCKET_ERROR == send(socketClient, szSendMessage, MAXBYTE, 0))
						 break;//跳出循环
			}
			else if (nResult == 0)//连接被关闭
			{
				cout << "Connection is closed:" << endl;
				break;
			}
			else
			{
				cout << "Unknown reason：" << endl;
				break;
			}
		}
		bSuccess = TRUE;
	} while (FALSE);


	if (!bSuccess)
	{
		int nError=WSAGetLastError();
		cout << "error" << nError << endl;
		if (INVALID_SOCKET != socketClient)
				closesocket(socketClient);


	}
		WSACleanup();
		system("pause");
		return 0;
}
