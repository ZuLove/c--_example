#include "DataDef.hpp"
#include "LoadData.hpp"
#include <iostream>
#include <mysql++.h>
#include <string.h>

using namespace std;

bool LoadData::Conn(const char* db, const char* ip, const char* user, const char* password, unsigned int port)
{
	if (conn.connect(db, ip, user, password, port))
	{
		return true;
	}
	return false;
}

bool LoadData::LoadMapData(map<int, MapData*> &mapm)
{
		mysqlpp::Query query = conn.query("select * from map_data");
		if (mysqlpp::StoreQueryResult res = query.store())
		{
			for (auto &row : res)
			{
				MapData *map_data = m_map_data_pool.Construct();
				if (map_data)
				{
					map_data->id = row["map_id"];
					map_data->name = row["map_name"];
					map_data->eject_map_id = row["eject_map_id"];
					map_data->eject_x = row["eject_x"];
					map_data->eject_y = row["eject_y"];
					mapm.insert(make_pair(row["map_id"], map_data));
				} 
				else{
				}
			}
		}
		else{
			return false;
		}

	return true;
}

bool LoadData::LoadDynamicObjectData(map<int, DynamicObjectData*> &mapd)
{
	mysqlpp::Query query = conn.query("select * from dynamic_object_data");
	if (mysqlpp::StoreQueryResult res = query.store())
	{
		
		
		for (auto &row : res)
		{
			DynamicObjectData *dynamic_object_data = m_dynamic_object_data_pool.Construct();
			if (dynamic_object_data)
			{
				dynamic_object_data->id = row["item_id"];
				dynamic_object_data->name = row["item_name"];
				mapd.insert(make_pair(row["item_id"],dynamic_object_data));
			} 
			else{
			}
		}
	}
	else{
		return false;
	}

	return true;
}

bool LoadData::LoadItemData(map<int, ItemData*> &mapi)
{
	mysqlpp::Query query = conn.query("select * from item_data");
	if (mysqlpp::StoreQueryResult res = query.store())
	{
		for (auto &row : res)
		{
			ItemData *item_data = m_item_data_pool.Construct();
			if (item_data)
			{
				item_data->id = row["item_id"];
				item_data->name = row["item_name"];
				item_data->career_limit = row["career_limit"];
				item_data->level_limit = row["level_limit"];
				item_data->level = row["level"];
				item_data->life_data.health_regen = row["health_regen"];
				item_data->life_data.mana_regen = row["mana_regen"];
				item_data->life_data.health = 0;
				item_data->life_data.health_limit = 0;
				item_data->life_data.mana = 0;
				item_data->life_data.mana_limit = 0;
				item_data->damag_data.attack_damage_lower_limit = row["attack_damage_lower_limit"];
				item_data->damag_data.attack_damage_upper_limit = row["attack_damage_upper_limit"];
				item_data->damag_data.ability_power_lower_limit = row["ability_power_lower_limit"];
				item_data->damag_data.ability_power_upper_limit = row["ability_power_upper_limit"];
				item_data->damag_data.poison_damage_lower_limit = row["poison_damage_lower_limit"];
				item_data->damag_data.poison_damage_upper_limit = row["poison_damage_upper_limit"];
				item_data->resist_data.armor_lower_limit = row["armor_lower_limit"];
				item_data->resist_data.armor_upper_limit = row["armor_upper_limit"];
				item_data->resist_data.magic_resist_lower_limit = row["magic_resist_lower_limit"];
				item_data->resist_data.magic_resist_upper_limit = row["magic_resist_upper_limit"];
				item_data->resist_data.spell_avoid = row["spell_avoid"];
				item_data->resist_data.accuracy = row["accuracy"];
				item_data->resist_data.agility = row["agility"];
				item_data->streng_data.bag_bear = row["bear"];
				item_data->streng_data.body_bear = 0;
				item_data->streng_data.grip = row["grip"];
				item_data->lucky = row["lucky"];
				item_data->curse = row["curse"];
				item_data->durability = row["durability"];
				item_data->cool_down = row["cool_down"];
				item_data->can_repair = row["can_repair"];
				item_data->can_discard = row["can_discard"];
				item_data->consume_type = row["consume_type"];
				item_data->overlap_limit = row["overlap_limit"];
				item_data->weight = row["weight"];
				item_data->desc = row["desc"];
				mapi.insert(make_pair(row["item_id"],item_data));
			} 
			else{
			}
		}
	}
	else{
		return false;
	}

	return true;	
}

