#include "mydesignplugin.h"
#include "mydesignpluginplugin.h"

#include <QtPlugin>

MyDesignPluginPlugin::MyDesignPluginPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void MyDesignPluginPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool MyDesignPluginPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *MyDesignPluginPlugin::createWidget(QWidget *parent)
{
    return new MyDesignPlugin(parent);
}

QString MyDesignPluginPlugin::name() const
{
    return QLatin1String("MyDesignPlugin");
}

QString MyDesignPluginPlugin::group() const
{
    return QLatin1String("");
}

QIcon MyDesignPluginPlugin::icon() const
{
    return QIcon(QLatin1String(":/funny.png"));
}

QString MyDesignPluginPlugin::toolTip() const
{
    return QLatin1String("");
}

QString MyDesignPluginPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool MyDesignPluginPlugin::isContainer() const
{
    return false;
}

QString MyDesignPluginPlugin::domXml() const
{
    return QLatin1String("<widget class=\"MyDesignPlugin\" name=\"myDesignPlugin\">\n</widget>\n");
}

QString MyDesignPluginPlugin::includeFile() const
{
    return QLatin1String("mydesignplugin.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(mydesignpluginplugin, MyDesignPluginPlugin)
#endif // QT_VERSION < 0x050000
