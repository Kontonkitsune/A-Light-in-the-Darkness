#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "DataSources.c"

int CharacterBattleStats[2][7][20] = {
	{ 
		{300,300,250,250,75,125,100,75,125,100,100,0,0,100,56},
		{500,500,100,100,150,50,75,125,75,100,80,0,0,100,43}},
	{
		{400,400,0,0,75,0,0,150,75,100,80,0,0,100,98},
		{400,400,0,0,75,0,0,150,75,100,100,20,0,100,47}}
};
char CharacterNames[2][7][20] = {
	{"Nia","Ral"},
	{"Jelly A","Jelly B"}
};
int CharacterResistances[2][7][22][2] = {
	{
		{},
		{}
	},
	{
		{{11,-2},{14,-1},{12,-1}},
		{{11,-2},{14,-1},{12,-1}}
	}
};
/*
int DisplayCharacterInfo[][][] = {
	{
		{},{}
	},
	{
		{},{}
	}
};*/

int leaderCharacter = 0;
int partysize = 2;
int enemypartysize = 2;









/*
int getArraySize(int localarr[]) {
	int localsize = sizeof localarr / sizeof localarr[0];
	return localsize;
};
*/

int calcDamage(int startteam, int startchar, int targetteam, int targetchar) {
	int damage = 0;
	if (CharacterBattleStats[targetteam][targetchar][7] == 0) {
		printf("why");
	}
	else {
	damage = (int)(100 * CharacterBattleStats[startteam][startchar][4] / CharacterBattleStats[targetteam][targetchar][7]);
	}
	return damage;
};

int dealDamage(int targetteam, int targetcharacter, int damage) {
	CharacterBattleStats[targetteam][targetcharacter][0] -= damage;
	return 0;
};

int doNormalAttack(int startteam, int startchar, int targetteam, int targetchar) {
	int localtarget = rand() % 2;
	if ( rand() % 100 < CharacterBattleStats[startteam][startchar][10] - CharacterBattleStats[targetteam][targetchar][11]) {
	int localdamage = calcDamage(startteam,startchar,targetteam,targetchar);
	printf("%s deals %d damage to %s\n", CharacterNames[startteam][startchar], localdamage, CharacterNames[targetteam][targetchar]);
	dealDamage(targetteam,targetchar,localdamage);
	}
	else {
		printf("%s missed.\n", CharacterNames[startteam][startchar]);
	};
	return 0;
};




int flag1 = 0;
int flag2 = 0;
char input[15];

int playerturn(int localcharacter) {
	int localflag1 = 0;
	while(localflag1==0) {
		printf("Spirit: %d/%d\nMana: %d/%d\n", CharacterBattleStats[0][0][0],CharacterBattleStats[0][0][1],CharacterBattleStats[0][0][2],CharacterBattleStats[0][0][3]);
		printf("choose action: \nFight\nMagic\nItem\nDefend\nRun\nExit");
		printf(">>> ");
		gets(input);
		puts(input);
		if(strcmp(input,"Fight") == 0) localflag1 = 1;
		if(strcmp(input,"Item") == 0) localflag1 = 1;
		if(strcmp(input,"Run") == 0) localflag1 = 1;
		if(strcmp(input,"Defend") == 0) localflag1 = 1;
		if(strcmp(input,"Status") == 0) localflag1 = 1;
		if(strcmp(input,"Exit") == 0) localflag1 = 1;
		if(strcmp(input,"Magic") == 0) localflag1 = 1;
	};
	
	if(strcmp(input,"Fight") == 0) {
		printf("Choose enemy:\n0-1 > ");
		gets(input);
		doNormalAttack(0,localcharacter,1,atoi(input));
	};
	if(strcmp(input,"Item") == 0) {
		printf("You have no items, stupid. you waste a turn.");
	};
	if(strcmp(input,"Run") == 0) {};
	if(strcmp(input,"Defend") == 0) {};
	if(strcmp(input,"Status") == 0) {
		
	};
	if(strcmp(input,"Exit") == 0) flag2 = 1;
	return 0;
}

int aiturn(int localteam, int localcharacter) {
	int localaction = rand() % 20;
	if(localaction < 30) {
		int localtarget = rand() % 2;
		doNormalAttack(localteam,localcharacter,1 - localteam,localtarget);
	}
	return 0;
};

int battleScript() {
	int battleTick = 0;
	int battleflag = 0;
	int tempid = 0;
	int teamid = 0;
	while (battleflag == 0) {
		battleTick += 1;
		for (int i; i < partysize + enemypartysize; i += 1) {
			if (i >= partysize) {
				tempid = i - partysize;
				teamid = 1;
			}
			else {
				teamid = 0;
			}; //battletick mod charspeed - initiative 1400 % 125 - 56 = 
			if ((battleTick % (int)(100 / CharacterBattleStats[teamid][i][9]) - CharacterBattleStats[teamid][i][14]) == 0) {
				if(teamid = 0 && leaderCharacter == i ) {
					playerturn(i);
				}
				else {
					aiturn(teamid,i);
				};
			};
			
		};
	};
	
};


int main() {
	while (flag2==0) {
		battleScript();
		/*playerturn(0);
		aiturn(0,1);
		aiturn(1,0);
		aiturn(1,1);*/
	}
	}
	

