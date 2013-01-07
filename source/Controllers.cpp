
#include "Controllers.h"

#include "IncludeTabs.h"

#include "View.h"
#include "raguna.h"
#include "Point.h"

namespace Controllers
{
	Controller* Super = new Controller(NULL);
		GameTabsController* gameTabsController = new GameTabsController(Super);
			HydTabController* hydTabController = new HydTabController(gameTabsController);
			TeleTabController* teleTabController = new TeleTabController(gameTabsController);
			BridgeTabController* brdgTabController = new BridgeTabController(gameTabsController);
			EndTabController* endTabController = new EndTabController(gameTabsController);
		InfoTabsController* infoTabsController = new InfoTabsController(Super);
			InitTabController* initTabController = new InitTabController(infoTabsController);
}

namespace MainViews
{
	View* Game = new View(NULL, kBottomScreen, Point(0,0));
	View* Info = new View(NULL, kTopScreen, Point(0,0));
	
	View* ReboundRumble = new View(NULL, NULL, Point(0,0));
}