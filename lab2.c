// lab2.c

#include <stdio.h>
#include <math.h>
#include "mypcm.h"

void run() {
    // define the parameters
    double A, omega, sigma;
    int duration, interval, encoderbits;
    
    // take the inputs
    scanf("%lf %lf %lf %d %d %d", &A, &omega, &sigma, &duration, &interval, &encoderbits);

    // Define number of quantization levels (2^encoderbits)
    int num_levels = (1 << encoderbits);  
    double q_min = -A;
    double q_max = A;

    // create sin wave samples and perform quantization
    for (int t = 0; t <= duration; t += interval) {
        // create the sin wave value at time t
        double x_t = A * sin(omega * t + sigma);

        // Quantize the value
        double q_level = ((x_t - q_min) / (q_max - q_min)) * num_levels;
        int q_value = (int) q_level;

        // Clip the quantized value(q_value) to stay within [0, num_levels - 1]
        if (q_value < 0) {
            q_value = 0;
        }
        if (q_value >= num_levels) {
            q_value = num_levels - 1;
        }
        //Generate the q_value in binary (encoderbits size)
        for (int i = encoderbits - 1; i >= 0; i--) {
            printf("%d", (q_value >> i) & 1);
        }
    }
    printf("\n");
}

int main() {
    run();
    return 0;
}
