#include "letadlo.h"

Letadlo::Letadlo()
{
     letadlo_obrys << QPoint(0,0) << QPoint(300,50) << QPoint(200,100);
}

int Letadlo::height()
{
    return 100;
}

QRectF Letadlo::boundingRect() const
{
    // opsany obdelnik nasemu letadlu
    return QRectF(0,0,200,100);
}

void Letadlo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(QBrush(QColor(125,125,0,255)));
    // vykresli objekt
    painter->drawPolygon(letadlo_obrys);
}

QPainterPath Letadlo::shape() const
{
    QPainterPath kolizni_obrys;

    kolizni_obrys.addPolygon(letadlo_obrys);
    return kolizni_obrys;
}
