#pragma once
using namespace std;
class MConstant {
public :
	static const int WINDOW_HEIGHT = 640; // 屏幕 高
	static const int WINDOW_WIDHT = 960; // 屏幕 宽

	static const int SET_CLOSE = 10000;// 设置 -- 关闭按钮
	static const int SET_ABOUT = 10001;// 设置 -- 关于按钮
	static const int SET_SHARE = 10002;// 设置 -- 分享按钮
	static const int SET_MUSIC = 10003;// 设置 -- 音乐按钮

	static const int START_START = 10004; // 开始 -- 开始游戏按钮
	static const int START_SETTING = 10005;// 开始 -- 设置按钮
	static const int START_QUIT = 10006; // 开始 -- 退出按钮

	static const int POP_WINDOW_MENU = 10007; // 弹窗 -- 菜单
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