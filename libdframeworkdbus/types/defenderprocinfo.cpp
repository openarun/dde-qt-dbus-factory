#include "defenderprocinfo.h"

bool DefenderProcInfo::operator!=(const DefenderProcInfo &procInfo)
{
    return !(this->pid == procInfo.pid);
}

QDBusArgument &operator<<(QDBusArgument &argument, const DefenderProcInfo &procInfo)
{
    argument.beginStructure();
    argument << procInfo.pid << procInfo.execPath << procInfo.isbSysApp << procInfo.procName
             << procInfo.pkgName << procInfo.appName << procInfo.themeIcon
             << procInfo.downloadSpeed << procInfo.uploadSpeed << procInfo.downloads << procInfo.uploads;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, DefenderProcInfo &procInfo)
{
    argument.beginStructure();
    argument >> procInfo.pid >> procInfo.execPath >> procInfo.isbSysApp >> procInfo.procName
             >> procInfo.pkgName >> procInfo.appName >> procInfo.themeIcon
             >> procInfo.downloadSpeed >> procInfo.uploadSpeed >> procInfo.downloads >> procInfo.uploads;
    argument.endStructure();
    return argument;
}

void registerDefenderProcInfoMetaType()
{
    qRegisterMetaType<DefenderProcInfo>("DefenderProcInfo");
    qDBusRegisterMetaType<DefenderProcInfo>();
}
