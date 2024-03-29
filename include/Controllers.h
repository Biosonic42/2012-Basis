
#ifndef _game_Controllers_h
#define _game_Controllers_h

#include "Controller.h"
#include "IncludeTabs.h"

#include "View.h"

namespace Controllers
{
	extern Controller* Super;
		extern GameTabsController* gameTabsController;
			extern HydTabController* hydTabController;
			extern TeleTabController* teleTabController;
			extern BridgeTabController* brdgTabController;
			extern EndTabController* endTabController;
		extern InfoTabsController* infoTabsController;
			extern InitTabController* initTabController;
}

namespace MainViews
{
	extern View* Game;
	extern View* Info;
	
	extern View* ReboundRumble;
}

#endif