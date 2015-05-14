#pragma once 
#include<vector>
#include "cocos2d.h"
#include "game/common/Prop.h"
#include "game/prop/Road.h"
#include "game/character/XiYangYang.h"
#include "BackGround.h"
#include "game/prop/Coin.h"
#include "data/MapData.h"
#include "data/GameData.h"
#include "game/prop/Guo.h"
#include "game/prop/ShiTou.h"
#include "game/prop/Lang.h"
#include "game/prop/Food.h"
#include "game/prop/LanProp.h"
#include "game/prop/FeiProp.h"
using namespace std;

class SMap : public cocos2d::Layer{
private :
	
	/* ���Ǳ��� */
	XiYangYang * xiYangYang; // ����
	BackGround * background; // ����
	/* ���� */
	vector<vector<Prop *>> props; // ����
	int *record;
	vector<Road *> roads; // ·

	int mapLoop; // ��ͼѭ��
	int propTotal; // ��������
	int mapIndex; // ��ͼ����
public:
	~SMap();
	bool init();
	static SMap * createMap();
	CREATE_FUNC(SMap);
	// ��ȡ ����
	XiYangYang * getCharacter();
	// �ƻ�����
	void update(float t);
	void updateUi(float t);
	/* �ӵ�ͼ�м��ص��� */
	Prop * addNewPropFormMap(MapData map); // �½�����
	void addPropToMap(); // �������ݽ�������ӵ�����
	void initPropVector();
	void initPropRecoders();
};