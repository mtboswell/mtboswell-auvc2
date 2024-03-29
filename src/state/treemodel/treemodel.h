/**
 * AUVC State Data storage structure.
 * Some code borrowed from the Qt documentation. Copyright below applies only to copied code.
 */
/****************************************************************************
 **
 ** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 ** All rights reserved.
 ** Contact: Nokia Corporation (qt-info@nokia.com)
 **
 ** This file is part of the examples of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:BSD$
 ** You may use this file under the terms of the BSD license as follows:
 **
 ** "Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are
 ** met:
 **   * Redistributions of source code must retain the above copyright
 **     notice, this list of conditions and the following disclaimer.
 **   * Redistributions in binary form must reproduce the above copyright
 **     notice, this list of conditions and the following disclaimer in
 **     the documentation and/or other materials provided with the
 **     distribution.
 **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
 **     the names of its contributors may be used to endorse or promote
 **     products derived from this software without specific prior written
 **     permission.
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include "../vdatum.h"
#include "treeitem.h"

//class TreeItem;

class TreeModel : public QAbstractItemModel
{
	Q_OBJECT

	public:
		TreeModel(QObject *parent = 0);
		~TreeModel();

		QVariant data(const QModelIndex &index, int role) const;
		QVariant headerData(int section, Qt::Orientation orientation,
				int role = Qt::DisplayRole) const;

		QModelIndex index(int row, int column,
				const QModelIndex &parent = QModelIndex()) const;
		QModelIndex parent(const QModelIndex &index) const;

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		int columnCount(const QModelIndex &parent = QModelIndex()) const;

		Qt::ItemFlags flags(const QModelIndex &index) const;
		bool setData(const QModelIndex &index, const QVariant &value,
				int role = Qt::EditRole);
		bool setHeaderData(int section, Qt::Orientation orientation,
				const QVariant &value, int role = Qt::EditRole);

		bool insertColumns(int position, int columns,
				const QModelIndex &parent = QModelIndex());
		bool removeColumns(int position, int columns,
				const QModelIndex &parent = QModelIndex());
		bool insertRows(int position, int rows,
				const QModelIndex &parent = QModelIndex());
		bool removeRows(int position, int rows,
				const QModelIndex &parent = QModelIndex());

		QModelIndex getIndex(TreeItem* thisItem, int column);

		QVariant& operator[](const char* ID);

		bool available(QString ID);
		QVariant value(QString ID);
		QTime timestamp(QString ID);

		//! \todo implement TreeModel.serialize()
		//QByteArray serialize(QString ID){return 0;}


	public slots:
		void setData(QString name, QVariant value, QTime timestamp = QTime::currentTime(), bool available = true, QVariant meta = QVariant());
		void setData(VDatum datum);
		void sync();
		void sync(TreeItem* parent);
		void sync(QTime fromWhen, TreeItem* parent);
		void sync(QTime fromWhen);

	signals:
		void dataUpdated(QString ID, QVariant value);
		void dataUpdated(VDatum data);
		void dataEdited(VDatum data);
		void syncData(VDatum data);

	private:
		VDatum getVDatum(QString ID);

		void setupModelData(const QStringList &lines, TreeItem *parent);
		TreeItem *getItem(const QModelIndex &index) const;
		TreeItem *getItem(QString name);
		TreeItem *getItem(QString name, TreeItem* parentItem);

		TreeItem *rootItem;
};

#endif
