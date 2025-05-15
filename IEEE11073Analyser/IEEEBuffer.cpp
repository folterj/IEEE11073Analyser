
#include "stdafx.h"
#include "IEEEBuffer.h"
#include "ntp.h"


IEEERegion::IEEERegion(int pointer,int len2) {
	start = pointer;
	len = len2;
	end = pointer + len2;
}


IEEEBuffer::IEEEBuffer() {
	reset();
}

void IEEEBuffer::reset() {
	clear();
	error = false;
	pointer = 0;
	resetRelPointer();
}

void IEEEBuffer::resetRelPointer() {
	relpointer = 0;
}

UInt16 IEEEBuffer::next() {
	UInt16 x = 0;

	if (pointer < size()) {
		x = this[pointer];
		pointer++;
		relpointer++;
	}
	return x;
}

UInt64 IEEEBuffer::next(int len) {
	UInt64 x = 0;
	int len2 = len/2;

	for (int i=0;i<len2;i++) {
		x*= 0x10000;
		x+= next();
	}
	return x;
}

String^ IEEEBuffer::nextBytes(int len) {
	String^ s = "";
	int len2 = len/2;

	for (int j=0;j<len2;j++) {
		s+= String::Format("{0:X4} ",next());
	}
	return s;
}


String^ IEEEBuffer::nextTime() {
	TimeDate_t dt;

	int eventTime = next() * 0x10000;
	eventTime+= next();
	if (eventTime != 0xFFFFFFFF && eventTime != 0) {
		dt = seconds2TimeDate(eventTime);
		return String::Format("{0}-{1:D2}-{2:D2} {3}:{4:D2}:{5:D2}",dt.year,dt.month,dt.day,dt.hour,dt.minute,dt.second);
	} else {
		return String::Format("{0:X8}",eventTime);
	}
}

String^ IEEEBuffer::nextAbsTime() {
	int year = next();
	int monthday = next();
	int month = monthday / 0x100;
	int day = monthday & 0xFF;
	int hourmin = next();
	int hour = hourmin / 0x100;
	int min = hourmin & 0xFF;
	int secmsec = next();
	int sec = secmsec / 0x100;
	int msec = secmsec & 0xFF;
	return String::Format("{0:X4}/{1:X2}/{2:X2} {3:X2}:{4:X2}:{5:X2}.{6:X2}",year,month,day,hour,min,sec,msec);
}

String^ IEEEBuffer::nextBOTime() {
	BOTime_t botime;
	TimeDate_t dt;

	botime.seconds = 0x10000 * next();
	botime.seconds += next();
	botime.fractionSeconds = next();
	botime.offset = next();
	dt = boTime2TimeDate(botime);
	if (botime.offset >= 0)
		return String::Format("BOTime = {0}-{1}-{2} {3}:{4:D2}:{5:D2} +{6:D4}",dt.year,dt.month,dt.day,dt.hour,dt.minute,dt.second,botime.offset);
	else
		return String::Format("BOTime = {0}-{1}-{2} {3}:{4:D2}:{5:D2} {6:D4}",dt.year,dt.month,dt.day,dt.hour,dt.minute,dt.second,botime.offset);
}

String^ IEEEBuffer::nextString(int len) {
	String^ s = "";
	char cs[100] = "\0";
	char c;
	int x;
	bool printable = true;

	for (int j=0;j<len/2;j++) {
		x = next();
		c = x / 0x100;
		if (c < 32 || c > 127)
			printable = false;
		strcat_s(cs,&c);
		c = x & 0xFF;
		if (c < 32 || c > 127)
			printable = false;
		strcat_s(cs,&c);
		s+= String::Format("{0:X4}",x);
	}
	if (printable)
		s+= String::Format(" ({0})",gcnew String(cs));
	return s;
}

bool IEEEBuffer::eof() {
	return (pointer >= size());
}

bool IEEEBuffer::skipUpto(int len) {
	int len2 = len/2;
	bool ok;
	int offset = len2 - relpointer;

	if (len2 == 0)
		return true;

	if (pointer + offset <= size()) {
		ok = true;
	} else {
		ok = false;
		offset = size() - pointer;
	}
	pointer+= offset;
	relpointer+= offset;
	return ok;
}

bool IEEEBuffer::skipRegion(IEEERegion^ region) {
	if (region->end <= size()) {
		pointer = region->end;
		return true;
	} else {
		pointer = size();
	}
	return false;
}

bool IEEEBuffer::checkLen(int len,int maxlen) {
	int len2 = len/2;
	int maxlen2 = maxlen/2;
	if (relpointer + len2 > maxlen2) {
		error = true;
		return false;
	}
	return true;
}

bool IEEEBuffer::popError() {
	if (error) {
		error = false;
		return true;
	}
	return false;
}

IEEERegion^ IEEEBuffer::getRegion(int len) {
	return gcnew IEEERegion(pointer,len/2);
}

bool IEEEBuffer::checkRegionEnd(IEEERegion^ region) {
	return (region->end == pointer);
}
