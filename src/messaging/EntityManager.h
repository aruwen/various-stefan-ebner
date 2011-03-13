#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <map>

class BaseGameEntity;

#define EM EntityManager::getInstance()

class EntityManager
{
public:
	static EntityManager* getInstance();
	int addEntity(BaseGameEntity* entity);
	void removeEntity(BaseGameEntity* entity);
	BaseGameEntity* getEntityFromID(int id);

private:
	EntityManager(void);
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);

	int mNumberOfEntities;
	std::map<int, BaseGameEntity*> mEntityMap;
};

#endif