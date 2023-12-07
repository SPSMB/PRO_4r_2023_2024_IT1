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
    // nahodna barva
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;

    painter->setBrush(QBrush(QColor(r,g,b,255)));
    // vykresli objekt
    painter->drawPolygon(letadlo_obrys);
}

QPainterPath Letadlo::shape() const
{
    QPainterPath kolizni_obrys;

    kolizni_obrys.addPolygon(letadlo_obrys);
    return kolizni_obrys;
}
