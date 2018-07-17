#ifndef COLLISIONTREE_H
#define COLLISIONTREE_H
#include "../node2d.h"
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
class CollisionTree
{
public:
    CollisionTree();
    virtual ~CollisionTree();
    void insertStaticChild(Node2D*);
    void testCollision(Node2D*);
    void clearChilds();
protected:
    std::vector<Node2D*> m_vStaticNodes;
    std::vector<Node2D*> m_vDinamicNodes;
};

#endif // COLLISIONTREE_H
