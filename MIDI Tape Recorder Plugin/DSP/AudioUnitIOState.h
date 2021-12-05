//
//  AudioUnitIOState.h
//  MIDI Tape Recorder
//
//  Created by Geert Bevin on 11/27/21.
//  MIDI Tape Recorder ©2021 by Geert Bevin is licensed under CC BY 4.0
//

#pragma once

#import <AudioToolbox/AUAudioUnit.h>
#import <CoreAudio/CoreAudioTypes.h>

struct AudioUnitIOState {
    int32_t channelCount    { 0 };
    float sampleRate        { 44100.f };
    uint32_t frameCount     { 0 };
    double tempo            { 120.0 };
    double currentBeatPos   { 0.0 };

    const AudioTimeStamp* timestamp    { nullptr };

    AUMIDIOutputEventBlock midiOutputEventBlock     { nullptr };
    AUHostTransportStateBlock transportStateBlock   { nullptr };
    AUHostMusicalContextBlock musicalContext        { nullptr };

    void reset() {
        channelCount = 0;
        sampleRate = 44100.f;
        frameCount = 0;
        
        timestamp = nullptr;
        
        midiOutputEventBlock = nullptr;
        transportStateBlock = nullptr;
        musicalContext = nullptr;
    }
};
