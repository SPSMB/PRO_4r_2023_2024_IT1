#ifndef LETADLO_H
#define LETADLO_H

#include <QGraphicsItem>
#include <QPainter>

class Letadlo : public QGraphicsItem
{
public:
    Letadlo();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LETADLO_H
