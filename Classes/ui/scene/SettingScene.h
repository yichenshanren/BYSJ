#pragma once
#include "ui/common/BaseScene.h"
#include "data/MConstant.h"
/**  @路遥 2015
* 游戏设置界面
* 在游戏开始界面上弹出此界面
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
	// 设置关闭按钮回掉函数
	void setCloseCallBack(const ccMenuCallback& callback);
};