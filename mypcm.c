// mypcm.c

#include "mypcm.h"
#include <math.h>
#include <stdio.h>

// Generates the signal value at time t
float analog_signal_generator(asignal signal, int t) {
    return signal.A * sin(signal.omega * t + signal.sigma);
}

// Samples the analog signal at specific intervals
void sampler(float *samples, int interval, asignal signal) {
    for (int t = 0; t <= signal.duration; t += interval) {
        samples[t] = analog_signal_generator(signal, t);
    }
}

// Quantizes the sampled values into PCM pulses
void quantizer(float *samples, int *pcmpulses, int levels, float A) {
    float minAmp = -A;  // Minimum amplitude
    float maxAmp = A;   // Maximum amplitude

    for (int t = 0; samples[t] != '\0'; t++) {
        float normalized = (samples[t] - minAmp) / (maxAmp - minAmp);
        pcmpulses[t] = floor(normalized * levels);

        // Edge case: When the signal is max amplitude, assign max level
        if (samples[t] == maxAmp) {
            pcmpulses[t] = levels - 1;
        }
    }
}

// Encodes the quantized values into binary PCM codes
void encoder(int *pcmpulses, int *dsignal, int encoderbits) {
    for (int t = 0; pcmpulses[t] != '\0'; t++) {
        dsignal[t] = pcmpulses[t] & ((1 << encoderbits) - 1);  // Store PCM codes as binary
    }
}
