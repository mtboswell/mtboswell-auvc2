#include "tmf.h"

TMF parseTMF(QByteArray treeData){
	QDataStream in(treeData);
	TMF tree;
	//! \todo implement actual hierarachy
	tree.parentID="";

	// Read and check the header
	quint32 magic;
	in >> magic;
	if (magic != 0x01212220)
		return TMF();

	// Read the version
	qint32 version;
	in >> version;
	if (version != 200)
		return TMF();
	in.setVersion(QDataStream::Qt_4_0);

	TIF thisItem;
	while(!in.atEnd()){
		in >> thisItem.ID;
		in >> thisItem.value;
		in >> thisItem.timestamp;
		in >> thisItem.available;
		in >> thisItem.meta;
		tree.treeItems << thisItem;
	}
	return tree;
}

QByteArray serializeTIF(TIF treeItem){
	QByteArray outArray;
	QDataStream out(&outArray,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);

	out << treeItem.ID;
	out << treeItem.value;
	out << treeItem.timestamp;
	out << treeItem.available;
	out << treeItem.meta;

	return outArray;
}

QByteArray serializeTMF(TMF tree){
	QByteArray outArray;
	QDataStream out(&outArray,QIODevice::WriteOnly);

	// Write a header with a "magic number" and a version
	// A = 1, U = 21, V = 22, T = 20
	out << (quint32)0x01212220;
	out << (qint32)200;

	out.setVersion(QDataStream::Qt_4_0);

	// Write the data
	//! \todo implement actual hierarchy
	foreach(TIF item, tree.treeItems){
		item.ID.prepend(tree.parentID+".");
		out << serializeTIF(item);
	}
	return outArray;
}
