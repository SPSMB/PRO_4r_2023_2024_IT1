#include "letadlo.h"

Letadlo::Letadlo()
{

}

QRectF Letadlo::boundingRect() const
{
    // opsany obdelnik nasemu letadlu
    return QRectF(0,0,200,100);
}

void Letadlo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon letadlo;
    letadlo.append(QPoint(0,0));
    letadlo.append(QPoint(200,50));
    letadlo.append(QPoint(200,100));
    painter->setBrush(QBrush(QColor(125,125,0,255)));
    // vykresli objekt
    painter->drawPolygon(letadlo);
}
