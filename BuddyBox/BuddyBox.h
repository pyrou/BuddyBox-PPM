//
//  BuddyBox.h
//  BuddyBox
//
//  Created by Nicholas Robinson on 12/23/12.
//  Copyright (c) 2012 Nicholas Robinson. All rights reserved.
//

#ifndef BuddyBox_BuddyBox_h
#define BuddyBox_BuddyBox_h

static const unsigned int MAX_CHANNELS          = 10;
static const unsigned int SYNCHRO_FRAME_WIDTH   = 200;
static const unsigned int SIGNAL_HIGH           = 1;
static const unsigned int SIGNAL_LOW            = 0;

typedef struct
{
    unsigned int wireSignal;
    float localMaxSample;
    unsigned int sampleCount;
    unsigned int signalEdgeSampleCount;
    unsigned int elapsedCounts;
    unsigned int signalChannel;
    unsigned int signals[MAX_CHANNELS];
} BuddyBox;

// Public
void initializeBuddyBox(BuddyBox* bb);
void readBufferIntoBuddyBox(BuddyBox* bb, float* buffer, unsigned int bufferSize);

// Private
float getBuddyBoxSampleMagnitude(float sample);
float getTmpLocalMax(float bufferSampleMagnitude, float tmpLocalMaxSample);
unsigned int isBuddyBoxSignalEdge(BuddyBox *bb, float bufferSampleMagnitude);
unsigned int isBuddyBoxSignalHigh(BuddyBox *bb, float bufferSampleMagnitude);
void processBuddyBoxSignalEdge(BuddyBox *bb);
void updateBuddyBoxElapsedCounts(BuddyBox *bb);
unsigned int isBuddyBoxWireSignalHigh(BuddyBox *bb);
void processHighBuddyBoxWireSignal(BuddyBox *bb);
unsigned int isBuddyBoxSynchroFrameEncountered(BuddyBox *bb);
void processBuddyBoxPacket(BuddyBox *bb);
void targetNextBuddyBoxPacketChannel(BuddyBox *bb);

#endif
