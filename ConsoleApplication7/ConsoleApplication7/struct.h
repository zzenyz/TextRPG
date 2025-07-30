#pragma once

#define MAX_INVENTORY 10
#define MAX_SHOP_ITEMS 10
#define MAX_EQUIPMENT 20
#define MAX_SKILL 2

// 직업 열거형
typedef enum {
    무당 = 1,
    풍수지리사,
    신학생,
} JobType;

// 아이템 구조체 (인벤토리, 상점 아이템에 공통으로 사용)
typedef struct {
    char name[20];
    int quantity;  // 인벤토리에선 수량, 상점에선 1로 사용
} Item;

// 플레이어 인벤토리 구조체
typedef struct {
    Item items[MAX_INVENTORY];
    int count;      // 현재 아이템 종류 개수
    int maxSlots;   // 슬롯 최대 개수 (레벨업 등으로 변경 가능)
} Inventory;

//장비 구조체

typedef enum {
    WEAPON,
    ARMOR,
    ACCESSORY
} EquipmentType;

typedef struct {
    char* name;
    char* desc;
    int price;
    int sellprice;
    EquipmentType type;  // ✅ 부위 정보 명시!
} Equipment;

Equipment equipmentList[MAX_EQUIPMENT];//장비 배열 선언

typedef struct {
    Equipment* weapon;
    Equipment* armor;
    Equipment* accessory;
} EquippedItems;

// 스킬 구조체

typedef struct {
    char name[50];
    char desc[100];  // 설명
} Skill;

// 플레이어 구조체
typedef struct 
{
    int level;
    int exp;
    int expToNextLevel;

    int hp;
    int maxHp;
    int atk;

    JobType job; 
    char jobName[20];

    int playerStunTurn;
    int ghostAttackDebuffTurn;
    int buffAttackTurn;
    int ghostDotTurn;

    int gold;

    Inventory inventory;  // 인벤토리 포함
    EquippedItems equippedItems;

    Skill skillSet[MAX_SKILL];
} Player;

// 귀신 구조체
typedef struct 
{
    int hp;
    int maxHp;
    int atk;
} Ghost;

// 상점 아이템 구조체
typedef struct 
{
    const char* name;
    int price;
    int sellprice;
    const char* desc;
} ShopItem;

// 상점 구조체
typedef struct 
{
    ShopItem items[MAX_SHOP_ITEMS];
    int numItems;
} Shop;
