#include "DataDef.hpp"
#include "LoadData.hpp"
#include <iostream>
#include <mysql++.h>
#include <map>
using namespace std;

int main()
{
	std::map<int, MapData*> mapm;
 	std::map<int,DynamicObjectData*> mapd;
 	std::map<int,ItemData*> mapi;
 	std::map<int,NpcData*>mapn;
 	std::map<int,PetData*> mapp;
 	std::map<int,SpellData*> maps;
	LoadData loaddata;
    std::map<int, SpellData*> mapss;
    if ()
    {
        cout << " " << endl;
    } 
    else
    {
    }
	if (loaddata.Conn("legendary", "127.0.0.1", "root", "yuli", 3306))
	{
		loaddata.LoadMapData(mapm);
		loaddata.LoadDynamicObjectData(mapd);
		loaddata.LoadItemData(mapi);
		loaddata.LoadNpcData(mapn);
		loaddata.LoadPetData(mapp);
		loaddata.LoadSpellData(maps);
	}
	else
	{
		cout << "Á¬½Ó´íÎó" << endl;
	}
	cout << "map_data tables data" << endl;
	for (auto &iter : mapm)
	{
		cout << iter.first << " " << iter.second->name << " " << iter.second->eject_map_id << " " << iter.second->eject_x << " " << iter.second->eject_y << endl;
	}

	cout << "danamic_object_data tables data" << endl;
	for (auto &ited : mapd)
	{
		cout << ited.first << " " << ited.second->name << endl;
	}

 	cout << "item_data tables data" << endl;
	for (auto &itei : mapi)
	{
		cout << itei.first << " " << itei.second->desc << " " << (itei.second->damag_data).ability_power_lower_limit << endl;
	}

 	cout << "npc_data tables data" << endl;
	for (auto &iten : mapn)
	{
		cout << iten.first << " " << iten.second->name << " " << (iten.second->damag_data).ability_power_upper_limit << endl;
	}

 	cout << "pet_data tables data" << endl;
	for (auto &itep : mapp)
	{
		cout << itep.first << " " << itep.second->name << endl;
	}

 	cout << "spell_data tables data" << endl;
	for (auto &ites : maps)
	{
		cout << ites.first << " " << ites.second->name << endl;
	}

	system("pause");
	return 0;
}