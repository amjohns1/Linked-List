//--------------------------------
// File CharacterList.h
// Purpose: Defining a class that encaptulate the properties of character
// Author: Adam Johnson
//--------------------------------

#pragma once
#include <cstring>
#include "Character.h"
class CharacterList
{
private:
	Character* m_pHead;
public:
	CharacterList();
	~CharacterList();
	bool addCharacter(Character* newCharacter);
	Character* deleteCharacter(char* characterName);
	bool addItem(char* characterName, Item* newItem);
	Item* getItem(char* characterName, char* itemName);
	Item* dropItem(char* characterName, char* itemName);
	void printCharacters();
};

