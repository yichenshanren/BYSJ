#pragma once
using namespace std;
class MConstant {
public :
	static const int WINDOW_HEIGHT = 640; // ��Ļ ��
	static const int WINDOW_WIDHT = 960; // ��Ļ ��

	static const int SET_CLOSE = 10000;// ���� -- �رհ�ť
	static const int SET_ABOUT = 10001;// ���� -- ���ڰ�ť
	static const int SET_SHARE = 10002;// ���� -- ����ť
	static const int SET_MUSIC = 10003;// ���� -- ���ְ�ť

	static const int START_START = 10004; // ��ʼ -- ��ʼ��Ϸ��ť
	static const int START_SETTING = 10005;// ��ʼ -- ���ð�ť
	static const int START_QUIT = 10006; // ��ʼ -- �˳���ť

	static const int POP_WINDOW_MENU = 10007; // ���� -- �˵�
	static const int GAMESCENE = 10008; // game scene

//	int coin[2][2] = { { 2, 2 }, { 2, 3 } };
	static string toString(int i){
		stringstream ss;
		string s;
		ss << i;
		ss >> s;
		return s;
	};
};