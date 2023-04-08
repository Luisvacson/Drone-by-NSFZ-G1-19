#ifndef R_EKF_CORE_H
#define R_EKF_CORE_H

#include "R_Math.h"
#include "R_EKF_State.h"
#include "R_Sensor.h"

#define NUM_STATE 23

class R_EKF_Core
{
    public:
        R_Float dt;
        R_Float g_n;
        R_Float g_e;
        R_Float g_d;

        R_Float omega_cov_x;
        R_Float omega_cov_y;
        R_Float omega_cov_z;
        R_Float acc_cov_x;
        R_Float acc_cov_y;
        R_Float acc_cov_z;
        R_Float omega_bias_cov_x;
        R_Float omega_bias_cov_y;
        R_Float omega_bias_cov_z;
        R_Float acc_bias_cov_x;
        R_Float acc_bias_cov_y;
        R_Float acc_bias_cov_z;
        R_Float mag_noise_cov_n;
        R_Float mag_noise_cov_e;
        R_Float mag_noise_cov_d;
        R_Float mag_bias_noise_cov_x;
        R_Float mag_bias_noise_cov_y;
        R_Float mag_bias_noise_cov_z;
        R_Float baro_bias_noise_cov;

        R_Float rv_n;
        R_Float rv_e;
        R_Float rv_d;
        R_Float rp_n;
        R_Float rp_e;
        R_Float rp_d;
        R_Float rmag_x;
        R_Float rmag_y;
        R_Float rmag_z;
        R_Float rdec;
        R_Float ryaw;
        R_Float rbaro;


        R_Vector<72> OF;
        R_Vector<83> OG;
        R_Vector<95> OQ;
        R_Vector<150> OPP;


        R_Float q1;
        R_Float q2;
        R_Float q3;
        R_Float q4;
        R_Float velocity_n;
        R_Float velocity_e;
        R_Float velocity_d;
        R_Float position_n;
        R_Float position_e;
        R_Float position_d;
        R_Float omega_bias_x;
        R_Float omega_bias_y;
        R_Float omega_bias_z;
        R_Float acc_bias_x;
        R_Float acc_bias_y;
        R_Float acc_bias_z;
        R_Float mag_n;
        R_Float mag_e;
        R_Float mag_d;
        R_Float mag_bias_x;
        R_Float mag_bias_y;
        R_Float mag_bias_z;
        R_Float baro_bias;

        R_Float da_prev_x;
        R_Float da_prev_y;
        R_Float da_prev_z;
        R_Float dv_prev_x;
        R_Float dv_prev_y;
        R_Float dv_prev_z;

        R_Matrix<NUM_STATE,NUM_STATE> P;

        inline R_EKF_Core();
        inline void initialize();

        void predict_state(R_Acc_Output acc,R_Gyro_Output gyro);
        void claculate_optimse(R_Acc_Output acc,R_Gyro_Output gyro);
        void predict_covariances();

        void fuse_GPS(R_GPS_Output GPS);
        void fuse_mag(R_Mag_Output mag);
        void fuse_baro(R_Baro_Output baro);
        void fuse_dec(R_Dec_Output dec);

        inline void calculate_prev();

        void calculate_output();
};

#endif