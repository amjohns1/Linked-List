//------------------------------
// File: Character.cpp
// Purpose: Using header file to create functions 
// Author: Adam Johnson
//------------------------------
#include "Character.h"
#include "Item.h"
#include <cstring>
#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

Character::Character()
{
	strcpy(m_sName, "");
	m_iAlignment = 0;
	m_iHitPoints = 0;
	m_iCharTraits[0] = 0;
	m_iCharTraits[1] = 0;
	m_iCharTraits[2] = 0;
	m_iCharTraits[3] = 0;
	m_iCharTraits[4] = 0;
	m_iCharTraits[5] = 0;
	for (int i = 0; i < 10; i++)
	{
		strcpy(m_Items[i].m_sItemName, "---");
	}

	m_pNext = nullptr;
}

Character::Character(char* name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr)
{

	strcpy(m_sName, name);
	m_iClass = cl;
	m_iAlignment = al;
	m_iHitPoints = hp;
	m_iCharTraits[0] = str;
	m_iCharTraits[1] = dex;
	m_iCharTraits[2] = con;
	m_iCharTraits[3] = itl;
	m_iCharTraits[4] = wis;
	m_iCharTraits[5] = chr;
	for (int i = 0; i < 10; i++)
	{
		strcpy(m_Items[i].m_sItemName, "---");
	}
	m_pNext = nullptr;
}

Character::~Character()
{
	delete m_pNext;
}


char* Character::getName()
{
	return m_sName;
}

void Character::setName(char* name)
{
	strcpy(m_sName, name);
}

int Character::getClass()
{
	return m_iClass;
}

void Character::setClass(int cl)
{
	m_iClass = cl;
}

int Character::getAlignment()
{
	return m_iAlignment;
}

void Character::setAlignment(int al)
{
	m_iAlignment = al;
}

int Character::getHitPoints()
{
	return m_iHitPoints;
}

void Character::setHitPoints(int hp)
{
	m_iHitPoints = hp;
}

int Character::getStrength()
{
	return m_iCharTraits[0];
}

void Character::setStrength(int str)
{
	m_iCharTraits[0] = str;
}

int Character::getDexterity()
{
	return m_iCharTraits[1];
}

void Character::setDexterity(int dex)
{
	m_iCharTraits[1] = dex;
}

int Character::getConstitution()
{
	return m_iCharTraits[2];
}

void Character::setConstitution(int cn)
{
	m_iCharTraits[2] = cn;
}

int Character::getIntelligence()
{
	return m_iCharTraits[3];
}

void Character::setIntelligence(int itl)
{
	m_iCharTraits[3] = itl;
}

int Character::getWisdom()
{
	return m_iCharTraits[4];
}

void Character::setWisdom(int wis)
{
	m_iCharTraits[4] = wis;
}

int Character::getCharisma()
{
	return m_iCharTraits[5];
}

void Character::setCharisma(int chr)
{
	m_iCharTraits[5] = chr;
}
//-----------------------------------------------
// Add an item to the list of items
//-----------------------------------------------
bool Character::addItem(Item* item)
{
	// See if there is an empty place to hold this item
	for (int i = 0; i < 10; i++)
	{
		if (strcmp(m_Items[i].m_sItemName, "---") == 0)
		{
			// Found an empty slot so copy this item here
			m_Items[i] = *item;
			return true;
		}
	}
	// If we get here then the Items array is full and we
	//  can't add this item so return false to flag failure.
	return false;
}

//-----------------------------------------------
// Get a pointer to an item in the list
//-----------------------------------------------
Item* Character::getItem(char* itemName)
{
	for (int i = 0; i < 10; i++)
	{
		if (strcmp(m_Items[i].m_sItemName, itemName) == 0)
			return &m_Items[i];
	}
	return NULL; // Didn't find
}

//-----------------------------------------------
// Delete an item from the list of items.  Return
// pointer to item if the item was found or NULL
// if it was not found in the list.
//-----------------------------------------------
Item* Character::dropItem(char* itemName)
{
	// Search all items
	for (int i = 0; i < 10; i++)
	{
		// If this it the correct item name
		if (strcmp(m_Items[i].m_sItemName, itemName) == 0)
		{
			Item* newItem = new Item();
			*newItem = m_Items[i];
			// Set the name of the item to the "Empty" string
			strcpy(m_Items[i].m_sItemName, "---");
			return newItem;
		}
	}
	return NULL;
}

void Character::printAll()
{
	cout << "Player Name: " << m_sName << endl;
	cout << "Player Class: " << m_iClass << endl;
	cout << "Player Alignment: " << m_iAlignment << endl;
	cout << "Player Hit Points: " << m_iHitPoints << endl;
	cout << "Player Strength: " << m_iCharTraits[0] << endl;
	cout << "Player Dexterity: " << m_iCharTraits[1] << endl;
	cout << "Player Constitution: " << m_iCharTraits[2] << endl;
	cout << "Player Intelligence: " << m_iCharTraits[3] << endl;
	cout << "Player Wisdom: " << m_iCharTraits[4] << endl;
	cout << "Player Charisma: " << m_iCharTraits[5] << endl;
	for (int i = 0; i < 10; i++)
	{
		if (strcmp(m_Items[i].m_sItemName, "---") != 0)
		{
			cout << "Player Item name: " << m_Items[i].m_sItemName << endl;
			cout << "Player Item weight: " << m_Items[i].m_dWeight << endl;
			cout << "Player Item value: " << m_Items[i].m_dValue << endl;
		}
	}
}
