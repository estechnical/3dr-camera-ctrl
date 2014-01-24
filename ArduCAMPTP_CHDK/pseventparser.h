#ifndef __PSEVENTPARSER_H__
#define __PSEVENTPARSER_H__

#include <inttypes.h>
#include <avr/pgmspace.h>
#include <message.h>
#include <parsetools.h>
#include <canonps.h>
#include "ptp_from_chdk.h"
#include "ptpdebug.h"


class PSEventParser : public PTPReadParser
{
	MultiValueBuffer					theBuffer;
	uint32_t							varBuffer;
	uint8_t								nStage;
        uint16_t							eventCode;
	uint32_t							objHandle;

	MultiByteValueParser				valueParser;

public:
	PSEventParser() : nStage(0), varBuffer(0), objHandle(0) 
	{ 
		theBuffer.pValue = &varBuffer;
	};
	uint32_t GetObjHandle() { return objHandle; };
	virtual void Parse(const uint16_t len, const uint8_t *pbuf, const uint32_t &offset);
};

#endif // __PSEVENTPARSER_H__
