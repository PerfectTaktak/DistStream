//
//
//	~ TAKTAK26 - DistStreamer.inc
// 	~ Kolayca Akış uzaklığı oluşturun veya belirtin!
//	~ Geliştirici: TAKTAK26
//	~ Discord: TAKTAK26#2626
//
//


#include <a_samp>

#if defined _DISTSTREAM_INC
        #endinput
#endif
#define _DISTSTREAM_INC


#define 	D_STREAM_INPUT			(0)
#define 	D_STREAM_OUTPUT			(1)
#define 	D_STREAM_CLIENT			(2)

enum InputStream {

	iStreamDist_Input_X,
	iStreamDist_Input_Y,
	iStreamDist_Input_Z,
	iStreamDist_Input_Ang

};

new iStreamDistance[MAX_PLAYERS][InputStream];

enum OutputStream {

	bool:distTrueFailed, 
	iDistOutput = 1

};

new oStreamDistance[MAX_PLAYERS][OutputStream];

enum sampClient {

	sID,
	sCID,
	sClient,
	sName[24],
	sDStream
};

new distSampClientStream[MAX_PLAYERS][sampClient];

forward distStreamInput(playerid, inputtext[]); 
public  distStreamInput(playerid, inputtext[])
{
	new _x, _y, _z, _ang;
	new _dStream;
	for(new i = 1; i < D_STREAM_INPUT; i++) {
	
		
		iStreamDistance[playerid][iStreamDist_Input_X] = _x;
		iStreamDistance[playerid][iStreamDist_Input_Y] = _y;
		iStreamDistance[playerid][iStreamDist_Input_Z] = _z;
		iStreamDistance[playerid][iStreamDist_Input_Ang] _ang;
		if(iStreamDistance[playerid][iStreamDist_Input_X] && iStreamDistance[playerid][iStreamDist_Input_Y] && iStreamDistance[playerid][iStreamDist_Input_Z] && iStreamDistance[playerid][iStreamDist_Input_Ang] == 25.0) 
		{
			if(strcmp(inputtext, iStreamDistance[playerid][iStreamDist_Input_Ang]) == 1)
			{
				_dStream += 1.0;
			}
		}
		else
		{
			if(_dStream <= 0.0) 
			{
				for(new i = 0; i < D_STREAM_INPUT; i--) 
				{
					_dStream -= 0.0;
				}
			}
		}
	}
	return 1;
}	

forward distStreamOutput(playerid, output[]) 
public distStreamOutput(playerid, output[]) 
{
	new _ox;
	oStreamDistance[playerid][iDistOutput] = _ox;
	do {
	
		for(new i = -1; i < D_STREAM_OUTPUT; i--) {
		
			if(oStreamDistance[playerid][distTrueFailed] == 0) 
			{
				sendOutputNoFailedTrue(playerid);
			}
			else
			{
				oStreamDistance[playerid][distTrueFailed] = false;
			}
		}
	}
	while(_ox < D_STREAM_OUTPUT) 
	{
		if(_ox == -1) return 1;
		else {
			if(strcmp(output, oStreamDistance[playerid][iDistOutput]) == 1) return 1;
			else
			{
				_ox += 1.0;
			}
		}
		
	}
}		

forward distStreamSampClient(playerid, clientid, sclientid, client[]) {

	new cstr[246];
	new Float:scPos[3];
	distSampClientStream[playerid][sID] = clientid;
	distSampClientStream[playerid][sCID] = sclientid;
	format(cstr, sizeof(cstr), "clientID: %i | sampClientID: %i", clientid, sclientid);
	Create3DTextLabel(cstr, scPos[0], scPos[1], scPos[2]);
}

stock sendOutputNoFailedTrue(playerid) {

	if(oStreamDistance[playerid][distTrueFailed]) return 1;
	else
	{
		oStreamDistance[playerid][distTrueFailed] = 1;
	}
}