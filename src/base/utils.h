/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
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

#ifndef UTILS_H
#define UTILS_H

#include "sys/time.h"
#include "dbus/dbusvariant/app_info.h"

#include <DApplicationHelper>
#include <DSysInfo>
#include <QWidget>

#define dApp (static_cast<DApplication *>(QCoreApplication::instance()))

DWIDGET_USE_NAMESPACE

class Utils : public QObject
{
    Q_OBJECT

public:
    explicit Utils(QObject *parent = nullptr);
    ~Utils();

    enum FontType { SourceHanSansMedium,
                    SourceHanSansNormal,
                    DefautFont
                  };

    static QHash<QString, QPixmap> m_imgCacheHash;
    static QHash<QString, QString> m_fontNameCache;
    static QString cpuModeName;
    static QPixmap renderSVG(const QString &filePath, const QSize &size);
    static QString translateTitle(const QString &titleUS);
    //获取所有应用列表
    static QList<AppInfo> launcherInterface();
    //获取系统应用中有帮助手册的应用列表
    static QStringList getSystemManualList();
    static QString getSystemManualDir();
    static QList<AppInfo> sortAppList(QMultiMap<qlonglong, AppInfo> map);
    static bool hasSelperSupport();
    static QStringList systemToOmit(Dtk::Core::DSysInfo::UosEdition);
    static bool activeWindow(quintptr winId);
    static QString regexp_label(const QString &strtext, const QString &strpatter);
    //创建多级目录
    static QString mkMutiDir(const QString &path);
    //判断是否为龙芯平台
    static bool judgeLoongson();
    //判断是否Wayland
    static bool judgeWayLand();

};

class ExApplicationHelper : public DGuiApplicationHelper
{
    Q_OBJECT

public:
    static ExApplicationHelper *instance();

    DPalette standardPalette(DGuiApplicationHelper::ColorType type) const;
    DPalette palette(const QWidget *widget, const QPalette &base = QPalette()) const;
    void setPalette(QWidget *widget, const DPalette &palette);

private:
    ExApplicationHelper();
    ~ExApplicationHelper() override;

    bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif
