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

#include <QtGui>

#include "mainwindow.h"
#include "treemodel.h"
#include "parametereditorcreator.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	setupUi(this);
	
	setupTreeEdit(view);

	connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	connect(view->selectionModel(),	SIGNAL(selectionChanged(const QItemSelection &,	const QItemSelection &)),this, SLOT(updateActions()));

	updateActions();
}

void MainWindow::setupTreeEdit(QTreeView* paramEdit) {

	QStringList headers;
	headers << tr("Parameter") << tr("Value");

	// load values
	QFile file("parameters.txt");
	file.open(QIODevice::ReadOnly);
	TreeModel *model = new TreeModel(headers, file.readAll());
	file.close();

	// link model to view
	paramEdit->setModel(model);

	// setup display/edit properties
	paramEdit->header()->setStretchLastSection(false);
	paramEdit->expandAll();
	for (int column = 0; column < model->columnCount(); ++column)
		paramEdit->resizeColumnToContents(column);
	paramEdit->collapseAll();

	QItemEditorFactory *factory = new QItemEditorFactory;
	QItemEditorCreatorBase *paramEditCreator = new QStandardItemEditorCreator<ParameterEditor>();
	factory->registerEditor(QVariant::Double, paramEditCreator);
	QItemEditorFactory::setDefaultFactory(factory);

	//QStyledItemDelegate* itemDel = view->itemDelegateForColumn(1);
	//itemDel->itemEditorFactory()->registerEditor(QVariant::Double, paramEditCreator);
}

void MainWindow::updateActions()
{
	bool hasSelection = !view->selectionModel()->selection().isEmpty();
	bool hasCurrent = view->selectionModel()->currentIndex().isValid();

	if (hasCurrent) {
		view->closePersistentEditor(view->selectionModel()->currentIndex());

		int row = view->selectionModel()->currentIndex().row();
		int column = view->selectionModel()->currentIndex().column();
	}
}
