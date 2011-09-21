#ifndef MIDI_EVENT_H
#define MIDI_EVENT_H

#include <QtGlobal>

#include <mt32emu/mt32emu.h>

enum MidiEventType {
	SHORT_MESSAGE,
	SYSEX
};

typedef qint64 SynthTimestamp;

class MidiEvent {
private:
	SynthTimestamp timestamp;
	MidiEventType type;
	MT32Emu::Bit32u msg;
	MT32Emu::Bit32u sysexLen;
	unsigned char *sysexData;

public:
	MidiEvent();
	~MidiEvent();

	SynthTimestamp getTimestamp() const;
	MidiEventType getType() const;
	MT32Emu::Bit32u getShortMessage() const;
	MT32Emu::Bit32u getSysexLen() const;
	unsigned char *getSysexData() const;

	void assignShortMessage(SynthTimestamp newTimestamp, MT32Emu::Bit32u newMsg);
	void assignSysex(SynthTimestamp newTimestamp, unsigned char *newSysexData, MT32Emu::Bit32u newSysexLen);
};

#endif