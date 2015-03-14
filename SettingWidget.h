#ifndef SETTING_WIDGET
#define SETTING_WIDGET

#include "ImageButton.h"
#include "ProfileWidget.h"
#include "SafetyWidget.h"
#include "SystemWidget.h"
#include "HelpWidget.h"
#include "LanguageWidget.h"

#include <QCheckBox>
#include <QComboBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWidget (QWidget *parent = 0);

signals:
    bool dismissAction ();
    bool closeAction ();
    bool minimizeAction ();
    bool languageChange (QString language);

public slots:
    bool onRetranslate();

protected:
    virtual void showEvent (QShowEvent* event);
private:
    ImageButton * minimizeButton;
    ImageButton * closeButton;

    QLabel * titleText;
    QTabWidget * tabs;

    ProfileWidget * profile;
    SafetyWidget * safety;
    SystemWidget * system;
    HelpWidget * help;
    LanguageWidget * language;

    QVBoxLayout * layout;

    bool connected;
};

#endif // SETTING_WIDGET
