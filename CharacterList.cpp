//--------------------------------
// File CharacterList.cpp
// Purpose: Using header files to create functions
// Author: Adam Johnson
//--------------------------------

#include "CharacterList.h"
#include "Character.h"
#include "Item.h"
#include <cstring>
#include <iostream>

using namespace std;

CharacterList::CharacterList()
{
	m_pHead = nullptr;
}

CharacterList::~CharacterList()
{
	Character* temp = m_pHead;
	Character* tempNext;

	while (temp != nullptr)
	{
		tempNext = temp->m_pNext;
		delete temp;
		temp = tempNext;
	}
}

bool CharacterList::addCharacter(Character* newCharacter)
{
	Character* temp = m_pHead;
	Character* end = nullptr;
	while ((temp != nullptr) && strcmp(temp->getName(), newCharacter->getName()) < 0)
	{
		end = temp;
		temp = temp->m_pNext;
	}
	if (end == nullptr)
	{
		newCharacter->m_pNext = temp;
		m_pHead = newCharacter;
	}
	else
	{
		newCharacter->m_pNext = temp;
		end->m_pNext = newCharacter;
	}

}

Character* CharacterList::deleteCharacter(char* characterName)
{
	Character* end = nullptr;
	Character* temp = m_pHead;

	if (temp == nullptr)
	{
		return nullptr;
	}

	while (temp != nullptr && strcmp(temp->getName(), characterName) != 0)
	{
		end = temp;
		temp = temp->m_pNext;
	}
	if (temp == nullptr)
	{
		return nullptr;
	}
	else if (end == nullptr)
	{
		m_pHead = m_pHead->m_pNext;
		temp->m_pNext = nullptr;
		return temp;
	}
	else
	{
		end->m_pNext = temp->m_pNext;
		temp->m_pNext = nullptr;
		return temp;

	}
	

}

bool CharacterList::addItem(char* characterName, Item* newItem)
{
	Character* temp = m_pHead;
	while (temp != nullptr && strcmp(characterName, temp->getName()) != 0)
	{
		temp = temp->m_pNext;
	}
	if (temp == nullptr)
	{
		return false;
	}
	else
	{
		return (temp->addItem(newItem));
	}
}

Item* CharacterList::getItem(char* characterName, char* itemName)
{
	Character* temp = m_pHead;
	while (temp != nullptr && strcmp(characterName, temp->getName()) != 0)
	{
		temp = temp->m_pNext;
	}
	if (temp == nullptr) 
	{
		return nullptr;
	}
	else
	{
		return temp->getItem(itemName);
	}
}

Item* CharacterList::dropItem(char* characterName, char* itemName)
{
	Character* temp = m_pHead;

	while (temp != nullptr && strcmp(characterName, temp->getName()) != 0)
	{
		temp = temp->m_pNext;
	}
	if (temp == nullptr)
	{
		return nullptr;
	}
	else
	{
		return (temp->dropItem(itemName));
	}
}

void CharacterList::printCharacters()
{
	Character* temp = m_pHead;

	while (temp != nullptr)
	{
		temp->printAll();
		temp = temp->m_pNext;
	}
}
