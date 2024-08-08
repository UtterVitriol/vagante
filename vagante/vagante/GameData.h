#pragma once

typedef struct Vec2
{
	float x;
	float y;
} Vec2;

class Character
{
public:
	char pad_0004[168]; //0x0004
	float xPos; //0x00AC
	float yPos; //0x00B0
	float xVel; //0x00B4
	float yVel; //0x00B8
	char pad_00BC[80]; //0x00BC
	float hp; //0x010C
	float maxHp; //0x0110
	char pad_0114[16]; //0x0114
	bool heavy; //0x0124
	char pad_0125[25]; //0x0125
	bool immortal; //0x013E
	bool palpable; //0x013F
	bool physical; //0x0140
	bool doesCollideLevel; //0x0141
	char pad_0142[515]; //0x0142
	bool playerActive; //0x0345
	char pad_0346[1186]; //0x0346
	bool N0000067E; //0x07E8
	bool N00000A2C; //0x07E9
	char pad_07EA[18]; //0x07EA
	int affinityPoints; //0x07FC
	char pad_0800[160]; //0x0800
	unsigned int currSkill; //0x08A0
	bool cheatNoClip; //0x08A4
	bool debugInvisible; //0x08A5
	char pad_08A6[2]; //0x08A6
	float debugNoclipSpeed; //0x08A8
	Vec2 noClipVel; //0x08AC
	char pad_08B4[16]; //0x08B4
	int discount; //0x08C4
	int experienceLevel; //0x08C8
	int storedExperienceLevels; //0x08CC
	char pad_08D0[4]; //0x08D0
	int goldCount; //0x08D4
	bool asceticVow; //0x08D8
	char pad_08D9[3]; //0x08D9
	int hardHead; //0x08DC
	int knockBackModifier; //0x08E0
	int cursedFairyFireAttack; //0x08E4
	int fairyFireAttack; //0x08E8
	int slowAttack; //0x08EC
	float evasionPercent; //0x08F0
	float criticalPercent; //0x08F4
	float maxAir; //0x08F8
	float air; //0x08FC
	float airIndicatorAlpha; //0x0900
	char pad_0904[4]; //0x0904
	int punchPower; //0x0908
	float meleeDamage; //0x090C
	float rangeDamage; //0x0910
	float damageFromItems; //0x0914
	int criticalChanceFromItems; //0x0918
	float cursedJumpDamage; //0x091C
	float jumpDamage; //0x0920
	bool superJump; //0x0924
	bool didSuperJump; //0x0925
	char pad_0926[2]; //0x0926
	int haveWalkChargeDamage; //0x0928
	bool rageVictory; //0x092C
	char pad_092D[7]; //0x092D
	int lightRadius; //0x0934
	bool farsighted; //0x0938
	char pad_0939[3]; //0x0939
	float bonusAttackSpeed; //0x093C
	float increasedAttackSpeed; //0x0940
	float jumpSpeed; //0x0944
	int numExtraJumps; //0x0948
	int numJumps; //0x094C
	int cursedDoubleJump; //0x0950
	int fireWalk; //0x0954
	int cursedFireWalk; //0x0958
	int fireWalkCooldown; //0x095C
	int bouncyShoes; //0x0960
	int cursedBouncyShoes; //0x0964
	int superSpeed; //0x0968
	int cursedSuperSpeed; //0x096C
	bool onWall; //0x0970
	char pad_0971[399]; //0x0971
	float blockHp; //0x0B00
	int armor; //0x0B04
	char pad_0B08[2720]; //0x0B08

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
}; //Size: 0x15A8
static_assert(sizeof(Character) == 0x15A8);