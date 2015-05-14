#pragma once
#include "ui/common/BaseScene.h"

class PopWindow : public BaseScene{
public :
	bool init();
	static PopWindow * createLayer();
	CREATE_FUNC(PopWindow);

	void setTitle(Sprite * titleImage);
	// ���ð�ť
	void addButton(MenuItemImage * btn);
	// �Ƴ�����
	void remove();
	// ����ȡ����ť
	void setCancelBtn(Sprite *normal, Sprite *press);
	void setCancelBtn(Sprite *normal, Sprite *press, const ccMenuCallback& callback);
	// ���õ�������
	void setContent(Sprite *cotent);
	
private:
	MenuItemImage * cancelBtn; // ����ȡ����ť
};