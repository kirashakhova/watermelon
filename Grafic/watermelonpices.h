#ifndef WATERMELONPICES_H
#define WATERMELONPICES_H

#include <QGraphicsItem>
#include <QPainter>

class WatermelonPices : public QGraphicsItem {
public:
    WatermelonPices() {
        // Конструктор, если потребуется
        setFlag(QGraphicsItem::ItemIsMovable);
    }

    QRectF boundingRect() const override {
        return QRectF(0, 0, 100, 100); // Задаем границы объекта
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        //painter->setRenderHint(QPainter::Antialiasing);

        // Рисуем корку арбуза (внешняя часть дольки)
        painter->setBrush(QBrush(Qt::green)); // Кисть для корки
        painter->drawPie(0, 0, 50, 50, 0 * 16, 90 * 16); // Сектор (90 градусов), уменьшенный размер

        // Рисуем мякоть арбуза (внутренняя часть дольки)
        painter->setBrush(QBrush(Qt::red)); // Кисть для мякоти
        painter->drawPie(5, 5, 40, 40, 0 * 16, 90 * 16); // Сектор мякоти (меньше по размеру)

        // Рисуем семена
        painter->setBrush(QBrush(Qt::black)); // Кисть для семян
        //painter->drawEllipse(10, 15, 3, 3); // Семена
        painter->drawEllipse(30, 15, 3, 3); // Семена
        //painter->drawEllipse(20, 25, 3, 3); // Семена
    }

protected:
    // Переопределите методы для обработки событий, если нужно
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // WATERMELONPICES_H
