#ifndef INDEXMANAGER_H
#define INDEXMANAGER_H

#include <panel.h>

class IndexManager
{
public:
    static uint GiveFirstIndexAvailble(QList<Panel*> &lista);

private:
    IndexManager();
    static bool is_occupied(uint index, QList<Panel*> &lista);
};

#endif // INDEXMANAGER_H
