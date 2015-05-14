#include "Map.h"


SMap * SMap::createMap(){
	auto map = SMap::create();
	return map;
}
bool SMap::init(){
	if ( ! Layer::init() ){
		return false;
	}
	/* ��ʼgamedata */
	GameData::getInstance()->initLayer(this);
	/* ��ӱ��� */
	background = new BackGround();
	background->addTo(this);
	/* ���ϲ���� */
	xiYangYang = new XiYangYang();
	this->addChild(xiYangYang->getNode(), 2);
	/* ���· */
	roads.reserve(7);
	for (int i = 0; i < 7; i++){
		roads.push_back( new Road( xiYangYang ) );
		roads.at(i)->setEnable(true);
		roads.at(i)->setPositionX(1160 - i * 180);
		this->addChild(roads.at(i)->getNode());
	}
	/* �����߸��������� */
	initPropVector();
	/* ��ӵ��� */
	addPropToMap();
	// ִ�мƻ�����
	this->schedule(schedule_selector(SMap::updateUi), 0.001f);
	//this->scheduleUpdate();
	//log(xiYangYang->getPosition().x);
	return true;
}
// ����
SMap::~SMap(){

}
/*
  ��ȡ��ͼ����
*/
void SMap::initPropVector(){
	mapLoop = 0; // ��ʼ��ͼѭ��ָ��
	mapIndex = 0; // ��ʼ��ͼ����
	propTotal = MapData::propNum;//   ��������
	props.reserve(propTotal); // 
	record = new int[propTotal];
	// ��ʼ
	int propNum = 0;
	/* ����Ϸ��Ҫ���ֵĵ��߶�����vector�� */
	for (int i = 0; i < propTotal; i ++){
		vector<Prop *> p;
		switch (i){
		case MapData::COIN: // ��ʼ����ҵ���----------------
				   p.reserve(40);
				   for (int a = 0; a < 40; a++){
					   p.push_back(new Coin(xiYangYang));
					   this->addChild(p.at(a)->getNode());
				   }
			break;
		case MapData::GUO: // ��ʼ��ƽ�׹�����--------------------
			p.reserve(3);
			for (int b = 0; b < 3; b++){
				p.push_back(new Guo(xiYangYang));
				this->addChild(p.at(b)->getNode());
			}
			break;
		case MapData::SHITOU: // ��ʼ��ʯͷ����------------------------
			p.reserve(3);
			for (int b = 0; b < 3; b++){
				p.push_back(new ShiTou(xiYangYang));
				this->addChild(p.at(b)->getNode());
			}
			break;
		case MapData::LANG: // ��ʼ����̫�ǵ���----------------------- 
			p.reserve(3);
			for (int b = 0; b < 3; b++){
				p.push_back(new Lang(xiYangYang));
				this->addChild(p.at(b)->getNode());
			}
			break;
		case MapData::FOOD: // ��ʼ��ʳ�����----------------------- 
			p.reserve(3);
			for (int b = 0; b < 3; b++){
				p.push_back(new Food(xiYangYang, ( b + 1 ) * 5));
				this->addChild(p.at(b)->getNode());
			}
			break;
		case MapData::LANPROP: // ��ʼ�����������----------------------- 
			p.reserve(1);
			p.push_back(new LanProp(xiYangYang));
			this->addChild(p.at(0)->getNode());
			break;
		case MapData::FEIPROP: // ��ʼ���������----------------------- 
			p.reserve(1);
			p.push_back(new FeiProp(xiYangYang));
			this->addChild(p.at(0)->getNode());
			break;
		}
		/* �������͵ĵ��ߴ���������� */
		props.push_back(p);
	}
	initPropRecoders();
}
/*
  ����map�е��ߵ����ʹ����µĵ���
*/
Prop * SMap::addNewPropFormMap(MapData map){
	Prop * prop = NULL;
	switch (map.type){
		/* ��ӽ�� */
	case MapData::COIN:
		prop = new Coin(xiYangYang);
		break;
		/* ���ƽ�׹� */
	case MapData::GUO:
		prop = new Guo(xiYangYang);
		break;
		/* ���ʯͷ */
	case MapData::SHITOU:
		prop = new ShiTou(xiYangYang);
		break;
		/* ��ӻ�̫�� */
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
  ��ӵ��ߵ���ͼ
*/
void SMap::addPropToMap(){
	mapLoop = 0;
	bool flag = false;
	if (mapIndex == MapData::mapLenth){
		mapIndex = 0;
		log("test ppppppppppppppppppppppppppppppppppppppppppp");
	}
	/* ����mapdata */
	for (int m = mapIndex; m < MapData::mapLenth; m ++){
		/* һҳ��ͼ�Ľ��� */
		// û������������־��ʱ
		if (mdatas[m].type != MapData::END){
			MapData map = mdatas[m];
			/* �ж�record[map.type] ��ֵ�Ƿ�С��props.at(map.type).size()
			   С����props.at(map.type)���п��õĵ���
			   �������½�������ߣ�����ӵ�props.at(map.type)��
			*/
				if (record[map.type] < (int) (props.at(map.type).size())){
					/* ����props.at(map.type)�ҵ����п��õĵ��� */
					for (int i = record[map.type]; i < (int)props.at(map.type).size(); i++){
						/* ����ĳ�����߿��� */
						if (!props.at(map.type).at(i)->getEnable()){
							/* ����ͼ�е����ݸ�ֵ���õ��� */
							props.at(map.type).at(i)->setPosition(ccp(map._x, map._y));
							props.at(map.type).at(i)->setEnable(true);
							/* record��ֵΪi + 1 �Ա��´α��� */
							record[map.type] = i + 1;
							/* flagΪtrue�������������д��ڿ��õ��� */
							flag = true;
							log("type: %d", map.type);
							break;
						}
					}
					/* �������� �жϴ��������Ƿ���ڿ��õ��� */
					if (!flag){ // �����ڿ��õ��� 
						record[map.type] = props.at(map.type).size();
					}
					else { // ���ڿ��õ��߳�ʼ��flag
						flag = false;
					}
				}
				else {
					// ���������������еĵ����������������½�
					props.at(map.type).push_back(addNewPropFormMap(map));
					record[map.type] ++;
				}
		}
		/* ������ͼ ������־�����˴�ѭ�� */
		else {
			break;
		}
		/* ÿѭ��һ�� */
		mapIndex++;
		log("mapIndex: %d", mapIndex);
	}
	mapIndex++;
	/* �˴�ѭ����������record���� */
	initPropRecoders();
}
/*
 ����record���� 
*/
void SMap::initPropRecoders(){
	for (int i = 0; i < propTotal; i++){
		record[i] = 0;
	}
}
// ��ȡ����
// �˴�Ϊ��ȡϲ����
XiYangYang * SMap::getCharacter(){
	return this->xiYangYang;
}

void SMap::update(float t){
}
void SMap::updateUi(float t){
	if (xiYangYang->getAlive()){
		GameData::getInstance()->setMi(1);
		/* ·�Ĺ��� */
		for (auto road : roads){
			if (road->getNode()->getPositionX() <= -90.0f){ // һ��·�ƶ�����Ļ�����Ժ�
				road->setPositionX(1078); // ����X���ö�·���ұ����¹���
				road->setNormalY();
				road->setEnable(true);
			}
			// ·�Ĺ���
			road->setPositionX(road->getPosition().x - xiYangYang->getSpeed());
			//road->move();
			road->collision();
		}
		/* �������� */
		background->move();
		/* ���߹��� */
		for (auto prop : props){
			for (auto p : prop){
				p->move();
			}
		}
		/* �ӵ�ͼ���ص���  */
		if (mapLoop > 900){ // ÿ900�����ؼ���һ�ε�ͼ
			addPropToMap();
		}
		else {
			mapLoop += xiYangYang->getSpeed();
		}
	}
}