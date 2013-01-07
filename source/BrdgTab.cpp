
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "BrdgTab.h"
#include "model.h"

#include "main.h"

#include "Controller.h"
#include "RadioButton.h"

#include "Controllers.h"

BridgeTabController::BridgeTabController(Controller* superController)
: Controller(superController)
{
	mSuperController = superController;
}

BridgeTabController::~BridgeTabController()
{
}

void BridgeTabController::handleKey()
{
	if(BalanceType->get_CurRB() == 4 || BalanceType->get_CurRB() == -1)
	{
		BalanceAmount->set_CurRB(-1);
		BalanceAmount->set_disabled(true);
	}
	else
		BalanceAmount->set_disabled(false);
	
	if (mSuperController)
		mSuperController->handleKey();
}

void BridgeTabController::loadData(const BrdgData& BrdgInfo)
{
	BalanceType->set_CurRB(BrdgInfo.BalanceType);
	BalanceAmount->set_CurRB(BrdgInfo.BalanceAmount);
}

void BridgeTabController::saveData(BrdgData* BrdgInfo)
{
	BrdgInfo->BalanceType = BalanceType->get_CurRB();
	BrdgInfo->BalanceAmount = BalanceAmount->get_CurRB();
}

void BridgeTabController::set_BalanceType(RBGroup* rbg)
{
	BalanceType = rbg;
}

void BridgeTabController::set_BalanceAmount(RBGroup* rbg)
{
	BalanceAmount = rbg;
}

Tab* initBrdgTab()
{
	
	Tab* BrdgTab = new Tab(MainViews::Game, Point(128,0), BridgeTab_Sprite, &BGBridge, Controllers::brdgTabController);
	
	View* BrdgTopLeftPoint = new View(NULL, kBottomScreen, Point(0, 32));
	
		RBGroup* BalanceType = new RBGroup(BrdgTopLeftPoint, Point(35,4));
		
			RadioButton* Balance = new RadioButton(BalanceType, Point(0,0), Balanc_Sprite);
			RadioButton* BalanCO = new RadioButton(BalanceType, Point(0,29), BalanCO_Sprite);
			RadioButton* AttBal = new RadioButton(BalanceType, Point(0,60), AttBal_Sprite);
			RadioButton* AttBalCO = new RadioButton(BalanceType, Point(0,89), AttBalCO_Sprite);
			RadioButton* None = new RadioButton(BalanceType, Point(0,120), none_Sprite);
		
		BalanceType->add(Balance);
		BalanceType->add(BalanCO);
		BalanceType->add(AttBal);
		BalanceType->add(AttBalCO);
		BalanceType->add(None);
		
		BrdgTab->add(BalanceType);
			Controllers::brdgTabController->set_BalanceType(BalanceType);
		
		RBGroup* BalanceAmount = new RBGroup(BrdgTopLeftPoint, Point(156,31));
		
			RadioButton* OneBot = new RadioButton(BalanceAmount, Point(0,0), One_Sprite);
			RadioButton* TwoBot = new RadioButton(BalanceAmount, Point(0,32), Two_Sprite);
			RadioButton* ThreeBot = new RadioButton(BalanceAmount, Point(0,64), Three_Sprite);
		
		BalanceAmount->add(OneBot);
		BalanceAmount->add(TwoBot);
		BalanceAmount->add(ThreeBot);
		
		BrdgTab->add(BalanceAmount);
			Controllers::brdgTabController->set_BalanceAmount(BalanceAmount);
	
	return BrdgTab;
}