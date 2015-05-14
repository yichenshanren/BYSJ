#pragma once
#include "ui/common/BaseScene.h"

class PopWindow : public BaseScene{
public :
	bool init();
	static PopWindow * createLayer();
	CREATE_FUNC(PopWindow);

	void setTitle(Sprite * titleImage);
	// 设置按钮
	void addButton(MenuItemImage * btn);
	// 移除动画
	void remove();
	// 设置取消按钮
	void setCancelBtn(Sprite *normal, Sprite *press);
	void setCancelBtn(Sprite *normal, Sprite *press, const ccMenuCallback& callback);
	// 设置弹窗内容
	void setContent(Sprite *cotent);
	
private:
	MenuItemImage * cancelBtn; // 弹窗取消按钮
};