bool LoadData::LoadNpcData(map<int, NpcData*> &mapn)
{
	mysqlpp::Query query = conn.query("select * from npc_data");
	if (mysqlpp::StoreQueryResult res = query.store())
	{
		for (auto &row : res)
		{
			NpcData *npc_data = m_npc_data_pool.Construct();
			if (npc_data)
			{
				npc_data->id = row["npc_id"];
				npc_data->name = row["npc_name"];
				npc_data->level = row["level"];
				npc_data->experience = row["experience"];
				npc_data->life_data.health = row["health"];
				npc_data->life_data.mana = row["mana"];
				npc_data->life_data.health_limit = row["health_limit"];
				npc_data->life_data.mana_limit = row["mana_limit"];
				npc_data->life_data.health_regen = row["health_regen"];
				npc_data->life_data.mana_regen = row["mana_regen"];
				npc_data->damag_data.attack_damage_lower_limit = row["attack_damage_lower_limit"];
				npc_data->damag_data.attack_damage_upper_limit = row["attack_damage_upper_limit"];
				npc_data->damag_data.ability_power_lower_limit = row["ability_power_lower_limit"];
				npc_data->damag_data.ability_power_upper_limit = row["ability_power_upper_limit"];
				npc_data->damag_data.poison_damage_lower_limit = row["poison_damage_lower_limit"];
				npc_data->damag_data.poison_damage_upper_limit = row["poison_damage_upper_limit"];
				npc_data->resist_data.armor_lower_limit = row["armor_lower_limit"];
				npc_data->resist_data.armor_upper_limit = row["armor_upper_limit"];
				npc_data->resist_data.magic_resist_lower_limit = row["magic_resist_lower_limit"];
				npc_data->resist_data.magic_resist_upper_limit = row["magic_resist_upper_limit"];
				npc_data->resist_data.spell_avoid = row["spell_avoid"];
				npc_data->resist_data.accuracy = row["accuracy"];
				npc_data->resist_data.agility = row["agility"];
				npc_data->view_range = row["view_range"];
				npc_data->move_speed = row["move_speed"];
				npc_data->attack_speed = row["attack_speed"];
				mapn.insert(make_pair(row["npc_id"],npc_data));
			} 
			else{
			}
		}
	}
	else{ 
		return false; 
	}
		
	return true;
}

bool LoadData::LoadPetData(map<int, PetData*> &mapp)
{
	mysqlpp::Query query = conn.query("select * from pet_data");
	if (mysqlpp::StoreQueryResult res = query.store())
	{
		for (auto &row : res)
		{
			PetData *pet_data = m_pet_data_pool.Construct();
			if (pet_data)
			{
				pet_data->id = row["pet_id"];
				pet_data->name = row["pet_name"];
				mapp.insert(make_pair(row["pet_id"],pet_data));
			}
			else{
			}
		}
	}
	else{
		return false;
	}

	return true;
}

bool LoadData::LoadSpellData(map<int, SpellData*> &maps)
{
	mysqlpp::Query query = conn.query("select spell_id,spell_name from spell_data");
	if (mysqlpp::StoreQueryResult res = query.store())
	{
		for (auto &row : res)
		{
			SpellData *spell_data = m_spell_data_pool.Construct();
            if (spell_data)
            {
				spell_data->id = row["spell_id"];
				spell_data->name = row["spell_name"];
				maps.insert(make_pair(row["spell_id"],spell_data));
            }
			else{
			}
			
		}
	}
	else{
		return false;
	}

	return true;
}

