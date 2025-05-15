#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "watermelon.h"
#include "watermelonpices.h"
#include "btn_close.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#include <QPointF>


bool btn=true;
QPointF genCor()
{
    // Генерируем случайные координаты
        int x = rand() % 1500;  // Диапазон по оси X
        int y = rand() % 900;   // Диапазон по оси Y

        // Преобразуем координаты в точку на сцене
        QPointF scenePos(x, y);
        return scenePos;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Создаем сцену и устанавливаем ее в представление
        QGraphicsScene *scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0, 0, 1500, 900); // Устанавливаем размер сцены

        connect(scene, &QGraphicsScene::changed, [this, scene]() {
            int objectCount = scene->items().count();
            ui->label->setText("Количество объектов: " + QString::number(objectCount));
        });

}

MainWindow::~MainWindow()
{
    QGraphicsScene *scene = ui->graphicsView->scene();
        if (scene) {
            QList<QGraphicsItem*> items = scene->items();
            for (QGraphicsItem* item : items) {
                delete item;
            }
        }
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    Watermelon *watermelon = new Watermelon();
    watermelon->setPos(genCor());
    watermelon->setFlag(QGraphicsItem::ItemIsMovable);
    ui->graphicsView->scene()->addItem(watermelon);

}


void MainWindow::on_pushButton_2_clicked()
{
    Btn_close *button = new Btn_close(this);
    button->setPos(genCor());
    button->setFlag(QGraphicsItem::ItemIsMovable);
    ui->graphicsView->scene()->addItem(button);

}

