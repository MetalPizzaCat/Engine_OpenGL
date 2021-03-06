#include "World.h"
#include "Game.h"



Array<Engine::CActor*> Engine::CWorld::GetActorsOfClass(String className)
{
	if (!actors.empty())
	{
		Array<Engine::CActor*> result = Array<Engine::CActor*>();
		for (int i = 0; i < actors.size(); i++)
		{
			if (actors[i]->IsOfClass(className))
			{
				result.push_back(actors[i]);
			}
		}
		return result;
	}
	return Array<Engine::CActor*>();
}

void Engine::CWorld::Update(float deltaTime)
{
	/*Issue: when updating some actors might be marked as "pending kill" and will need to be deleted, when deleting array will change size
	* Solution do iteration twice -> skip the ones that have death mark first time and then do reverse iteration deleting those marked to be dead
	*/
	if (!actors.empty())
	{
		for (int i = 0; i < actors.size(); i++)
		{
			if (actors[i]->Valid()) 
			{
				actors[i]->Update(deltaTime);
			}
		}

		//it is constant to avoid issues with array shirnking
		const uint size = actors.size();
		for (int i = size - 1; i > Index_None; --i)
		{
			if (!actors[i]->Valid())
			{
				delete actors[i];
			}
		}
	}
}

void Engine::CWorld::Init()
{
	if (!actors.empty())
	{
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Init();
		}
	}
}

Engine::CWorld::~CWorld()
{
	if (!actors.empty())
	{
		//it is constant to avoid issues with array shirnking
		const uint size = actors.size();
		for (int i = size - 1; i > Index_None; --i)
		{
			delete actors[i];
		}
	}
}
