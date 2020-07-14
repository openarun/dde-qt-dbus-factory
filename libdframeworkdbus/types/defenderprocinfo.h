/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     luokai <luokai_cm@deepin.com>
 *
 * Maintainer: luokai <luokai_cm@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEFENDERPROCINFO_H
#define DEFENDERPROCINFO_H

#include <QtCore/QString>
#include <QtDBus/QtDBus>
#include <QDBusMetaType>
#include <QtCore/QList>

struct DefenderProcInfo {
    int nPid;
    QString sExecPath; // 执行路径
    bool isbSysApp; // 是否是系统应用
    QString sProcName;
    // 启动器应用信息
    QString sDesktopPath;
    QString sPkgName;
    QString sAppName;
    QString sThemeIcon;
    QString sID;
    qint64 nCategoryID;
    qint64 nTimeInstalled;
    // 流量信息
    double dDownloadSpeed;
    double dUploadSpeed;
    double dDownloads; //下载量
    double dUploads;
    bool operator!=(const DefenderProcInfo &procInfo);
};

Q_DECLARE_METATYPE(DefenderProcInfo);

QDBusArgument &operator<<(QDBusArgument &argument, const DefenderProcInfo &procInfo);
const QDBusArgument &operator>>(const QDBusArgument &argument, DefenderProcInfo &procInfo);

void registerDefenderProcInfoMetaType();
#endif
