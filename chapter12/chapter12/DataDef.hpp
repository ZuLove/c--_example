#ifndef DATA_DEFINE_HPP
#define DATA_DEFINE_HPP

#include <cstdint>
#include <string>


enum TIME_VALUE
{
    SECOND = 1,
    MINUTE = SECOND * 60,
    HOUR = MINUTE * 60,
    DAY = HOUR * 24,
    MONTH = DAY * 30,
};


enum ACCOUNT_TYPE
{
    PLAYER,
    GAMEMASTER,
    ADMINISTRATOR,
};


struct Point
{
    uint32_t x;
    uint32_t y;

    bool operator == (const Point &other)
    {
        return other.x == x && other.y == y;
    }
};


enum DIRECTION
{
    DIR_N,
    DIR_NE,
    DIR_E,
    DIR_SE,
    DIR_S,
    DIR_SW,
    DIR_W,
    DIR_NW,
};


struct LifeData
{
    uint32_t health;                        // 生命值
    uint32_t mana;                          // 能量值

    uint32_t health_limit;                  // 生命值上限
    uint32_t mana_limit;                    // 能量值上限

    uint32_t health_regen;                  // 生命恢复值
    uint32_t mana_regen;                    // 能量恢复值
};


struct DamagData
{
    uint32_t attack_damage_lower_limit;     // 物理伤害下限
    uint32_t attack_damage_upper_limit;     // 物理伤害上限

    uint32_t ability_power_lower_limit;     // 魔法伤害下限
    uint32_t ability_power_upper_limit;     // 魔法伤害上限

    uint32_t poison_damage_lower_limit;     // 道术伤害下限
    uint32_t poison_damage_upper_limit;     // 道术伤害上限
};


struct ResistData
{
    uint32_t armor_lower_limit;             // 护甲下限
    uint32_t armor_upper_limit;             // 护甲上限

    uint32_t magic_resist_lower_limit;      // 魔抗下限
    uint32_t magic_resist_upper_limit;      // 魔抗上限

    uint32_t spell_avoid;                   // 技能躲避几率
    uint32_t accuracy;                      // 精准
    uint32_t agility;                       // 敏捷
};


struct StrengthData
{
    uint32_t body_bear;                     // 身体负重
    uint32_t bag_bear;                      // 背包负重
    uint32_t grip;                          // 握力
};


struct MapData
{
	//id ,map_id 是哪个map_name为啥为int
    uint32_t id;                            // ID编号
    std::string name;                       // 名字

    uint32_t eject_map_id;                  // 下线地图编号
    uint32_t eject_x;                       // 下线地图X坐标
    uint32_t eject_y;                       // 下线地图Y坐标
};


struct DynamicObjectData
{
	//id, item_id是哪个
    uint64_t id;                            // ID编号
    std::string name;                       // 名字
};


struct ItemData
{
	//id,item_id
    uint64_t id;                            // ID编号
    std::string name;                       // 名字

    uint32_t level_limit;                   // 等级限制
    uint32_t career_limit;                  // 职业限制

    uint32_t level;                         // 等级
	//LifeData只有前两个结构
    LifeData life_data;                     // 生命、能量
    DamagData damag_data;                   // 伤害
    ResistData resist_data;                 // 防御
    //两个负重bag_bear,body_bear
	StrengthData streng_data;               // 力量

    uint32_t lucky;                         // 幸运
    uint32_t curse;                         // 诅咒

    uint32_t durability;                    // 持久
    uint32_t cool_down;                     // 冷却时间

    bool can_repair;                        // 能否修理
    bool can_discard;                       // 能否丢弃

    uint32_t consume_type;                  // 消耗类型[立即消耗，延时消耗，不消耗]
    uint32_t overlap_limit;                 // 物品叠加上限

    uint32_t weight;                        // 重量
    std::string desc;                       // 详细描述
};


struct NpcData
{
	//npc_id ,id
    uint64_t id;                            // ID编号
    std::string name;                       // 名字

    uint32_t level;                         // 等级
    uint32_t experience;                    // 击杀后获得的经验

    LifeData life_data;                     // 生命、能量
    DamagData damag_data;                   // 伤害
    ResistData resist_data;                 // 防御

    uint32_t view_range;                    // 视野
    //以下三个数据库表格没有
    Point center;                           // 领地中心
    uint32_t move_radius;                   // 活动半径
    uint32_t guard_radius;                  // 守护半径

    uint32_t move_speed;                    // 移动速度
    uint32_t attack_speed;                  // 攻击速度
   //数据库中有个desc，详细描述
};

//没得career_data结构体

struct PetData
{
	//id,pet_id
    uint32_t id;            // ID编号
    std::string name;       // 名字
};


struct SpellData
{
	//id,spell_id
    uint32_t id;            // ID编号
    std::string name;       // 名字
};

#endif