
/* 
0: stamina
1: maxstamina
2: spirit
3: maxspirit
4: energy
5: maxenergy
6 strength
7 magic
8 res power
9 integrity
10 resistance
11 speed
12 accuracy
13 evasion
14 crit chance
15 crit damage
16: Initiative
*/


int SkillsList[10][10] = { // Damage / healing, Exhaustion Cost, Damage type 1, Damage type 2, damage type 3, AoE?, debuff inflict, cure type (if it cures debuffs)
	{200, 10, 11, -1, -1, 0, -1, -1},
	{200, 10, 12, -1, -1, 0, -1, -1},
	{-200, 15, -1, -1, -1, 0, -1, -1}
};
char SkillNamesList[10][20] = {
	"Fireball","Lightning Bolt","Cure","","","","","","",""
};
/*
Type Ids:
-1: Null/N/A
0: Null Phys
1: Slash
2: Pierce
3: Blunt
4: Gun

10: Null Elemental
11: Fire
12: Lightning
13: Wind
14: Ice
15: Water
16: Nature
17: Earth

21: Light
22: Dark
*/
/*
int Weapons[10][10] {
	// Attack power, Magattack power, restoration power, 7 main stats 
	{30,0,0,0,0,},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{}
}
*/

