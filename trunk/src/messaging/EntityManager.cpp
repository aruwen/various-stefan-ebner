#include "EntityManager.h"
#include "BaseGameEntity.h"

EntityManager::EntityManager(void)
{
	mNumberOfEntities = 0;
}

EntityManager* EntityManager::getInstance()
{
	static EntityManager instance;

	return &instance;
}

int EntityManager::addEntity( BaseGameEntity* entity )
{
	mEntityMap.insert(std::make_pair(entity->getID(), entity));
	++mNumberOfEntities;
	return mNumberOfEntities;
}

void EntityManager::removeEntity( BaseGameEntity* entity )
{
	mEntityMap.erase(mEntityMap.find(entity->getID()));
}

BaseGameEntity* EntityManager::getEntityFromID( int id )
{

	std::map<int, BaseGameEntity*>::iterator it;
	
	it = mEntityMap.find(id);
	if(it != mEntityMap.end())
	{
		return it->second;
	}
	else return NULL;
}
