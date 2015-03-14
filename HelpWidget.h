#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include "ImageButton.h"

#include <QString>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

class HelpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HelpWidget(QWidget *parent = 0);

signals:
    bool languageChange (QString language);
    bool dismissAction ();

public slots:
    bool onCancelClicked();
    bool onOkClicked();

    bool onRetranslate();

private:
    QTextEdit * content;
    QString  manual;

    ImageButton * ok;
    ImageButton * cancel;

    QVBoxLayout * buttons;
    QHBoxLayout * layout;
};

#endif // HELPWIDGET_H
