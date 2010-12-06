#ifndef AUV_STATE
#define AUV_STATE

#include "treemodel/treemodel.h"

QStringList headers;
headers << "ID" << "Value";

TreeModel AUVC_State_Data(headers);

/// function for serializing the state data into a portable format for logging and networking
/// \ingroup HUB
QByteArray serializeState(AUV_State* state) {
	/// What format should be used? SID? XML? CSV?
}
#endif
