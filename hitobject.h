#ifndef HITOBJECT_H
#define HITOBJECT_H

#include "boundedint.h"

class HitObject
{
public:
    HitObject();

    enum SampleSet {
        AUTO,
        NORMAL,
        SOFT,
        DRUM
    };

private:

    // Ref: 320,192,54981,1,0,0:0:0:100:LR_Kick Total beat.wav
    //      192,192,56040,1,0,0:0:0:30:LR_Kick Bass strong fast.wav

    double m_column;
    double m_offset;
    SampleSet m_hitsound;
    SampleSet m_sample;
    SampleSet m_addition;
    BoundedInt m_custom;

};

#endif // HITOBJECT_H
