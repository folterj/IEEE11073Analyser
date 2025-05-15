#pragma once

#include <cliext/vector>

using namespace System;
using namespace cliext;


ref class IEEERegion
{
public:
	int start;
	int len;
	int end;

	IEEERegion(int pointer,int len2);
};


ref class IEEEBuffer : public vector<UInt16>
{
public:
	int pointer;
	int relpointer;
	bool error;

	IEEEBuffer();
	void reset();
	void resetRelPointer();
	UInt16 next();
	UInt64 next(int len);
	String^ nextBytes(int len);
	String^ nextTime();
	String^ nextAbsTime();
	String^ nextBOTime();
	String^ nextString(int len);
	bool skipUpto(int len);
	bool skipRegion(IEEERegion^ region);
	bool eof();
	bool checkLen(int len,int maxlen);
	bool popError();
	IEEERegion^ getRegion(int len);
	bool checkRegionEnd(IEEERegion^ region);
};
