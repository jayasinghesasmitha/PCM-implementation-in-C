// mypcm.h

#ifndef MYPCM_H
#define MYPCM_H

// Struct to store analog signal properties
typedef struct {
    float A;       // Amplitude
    float omega;   // Angular frequency
    float sigma;   // Phase
    int duration;  // Duration of the signal
} asignal;

// Function prototypes
float analog_signal_generator(asignal signal, int t);
void sampler(float *samples, int interval, asignal signal);
void quantizer(float *samples, int *pcmpulses, int levels, float A);
void encoder(int *pcmpulses, int *dsignal, int encoderbits);
void run();

#endif
