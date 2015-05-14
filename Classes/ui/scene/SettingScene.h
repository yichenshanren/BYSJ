#pragma once
#include "ui/common/BaseScene.h"
#include "data/MConstant.h"
/**  @·ң 2015
* ��Ϸ���ý���
* ����Ϸ��ʼ�����ϵ����˽���
*/
class SettingScene :public BaseScene{
private :
	MenuItemImage * closeBtn;
public:
	SettingScene(void);
    ~SettingScene(void);
	
	bool init();
	static SettingScene * createLayer();
	CREATE_FUNC(SettingScene);
	
	void eventCallBack(Ref * pSender);
	// ���ùرհ�ť�ص�����
	void setCloseCallBack(const ccMenuCallback& callback);
};