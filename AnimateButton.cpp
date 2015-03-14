#include "AnimateButton.h"

#include <QPainter>

AnimateButton::AnimateButton
(const QString& text,
 const QString& first,
 const QString& second,
 const QString& third,
 const QString& fourth,
 const QString& fifth,
 const QString& sixth,
 QWidget *parent)
    : QPushButton(parent),
      text (text),
      color (Qt::white),
      size (0),
      bold (true)
{
    this->initialize ();

    this->imageList << QImage (first);
    this->imageList << QImage (second);
    this->imageList << QImage (third);
    this->imageList << QImage (fourth);
    this->imageList << QImage (fifth);
    this->imageList << QImage (sixth);
}

AnimateButton::AnimateButton
(const QString& text,
 const QStringList& buttons,
 QWidget *parent)
    : QPushButton(parent),
      text (text),
      color (Qt::white),
      size (0),
      bold (true)
{
    this->initialize();

    this->imageList << QImage (buttons.at (0));
    this->imageList << QImage (buttons.at (1));
    this->imageList << QImage (buttons.at (2));
    this->imageList << QImage (buttons.at (3));
    this->imageList << QImage (buttons.at (4));
    this->imageList << QImage (buttons.at (5));
}

bool
AnimateButton::setImages
(const QStringList& buttons)
{
    this->timer->stop ();
    this->imageList.clear ();

    this->imageList << QImage (buttons.at (0));
    this->imageList << QImage (buttons.at (1));
    this->imageList << QImage (buttons.at (2));
    this->imageList << QImage (buttons.at (3));
    this->imageList << QImage (buttons.at (4));
    this->imageList << QImage (buttons.at (5));

    this->timer->start (100);

    return true;
}

bool AnimateButton::setColor(QColor& color)
{
    this->color = color;

    return true;
}

bool
AnimateButton::initialize ()
{
    this->startTime.start();
    this->timer = new QTimer ();

    QObject::connect (this->timer,
                      SIGNAL(timeout ()),
                      this,
                      SLOT(update ()));

    return true;
}

void
AnimateButton::paintEvent
(QPaintEvent *event)
{
    Q_UNUSED (event);

    QPainter painter (this);
    painter.drawImage (QPoint(0,0),
                       this->imageList.at(
                           (this->startTime.elapsed()/100)%6));

    if (false == this->text.isEmpty()) {

        painter.setRenderHint (QPainter::Antialiasing);
        painter.setPen (this->color);

        QFont font = painter.font ();
        font.setBold (this->bold);
        if ( 0 < this->size)
        {
            font.setPointSize (this->size);
        }

        painter.setFont (font);
        painter.drawText (QRect(0,0, this->width (), this->height ()),
                          Qt::AlignCenter,
                          this->text);
    }

    painter.end ();
}

void
AnimateButton::hideEvent
(QHideEvent * event)
{
    this->timer->stop();

    QPushButton::hideEvent (event);
}

void
AnimateButton::showEvent
(QShowEvent * event)
{
    this->timer->start(100);

    QPushButton::showEvent(event);
}

bool AnimateButton::setBold(bool bold)
{
    this->bold = bold;

    return true;
}

bool AnimateButton::setSize(int size)
{
    this->size = size;

    return true;
}

bool AnimateButton::setText (QString text)
{
    this->text = text;

    return true;
}
