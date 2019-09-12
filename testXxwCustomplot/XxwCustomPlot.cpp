#include "XxwCustomPlot.h"

XxwCustomPlot::XxwCustomPlot(QWidget *parent)
    :QCustomPlot(parent)
    ,m_isShowTracer(false)
    ,m_xTracer(Q_NULLPTR)
    ,m_yTracer(Q_NULLPTR)
    ,m_dataTracers(QList<XxwTracer *>())
    ,m_lineTracer(Q_NULLPTR)
{
}

void XxwCustomPlot::mouseMoveEvent(QMouseEvent *event)
{
    QCustomPlot::mouseMoveEvent(event);

    if(m_isShowTracer)
    {
        //当前鼠标位置（像素坐标）
        int x_pos = event->pos().x();
        int y_pos = event->pos().y();

        //像素坐标转成实际的x,y轴的坐标
        float x_val = this->xAxis->pixelToCoord(x_pos);
        float y_val = this->yAxis->pixelToCoord(y_pos);



        if(Q_NULLPTR == m_xTracer)
            m_xTracer = new XxwTracer(this, XxwTracer::DataTracer);//x轴
        m_xTracer->updatePosition(x_val, y_val);

        if(Q_NULLPTR == m_lineTracer)
            m_lineTracer = new XxwTraceLine(this,XxwTraceLine::Both);//直线
        m_lineTracer->updatePosition(x_val, y_val);

        this->replot();//曲线重绘
    }
}
