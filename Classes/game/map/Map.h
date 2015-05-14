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
	
	/* 主角背景 */
	XiYangYang * xiYangYang; // 主角
	BackGround * background; // 背景
	/* 道具 */
	vector<vector<Prop *>> props; // 道具
	int *record;
	vector<Road *> roads; // 路

	int mapLoop; // 地图循环
	int propTotal; // 道具总数
	int mapIndex; // 地图索引
public:
	~SMap();
	bool init();
	static SMap * createMap();
	CREATE_FUNC(SMap);
	// 获取 主角
	XiYangYang * getCharacter();
	// 计划任务
	void update(float t);
	void updateUi(float t);
	/* 从地图中加载道具 */
	Prop * addNewPropFormMap(MapData map); // 新建道具
	void addPropToMap(); // 根据数据将道具添加到场景
	void initPropVector();
	void initPropRecoders();
};