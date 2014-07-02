#include <iostream>
#include "DataDef.hpp"
#include <mysql++.h>
#include <vector>
#include <map>
#include "memorypool/ObjectPool.hpp"


class LoadData{
public:
	LoadData() :
		conn(false){ }

	bool Conn(const char *db, const char *ip, const char *user, const char *password, unsigned int port);
	bool LoadMapData(std::map<int,MapData*> &mapm);
	bool LoadDynamicObjectData(std::map<int,DynamicObjectData*> &mapd);
	bool LoadItemData(std::map<int,ItemData*> &mapi);
	bool LoadNpcData(std::map<int,NpcData*> &mapn);
	bool LoadPetData(std::map<int,PetData*> &mapp);
	bool LoadSpellData(std::map<int,SpellData*> &maps);
	~LoadData() = default;
private:
	mysqlpp::Connection conn;
	ObjectPool<MapData> m_map_data_pool;
	ObjectPool<DynamicObjectData> m_dynamic_object_data_pool;
	ObjectPool<ItemData> m_item_data_pool;
	ObjectPool<NpcData> m_npc_data_pool;
	ObjectPool<PetData> m_pet_data_pool;
	ObjectPool<SpellData> m_spell_data_pool;
};

