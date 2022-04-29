
//--------------------------------
// File Character.h
// Purpose: Defining a class that encaptulate the properties of character
// Author: Adam Johnson
//--------------------------------
#pragma once
#include "Item.h"
#include <iostream>

class Character
{
public:
	Character();
	Character(char* name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr);
	~Character();
	char *getName();
	void setName(char* name);
	int getClass();
	void setClass(int cl);
	int getAlignment();
	void setAlignment(int al);
	int getHitPoints();
	void setHitPoints(int hp);
	int getStrength();
	void setStrength(int str);
	int getDexterity();
	void setDexterity(int dex);
	int getConstitution();
	void setConstitution(int cn);
	int getIntelligence();
	void setIntelligence(int itl);
	int getWisdom();
	void setWisdom(int wis);
	int getCharisma();
	void setCharisma(int chr);
	void printAll();
	bool addItem(Item* item);
	Item* getItem(char* itemName);
	Item* dropItem(char* itemName);
	Character* m_pNext;

private:
	char m_sName[64] = "";
	int m_iClass, m_iAlignment, m_iHitPoints;
	int m_iCharTraits[6];
	Item m_Items[10];
};


