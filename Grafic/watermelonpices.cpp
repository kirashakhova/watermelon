#include "watermelonpices.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

void WatermelonPices::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::RightButton && scene()) { // Проверяем, что сцена существует
        scene()->removeItem(this); // Удаляем объект со сцены
        delete this;
    } else {
        QGraphicsItem::mousePressEvent(event); // Обрабатываем другие события
    }
}
