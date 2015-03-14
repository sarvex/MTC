#include "DeamonSetting.h"
#include "DeamonConnection.h"
#include "DeamonDatabase.h"
#include "DeamonPort.h"
#include "SettingWidget.h"

#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QLabel>
#include <QSettings>

SettingsWidget::SettingsWidget
(QWidget *parent)
    : QWidget(parent)
{
    this->titleText = new QLabel(tr("MTC Connect"), this);
    this->titleText->setStyleSheet ("QLabel { color: white; font: bold 15px; }");
    this->titleText->setGeometry (38, 5, 160, 22);

    this->minimizeButton = new ImageButton ("",
                                            ":/minimizeDefault.png",
                                            ":/minimizeHover.png",
                                            false, this);
    this->minimizeButton->setGeometry (418, 5, 22, 22);

    this->closeButton = new ImageButton("",
                                        ":/closeDefault.png",
                                        ":/closeHover.png",
                                        false, this);
    this->closeButton->setGeometry (446, 5, 21, 22);

    this->tabs = new QTabWidget;
    this->profile = new ProfileWidget;
    this->safety = new SafetyWidget;
    this->system = new SystemWidget;
    this->language = new LanguageWidget;
    this->help = new HelpWidget;

    this->tabs->addTab (this->profile, tr("Profile"));
    this->tabs->addTab (this->safety, tr("Security"));
    this->tabs->addTab (this->system, tr("System"));
    this->tabs->addTab (this->language, tr("Language"));
    this->tabs->addTab (this->help, tr("Help"));

    this->layout = new QVBoxLayout;
    this->layout->setContentsMargins (20, 40, 20, 20);
    this->layout->addWidget (this->tabs);

    this->setLayout (this->layout);

    this->closeButton->setToolTip (tr("Close"));
    this->minimizeButton->setToolTip (tr("Minimize"));

    QObject::connect (this->profile,
                      SIGNAL(dismissAction()),
                      this,
                      SIGNAL(dismissAction()));

    QObject::connect (this->safety,
                      SIGNAL(dismissAction()),
                      this,
                      SIGNAL(dismissAction()));

    QObject::connect (this->system,
                      SIGNAL(dismissAction()),
                      this,
                      SIGNAL(dismissAction()));

    QObject::connect (this->language,
                      SIGNAL(dismissAction()),
                      this,
                      SIGNAL(dismissAction()));

    QObject::connect (this->help,
                      SIGNAL(dismissAction()),
                      this,
                      SIGNAL(dismissAction()));

    QObject::connect (this->minimizeButton,
                      SIGNAL (clicked()),
                      this,
                      SIGNAL (minimizeAction()));

    QObject::connect (this->closeButton,
                      SIGNAL(clicked()),
                      this,
                      SIGNAL(closeAction()));

    QObject::connect (this->language,
                      SIGNAL(languageChange(QString)),
                      this,
                      SIGNAL(languageChange(QString)));
}


void
SettingsWidget::showEvent (
        QShowEvent* event)
{
     Q_UNUSED (event)

    this->tabs->setCurrentIndex (0);

}

bool
SettingsWidget::onRetranslate
()
{
    this->tabs->setTabText (0, tr("Profile"));
    this->tabs->setTabText (1, tr("Security"));
    this->tabs->setTabText (2, tr("System"));
    this->tabs->setTabText (3, tr("Language"));
    this->tabs->setTabText (4, tr("Help"));

    this->titleText->setText (tr ("MTC Connect"));

    this->closeButton->setToolTip (tr("Close"));
    this->minimizeButton->setToolTip (tr("Minimize"));

    this->profile->onRetranslate ();
    this->safety->onRetranslate ();
    this->system->onRetranslate ();
    this->language->onRetranslate ();
    this->help->onRetranslate ();

    return true;
}
