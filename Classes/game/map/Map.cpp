#include "Map.h"


SMap * SMap::createMap(){
	auto map = SMap::create();
	return map;
}
bool SMap::init(){
	if ( ! Layer::init() ){
		return false;
	}
	/* 初始gamedata */
	GameData::getInstance()->initLayer(this);
	/* 添加背景 */
	background = new BackGround();
	background->addTo(this);
	/* 添加喜羊羊 */
	xiYangYang = new XiYangYang();
	this->addChild(xiYangYang->getNode(), 2);
	/* 添加路 */
	roads.reserve(7);
	for (int i = 0; i < 7; i++){
		roads.push_back( new Road( xiYangYang ) );
		roads.at(i)->setEnable(true);
		roads.at(i)->setPositionX(1160 - i * 180);
		this->addChild(roads.at(i)->getNode());
	}
	/* 将道具各向量加入 */
	initPropVector();
	/* 添加道具 */
	addPropToMap();
	// 执行计划任务
	this->schedule(schedule_selector(SMap::updateUi), 0.001f);
	//this->scheduleUpdate();
	//log(xiYangYang->getPosition().x);
	return true;
}
// 析构
SMap::~SMap(){

}
/*
  读取地图数据
*/
void SMap::initPropVector(){
	mapLoop = 0; // 初始地图循环指数
	mapIndex = 0; // 初始地图索引
	propTotal = MapData::propNum;//   道具总数
	props.reserve(propTotal); // 
	record = new int[propTotal];
	// 初始
	int propNum = 0;
	/* 将游戏中要出现的道具都存在vector中 */
	for (int i = 0; i < propTotal; i ++){
		vector<Prop *> p;
		switch (i){
		case MapData::COIN: // 初始化金币道具----------------
				   p.reserve(40);
				   for (int a = 0; a < 40; a++){
					   p.push_back(new Coin(xiYangYang));
					   this->addChild(p.at(a)->getNode());
				   }
			break;
		case MapData::GUO: // 初始化平底锅道具--------------------
			p.reserve(3);
			for (int b = 0; b < 3; b++){
				p.push_back(new Guo(xiYangYang));
				this->addChild(p.at(b)->getNode());
			}
			break;
		case MapData::SHITOU: // 初始化石头道具------------------------
			p.reserve(3);
			for (int b = 0; b < 3; b++){
				p.push_back(new ShiTou(xiYangYang));
				this->addChild(p.at(b)->getNode());
			}
			break;
		case MapData::LANG: // 初始化灰太狼道具----------------------- 
			p.reserve(3);
			for (int b = 0; b < 3; b++){
				p.push_back(new Lang(xiYangYang));
				this->addChild(p.at(b)->getNode());
			}
			break;
		case MapData::FOOD: // 初始化食物道具----------------------- 
			p.reserve(3);
			for (int b = 0; b < 3; b++){
				p.push_back(new Food(xiYangYang, ( b + 1 ) * 5));
				this->addChild(p.at(b)->getNode());
			}
			break;
		case MapData::LANPROP: // 初始化懒洋洋道具----------------------- 
			p.reserve(1);
			p.push_back(new LanProp(xiYangYang));
			this->addChild(p.at(0)->getNode());
			break;
		case MapData::FEIPROP: // 初始沸羊羊道具----------------------- 
			p.reserve(1);
			p.push_back(new FeiProp(xiYangYang));
			this->addChild(p.at(0)->getNode());
			break;
		}
		/* 将各类型的道具存入道具向量 */
		props.push_back(p);
	}
	initPropRecoders();
}
/*
  根据map中道具的类型创建新的道具
*/
Prop * SMap::addNewPropFormMap(MapData map){
	Prop * prop = NULL;
	switch (map.type){
		/* 添加金币 */
	case MapData::COIN:
		prop = new Coin(xiYangYang);
		break;
		/* 添加平底锅 */
	case MapData::GUO:
		prop = new Guo(xiYangYang);
		break;
		/* 添加石头 */
	case MapData::SHITOU:
		prop = new ShiTou(xiYangYang);
		break;
		/* 添加灰太狼 */
	case MapData::LANG:
		prop = new Lang(xiYangYang);
		break;
	default :
		break;
	}
	if (prop != NULL){
		prop->setPosition(ccp(map._x, map._y));
		this->addChild(prop->getNode());
	}
	return prop;
}
/*
  添加道具到地图
*/
void SMap::addPropToMap(){
	mapLoop = 0;
	bool flag = false;
	if (mapIndex == MapData::mapLenth){
		mapIndex = 0;
		log("test ppppppppppppppppppppppppppppppppppppppppppp");
	}
	/* 遍历mapdata */
	for (int m = mapIndex; m < MapData::mapLenth; m ++){
		/* 一页地图的结束 */
		// 没有遇到结束标志符时
		if (mdatas[m].type != MapData::END){
			MapData map = mdatas[m];
			/* 判断record[map.type] 的值是否小于props.at(map.type).size()
			   小于则props.at(map.type)中有可用的道具
			   大于则新建此类道具，并添加到props.at(map.type)中
			*/
				if (record[map.type] < (int) (props.at(map.type).size())){
					/* 遍历props.at(map.type)找到其中可用的道具 */
					for (int i = record[map.type]; i < (int)props.at(map.type).size(); i++){
						/* 假如某个道具可用 */
						if (!props.at(map.type).at(i)->getEnable()){
							/* 将地图中的数据赋值给该道具 */
							props.at(map.type).at(i)->setPosition(ccp(map._x, map._y));
							props.at(map.type).at(i)->setEnable(true);
							/* record赋值为i + 1 以便下次遍历 */
							record[map.type] = i + 1;
							/* flag为true则此类道具向量中存在可用道具 */
							flag = true;
							log("type: %d", map.type);
							break;
						}
					}
					/* 遍历结束 判断此向量中是否存在可用道具 */
					if (!flag){ // 不存在可用道具 
						record[map.type] = props.at(map.type).size();
					}
					else { // 存在可用道具初始化flag
						flag = false;
					}
				}
				else {
					// 如果此类道具向量中的道具数量不够，则新建
					props.at(map.type).push_back(addNewPropFormMap(map));
					record[map.type] ++;
				}
		}
		/* 遇到地图 结束标志跳出此次循环 */
		else {
			break;
		}
		/* 每循环一次 */
		mapIndex++;
		log("mapIndex: %d", mapIndex);
	}
	mapIndex++;
	/* 此次循环结束重置record数组 */
	initPropRecoders();
}
/*
 重置record数组 
*/
void SMap::initPropRecoders(){
	for (int i = 0; i < propTotal; i++){
		record[i] = 0;
	}
}
// 获取主角
// 此处为获取喜羊羊
XiYangYang * SMap::getCharacter(){
	return this->xiYangYang;
}

void SMap::update(float t){
}
void SMap::updateUi(float t){
	if (xiYangYang->getAlive()){
		GameData::getInstance()->setMi(1);
		/* 路的滚动 */
		for (auto road : roads){
			if (road->getNode()->getPositionX() <= -90.0f){ // 一段路移动到屏幕外面以后
				road->setPositionX(1078); // 重设X，该段路从右边重新滚动
				road->setNormalY();
				road->setEnable(true);
			}
			// 路的滚动
			road->setPositionX(road->getPosition().x - xiYangYang->getSpeed());
			//road->move();
			road->collision();
		}
		/* 背景滚动 */
		background->move();
		/* 道具滚动 */
		for (auto prop : props){
			for (auto p : prop){
				p->move();
			}
		}
		/* 从地图加载道具  */
		if (mapLoop > 900){ // 每900个像素加载一次地图
			addPropToMap();
		}
		else {
			mapLoop += xiYangYang->getSpeed();
		}
	}
}