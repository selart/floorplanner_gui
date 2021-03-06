#ifndef GRAPHICSAREA_H
#define GRAPHICSAREA_H

#include "Floorplans.h"

#include <QWidget>
#include <QPixmap>

#include <set>

class GraphicsArea
    : public QWidget
{
public:

    typedef Qt::GlobalColor ColorType;
    static const ColorType* colors;

    GraphicsArea(QWidget* parent = 0);
    ~GraphicsArea();

    Point recalculatePoint(const QPoint& point) const;

    void reset();
    void draw();
    void setFloorplan(BaseFloorplan* floorplan);
    void setSelectedItems(std::set<Module*> modules);
    void setTargetPoint(const Point& point);

protected:
    virtual void paintEvent(QPaintEvent* e);
    virtual void resizeEvent(QResizeEvent *);

private:
    void drawFloorplan(BaseFloorplan* root);
    void _drawFloorplan(BaseFloorplan* root, unsigned short colorIdx);

    void drawTarget();
    void calculateScaleAndPosition();

private:
    QPixmap m_pixmap;
    Point* m_target;
    BaseFloorplan* m_floorplan;
    std::set<Module*> m_selectedModules;
    double m_scale;
    double m_xShift;
    double m_yShift;

};

#endif // GRAPHICSAREA_H
