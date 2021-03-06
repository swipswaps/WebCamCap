/*
 *
 * Copyright (C) 2015  Miroslav Krajicek (https://github.com/kaajo).
 * All Rights Reserved.
 *
 * This file is part of WebCamCap.
 *
 * WebCamCap is free software: you can redistribute it and/or modify
 * it under the terms of the GNU LGPL version 3 as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * WebCamCap is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU LGPL version 3
 * along with WebCamCap. If not, see <http://www.gnu.org/licenses/lgpl-3.0.txt>.
 *
 */

#ifndef ICAMERATOPOLOGY_H
#define ICAMERATOPOLOGY_H

#include "webcamcapinterfaces_global.h"

#include "frame.h"
#include "icamera.h"

#include <QVector3D>
#include <QString>
#include <QVector>
#include <QVariantMap>
#include <QObject>

class WEBCAMCAPINTERFACESSHARED_EXPORT ICameraTopology : public QObject
{
    Q_OBJECT

protected:
    static double m_maxError;
    QVector3D m_roomDimensions;
    QVector<ICamera*> m_cameras;

public:
    explicit ICameraTopology(QVector3D roomDims, double maxError, QObject *parent = 0);
    virtual ~ICameraTopology();

    virtual void addCameras(QVector<ICamera *> cameras) = 0;
    virtual void removeCamera(ICamera *camera) = 0;

    ICamera *getCamera(QString name);

    virtual QVariantMap toVariantMap() = 0;
    virtual bool fromVariantMap(QVariantMap varMap) = 0;

    QVector3D getRoomDimensions() const;
    void setRoomDimensions(const QVector3D &roomDimensions);

    static double getMaxError();
    static void setMaxError(double maxError);

    QVector<ICamera *> getCameras() const;

signals:
    void frameReady(Frame frame);

public slots:
    virtual void setNumberOfPoints(int numberOfPoints) = 0;
    virtual void record(bool start) = 0;

};

#endif // ICAMERATOPOLOGY_H
