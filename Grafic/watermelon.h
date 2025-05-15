#ifndef WATERMELON_H
#define WATERMELON_H

#include <QGraphicsItem>
#include <QPainter>

class Watermelon : public QGraphicsItem {
public:
    Watermelon() {
        // Конструктор, если потребуется
        this->setFlag(QGraphicsItem::ItemIsMovable);
    }

    QRectF boundingRect() const override {
        return QRectF(0, 0, 100, 100); // Задаем границы объекта
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        painter->setBrush(QBrush(Qt::green)); // Задаем кисть для заливки
        painter->drawEllipse(0, 0, 50, 50); // Рисуем круг (целый арбуз)

        painter->setPen(QPen(Qt::darkGreen, 2)); // Задаем цвет и толщину линии для полос
        painter->drawLine(10, 10, 10, 42); // Первая вертикальная полоса
            painter->drawLine(20, 0, 20, 47); // Вторая вертикальная полоса
            painter->drawLine(30, 0, 30, 47); // Третья вертикальная полоса
            painter->drawLine(40, 10, 40, 42); //
    }

protected:
    // Переопределите методы для обработки событий, если нужно
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // WATERMELON_H
