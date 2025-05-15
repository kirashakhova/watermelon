#include "watermelon.h"
#include "watermelonpices.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include "mainwindow.h"

void Watermelon::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::RightButton && scene()) { // Проверяем, что сцена существует

        // Добавляем 8 долек арбуза
        for (int i = 0; i < 8; ++i) {
            WatermelonPices *slice = new WatermelonPices();
            slice->setPos(qrand() % int(scene()->width()), qrand() % int(scene()->height())); // Устанавливаем случайное положение
            slice->setFlag(QGraphicsItem::ItemIsMovable);
            scene()->addItem(slice);
                   }
        scene()->removeItem(this); // Удаляем объект со сцены
        delete this;

    } else {
        QGraphicsItem::mousePressEvent(event); // Обрабатываем другие события
    }
}
