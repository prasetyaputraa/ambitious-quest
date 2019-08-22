#include<iostream>
#include<stdint.h>
#include  "s_minimal_wave_file.h"

using namespace std;

int nSampleRate  = 44100;
int nNumSeconds  = 4;
int nNumChannels = 1;

int nNumSamples = nSampleRate * nNumChannels * nNumSeconds;
int32_t *pData  = new int32_t[nNumSamples];

int32_t nValue = 0;

int main() 
{
    for(int nIndex = 0; nIndex < nNumSamples; ++nIndex)
    {
        nValue += 8000000;
        pData[nIndex] = nValue;

        cout << nValue;
    }
    
    WriteWaveFile(
        "outmono.wav",
        pData,
        nNumSamples * sizeof(pData[0]),
        nNumChannels,
        nSampleRate,
        sizeof(pData[0]) * 8
    );
    
    delete[] pData;

    return 0;
}

