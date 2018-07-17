#include "collisiontree.h"
#include "../motor.h"
CollisionTree::CollisionTree()
{
}

CollisionTree::~CollisionTree()
{
}
void CollisionTree::insertStaticChild(Node2D* d)
{
    m_vStaticNodes.push_back(d);
}
void CollisionTree::testCollision(Node2D* d)
{
    std::vector<Node2D*> collnodes;
    int i =0;
    for(Node2D *nodo:m_vStaticNodes){
            Motor::I().PrintStr(std::to_string(i));
        if(nodo->m_rect.isColliding(d->m_rect)){
            collnodes.push_back(nodo);
        }
        i++;
    }
    if(collnodes.size()>0){
        d->onCollide(collnodes);
    }
}
void CollisionTree::clearChilds()
{
    m_vStaticNodes.clear();
}
