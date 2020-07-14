#include "defenderprocinfo.h"

bool DefenderProcInfo::operator!=(const DefenderProcInfo &procInfo)
{
    return !(this->nPid == procInfo.nPid);
}

QDBusArgument &operator<<(QDBusArgument &argument, const DefenderProcInfo &procInfo)
{
    argument.beginStructure();
    argument << procInfo.nPid << procInfo.sExecPath << procInfo.isbSysApp << procInfo.sProcName
             << procInfo.sPkgName << procInfo.sAppName << procInfo.sThemeIcon
             << procInfo.dDownloadSpeed << procInfo.dUploadSpeed << procInfo.dDownloads << procInfo.dUploads;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, DefenderProcInfo &procInfo)
{
    argument.beginStructure();
    argument >> procInfo.nPid >> procInfo.sExecPath >> procInfo.isbSysApp >> procInfo.sProcName
             >> procInfo.sPkgName >> procInfo.sAppName >> procInfo.sThemeIcon
             >> procInfo.dDownloadSpeed >> procInfo.dUploadSpeed >> procInfo.dDownloads >> procInfo.dUploads;
    argument.endStructure();
    return argument;
}

void registerDefenderProcInfoMetaType()
{
    qRegisterMetaType<DefenderProcInfo>("DefenderProcInfo");
    qDBusRegisterMetaType<DefenderProcInfo>();
}
