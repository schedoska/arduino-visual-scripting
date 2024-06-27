#include "indexmanager.h"

uint IndexManager::GiveFirstIndexAvailble(QList<Panel *> &lista)
{
    for(uint index = 1; index < 1000; index++)
    {
        if(!is_occupied(index,lista)) return index;
    }
    return 0;
}

bool IndexManager::is_occupied(uint index, QList<Panel *> &lista)
{
    foreach(Panel *panel, lista)
    {
        if(panel->getIndex() == index) return true;
    }
    return false;
}

IndexManager::IndexManager()
{

}

