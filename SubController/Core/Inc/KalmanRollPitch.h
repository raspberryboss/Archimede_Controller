// Filtre de Kalman étendu pour l'estimation des angles de tangage ( theta ) et roulis (phi)

#ifndef INC_KALMANROLLPITCH_H_
#define INC_KALMANROLLPITCH_H_

#include <math.h>

#define KALMAN_P_INIT 0.1f
#define KALMAN_Q 0.001f
#define KALMAN_R 0.011f
#define KALMAN_PREDICT_PERIOD_MS 100
#define KALMAN_UPDATE_PERIOD_MS 1000

typedef struct {

	float phi_r;
	float theta_r;

	float P[2][2];

	float Q[2];
	float R[3];

} EKF;

void EKF_Init(EKF *ekf, float P, float Q[2], float R[3]);

void EKF_Predict(EKF *ekf, float p_rps, float q_rps, float r_rps, float sampleTime_s);

void EKF_Update(EKF *ekf, float ax_mps2, float ay_mps2, float az_mps2);

#endif
