#ifndef EYERPLAYERLIB_THREAD_H
#define EYERPLAYERLIB_THREAD_H

#include "EyerCore/EyerCore.hpp"
#include "EyerThread/EyerThread.hpp"
#include "EyerAV/EyerAV.hpp"
#include "EyerEventQueue/EyerEventQueue.hpp"
#include "EyerAV/EyerAVQueue.hpp"
#include "EyerPlayerLib.h"
#include "PlayerTypedef.hpp"

#include <QAudioFormat>
#include <QAudioOutput>

namespace EyerPlayer {

    class AVDecoderThread;
    class AVReaderThread;
    class PlayCtrThread;
    class AudioPlayThread;

    class AVReaderThread : public Eyer::EyerThread
    {
    public:
        AVReaderThread(Eyer::EyerString url, Eyer::EyerEventQueue * eventQueue, long long openEventId, AVFrameQueueManager * _queueManager, double seekTime);
        ~AVReaderThread();
        virtual void Run();

        int Play();
        int Pause();

        Eyer::EyerString GetURL();

    private:
        Eyer::EyerString url;
        Eyer::EyerEventQueue * eventQueue = nullptr;
        long long openEventId = 0;

        std::vector<AVDecoderThread *> decodeThreadList;

        PlayCtrThread * playerCtr = nullptr;

        AVFrameQueueManager * queueManager = nullptr;

        double seekTime = 0.0;
    };

    class AVDecoderThread : public Eyer::EyerThread
    {
    public:
        AVDecoderThread(Eyer::EyerAVStream & stream, StreamInfo & streamInfo, Eyer::EyerEventQueue * eventQueue, AVFrameQueueManager * _queueManager, double _startTme);
        ~AVDecoderThread();
        virtual void Run();

        int PushPkt(Eyer::EyerAVPacket * pkt);
        int GetQueueSize();
        int GetStreamId();

        int GetFrameQueueSize();

        int HasNewFrame();


        int SetReadFinishFlag();
    private:
        double startTme;

        Eyer::EyerEventQueue * eventQueue = nullptr;
        Eyer::EyerAVDecoder * decoder = nullptr;
        int streamId = -1;

        std::atomic_int isReadFinish {0};

        Eyer::EyerAVQueue<Eyer::EyerAVPacket> pktQueue;
        AVFrameQueueManager * queueManager = nullptr;
        StreamInfo streamInfo;
    };


    class PlayCtrThread : public Eyer::EyerThread
    {
    public:
        PlayCtrThread(Eyer::EyerEventQueue * eventQueue, AVFrameQueueManager * _queueManager, int recommendVideoIndex, int recommendAudioIndex, double seekTime);
        ~PlayCtrThread();

        virtual void Run();
    private:
        Eyer::EyerEventQueue * eventQueue = nullptr;
        AVFrameQueueManager * queueManager = nullptr;

        int recommendVideoIndex = -1;
        int recommendAudioIndex = -1;

        double playerProgressPts = 0.0;
        double startPlayerPts = 0.0;
    };


    class AudioPlayThread : public Eyer::EyerThread
    {
    public:
        AudioPlayThread(Eyer::EyerEventQueue * eventQueue, AVFrameQueueManager * _queueManager);
        ~AudioPlayThread();

        virtual void Run();

    private:
        Eyer::EyerEventQueue * eventQueue = nullptr;
        AVFrameQueueManager * queueManager = nullptr;

        QAudioOutput * out = nullptr;
        QIODevice * io = nullptr;
    };
}

#endif // EYERPLAYERLIB_THREAD_H
