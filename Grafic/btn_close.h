#ifndef BTN_CLOSE_H
#define BTN_CLOSE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMessageBox>

class Btn_close : public QGraphicsItem {
public:
    explicit Btn_close(QMainWindow *parentWindow) : parentWindow(parentWindow) {
            // Конструктор, где передается указатель на главное окно
        setFlag(QGraphicsItem::ItemIsMovable);
        }

    QRectF boundingRect() const override {
        return QRectF(0, 0, 70, 50); // Задаем границы объекта
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        // Рисуем кнопку
        painter->setBrush(QBrush(Qt::gray)); // Задаем кисть для заливки
        painter->drawRect(boundingRect());

        // Рисуем текст
        painter->setPen(Qt::black); // Задаем цвет текста
        painter->drawText(boundingRect(), Qt::AlignCenter, "Выход"); // Рисуем текст "Выход"
    }

protected:
    // Обработка событий мыши
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
        if(event->button() == Qt::RightButton){
        if (scene()->items().count() == 256) {
            parentWindow->close();
            event->accept(); // Закрыть приложение
            }
        else {
               QMessageBox::warning(parentWindow, "Предупреждение", "Отсюда не сбежать!");
                event->ignore(); // Отмена закрытия
            }
        }
    }

private:
    QMainWindow* parentWindow;
};

#endif // BTN_CLOSE_H
