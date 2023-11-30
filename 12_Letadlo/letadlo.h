#ifndef LETADLO_H
#define LETADLO_H

#include <QGraphicsItem>
#include <QPainter>

class Letadlo : public QGraphicsItem
{
public:
    Letadlo();
    int height();

    // QGraphicsItem interface
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPolygon letadlo_obrys;

    QPainterPath shape() const;
};

#endif // LETADLO_H
