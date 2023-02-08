clear all;

%%state vector

syms q1 q2 q3 q4 'real' %state quaternion
syms v_n v_e v_d 'real' %velocity in NED
syms p_n p_e p_d 'real' %position in NED
syms da_bias_x da_bias_y da_bias_z 'real' %delta angle bias in XYZ - rad
syms dv_bias_x dv_bias_y dv_bias_z 'real' %delta velocity bias in XYZ - m/s
syms mag_n mag_e mag_d 'real' %earth magnetic field in NED - milligauss
syms mag_bias_x mag_bias_y mag_bias_z 'real' %body magnetic field in xyz - milligauss

state_vector = [q1;q2;q3;q4;v_n;v_e;v_d;p_n;p_e;p_d;da_bias_x;da_bias_y;da_bias_z;dv_bias_x;dv_bias_y;dv_bias_z;mag_n;mag_e;mag_d;mag_bias_x;mag_bias_y;mag_bias_z];
nstate = numel(state_vector);

syms da_x da_y da_z 'real' %delta angle measurement in XYZ - rad
syms dv_x dv_y dv_z 'real' %delta velocity measurement in XYZ - m/s^2
syms da_noise_x da_noise_y da_noise_z 'real' %delta angle noise - rad
syms dv_noise_x dv_noise_y dv_noise_z 'real' %delta velocity noise - m/s
syms mag_noise_n mag_noise_e mag_noise_d 'real' %mag noise - milligauss
syms da_bias_noise_x da_bias_noise_y da_bias_noise_z 'real' %delta angle bias noise - rad
syms dv_bias_noise_x dv_bias_noise_y dv_bias_noise_z 'real' %delta angle bias noise - m/s
syms mag_bias_noise_x mag_bias_noise_y mag_bias_noise_z 'real' %mag bias noise - milligauss
syms dt 'real' %measurement time step - s
syms g_n g_e g_d 'real' %NED gravity - m/s^2
syms da_cov_x da_cov_y da_cov_z dv_cov_x dv_cov_y dv_cov_z 'real'; %delta angle and delta velocity measurement variances
syms da_bias_cov_x da_bias_cov_y da_bias_cov_z dv_bias_cov_x dv_bias_cov_y dv_bias_cov_z 'real'; %delta angle and delta velocity measurement variances
syms mag_noise_cov_n mag_noise_cov_e mag_noise_cov_d 'real' %mag noise variances- milligauss^2
syms mag_bias_noise_cov_x mag_bias_noise_cov_y mag_bias_noise_cov_z 'real' %mag bias noise variances - milligauss^2
syms rv_n rv_e rv_d 'real' %variances for NED velocity measurements - (m/s)^2
syms rp_n rp_e rp_d 'real' %variances for NED position measurements - m^2
syms rmag 'real' %variance for magnetic flux measurements - milligauss^2
syms rdec 'real' %variance for magnetic declination measurements - rad^2
syms ryaw 'real' %variance for yaw measurements - rad^2
syms rgpsv 'real' %variances for GPS NED velocity measurements - (m/s)^2
syms rgpsp 'real' %variances for GPS NED position measurements - m^2

da_bias = [da_bias_x;da_bias_y;da_bias_z];
dv_bias = [dv_bias_x;dv_bias_y;dv_bias_z];

da_noise = [da_noise_x;da_noise_y;da_noise_z];
dv_noise = [dv_noise_x;dv_noise_y;dv_noise_z];
mag_noise = [mag_noise_n;mag_noise_e;mag_noise_d];
da_bias_noise = [da_bias_noise_x,da_bias_noise_y,da_bias_noise_z];
dv_bias_noise = [dv_bias_noise_x,dv_bias_noise_y,dv_bias_noise_z];
mag_bias_noise = [mag_bias_noise_n;mag_bias_noise_e;mag_bias_noise_d];

da_measurement = [da_x;da_y;da_z];
dv_measurement = [dv_x;dv_y;dv_z];

da_prev = [da_prev_x;da_prev_y;da_prev_z];
dv_prev = [dv_prev_x;dv_prev_y;dv_prev_z];

tbn = Quat2Tbn([q1,q2,q3,q4]);

%Ignore coning compensation and earths rotation as these effect are
%negligible in terms of covariance growth compared to other efects for our
%grade of sensor
%deltaA = da - da_b + 1/12*cross(da_prev,da) - transpose(Cbn)*([omn; ome; omd])*dt;
real_da = da_measurement - da_bias - da_noise;

%define the bias corrected delta v
%Ignore sculling as this effect is negligible in terms of covariance growth 
%compared to other effects for our grade of sensor
%deltaVelocity = dv - dv_b + 0.5*cross(da,dv) + 1/12*(cross(da_prev,dv) + cross(dv_prev,da));
%rotation correction
real_dv = dv_measurement - dv_bias - dv_noise;

quat = [q0;q1;q2;q3];

%define the attitude update equations
%use a first order expansion of rotation to calculate the quaternion increment
%acceptable for propagation of covariances
dquat = [1;
    0.5*real_da(1);
    0.5*real_da(2);
    0.5*real_da(3);
    ];
quat_new = QuatMult(quat,dquat);

%define the velocity update equations
%vNew = [vn;ve;vd] + [gn;ge;gd]*dt + Tbn*deltaVelocity - cross(2*[omn; ome; omd],[vn;ve;vd])*dt;
v_new = [v_n;v_e;v_d] + [g_n;g_e;g_d]*dt + tbn*real_dv;

p_new = [p_n;p_e;p_d] + [v_n;v_e;v_d]*dt + 0.5*real_dv*dt;

da_bias_new = [da_bias_x;da_bias_y;da_bias_z] + da_bias_noise;
dv_bias_new = [dv_bias_x;dv_bias_y;dv_bias_z] + dv_bias_noise;

magn_new = mag_n + mag_noise_n;
mage_new = mag_e + mag_noise_e;
magd_new = mag_d + mag_noise_d;

mag_bias_x_new = mag_bias_x + mag_bias_noise_x;
mag_bias_y_new = mag_bias_y + mag_bias_noise_y;
mag_bias_z_new = mag_bias_z + mag_bias_noise_z;

process_equation = [quat_new;v_new;p_new;da_bias_new,dv_bias_new;magn_new;mage_new;magd_new;mag_bias_x_new;mag_bias_y_new;mag_bias_z_new;];

%%generate equations

%derive the state transition matrix
F = jacobian(process_equation,state_vector);
[F,OF] = OptimiseAlgebra(F,'OF');

%Define the control (disturbance) vector. Error growth in the inertial
%solution is assumed to be driven by 'noise' in the delta angles and
%velocities, after bias effects have been removed. This is OK becasue we
%have sensor bias accounted for in the state equations.
dist_vector = [da_noise;dv_noise;da_bias_noise;dv_bias_noise;mag_noise;mag_bias_noise];

%derive the control(disturbance) influence matrix
G = jacobian(process_equation,dist_vector);
[G,OG] = OptimiseAlgebra(G,'OG');

%derive the state error matrix
%Note - this derivation of the covariance update equations does not include
%any general state noise - this will be added at the implementation stage
%by adding an approriately scaled diagonal process noise matrix to the 
%covariance matrix
noise = diag([da_cov_x da_cov_y da_cov_z dv_cov_x dv_cov_y dv_cov_z  da_bias_cov_x da_bias_cov_y da_bias_cov_z dv_bias_cov_x dv_bias_cov_y dv_bias_cov_z mag_noise_cov_n mag_noise_cov_e mag_noise_cov_d mag_bias_noise_cov_x mag_bias_noise_cov_y mag_bias_noise_cov_z]);
Q = G*noise*transpose(G);
[Q,OQ] = OptimiseAlgebra(Q,'OQ');

%define a symbolic covariance matrix using strings to represent 
%'_lp_' to represent '( '
%'_c_' to represent ,
%'_rp_' to represent ')' 
%these can be substituted later to create executable code
for rowIndex = 1:nstate
    for colIndex = 1:nstate
        eval(['syms LP_lp_',num2str(rowIndex),'_c_',num2str(colIndex), '_rp_ real']);
        eval(['P(',num2str(rowIndex),',',num2str(colIndex), ') = LP_lp_',num2str(rowIndex),'_c_',num2str(colIndex),'_rp_;']);
    end
end

PP = F*P*transpose(F) + Q;
[PP,OPP] = OptimiseAlgebra(PP,'OPP');

%%derive equations for sequential fusion of velocity and position measurements

H_VN = jacobian(v_n,state_vector);
K_VN = (P*transpose(H_VN))/(H_VN*P*transpose(H_VN) + rv_n);

H_VE = jacobian(v_e,state_vector);
K_VE = (P*transpose(H_VE))/(H_VE*P*transpose(H_VE) + rv_e);

H_VD = jacobian(v_d,state_vector);
K_VD = (P*transpose(H_VD))/(H_VD*P*transpose(H_VD) + rv_d);

H_PN = jacobian(p_n,state_vector);
K_PN = (P*transpose(H_PN))/(H_PN*P*transpose(H_PN) + rp_n);

H_PE = jacobian(p_e,state_vector);
K_PE = (P*transpose(H_PE))/(H_PE*P*transpose(H_PE) + rp_e);

H_PD = jacobian(p_d,state_vector);
K_PD = (P*transpose(H_PD))/(H_PD*P*transpose(H_PD) + rp_d);

%combine into a single H and K matrix (note these matrices cannot be used
%for a single step fusion, so each row|column mst be used in a separate
%fusion step
H_VP  = [H_VN;H_VE;H_VD;H_PN;H_PE;H_PD];
clear    H_VN H_VE H_VD H_PN H_PE H_PD;
K_VP = [K_VN,K_VE,K_VD,K_PN,K_PE,K_PD];
clear   K_VN K_VE K_VD K_PN K_PE K_PD;
[K_VP,OK_VP] = OptimiseAlgebra(K_VP,'OK_VP');

%%derive equations for fusion of magnetic field measurement
mag_measurement = transpose(tbn)*[mag_n;mag_e;mag_d] + [mag_bias_x;mag_bias_y;mag_bias_z]; % predicted measurement
H_MAG = jacobian(mag_measurement,state_vector); % measurement Jacobian
[H_MAG,OH_MAG] = OptimiseAlgebra(H_MAG,'OH_MAG');

K_MX = (P*transpose(H_MAG(1,:)))/(H_MAG(1,:)*P*transpose(H_MAG(1,:)) + rmag); % Kalman gain vector
[K_MX,OK_MX] = OptimiseAlgebra(K_MX,'OK_MX');
K_MY = (P*transpose(H_MAG(2,:)))/(H_MAG(2,:)*P*transpose(H_MAG(2,:)) + rmag); % Kalman gain vector
[K_MY,OK_MY] = OptimiseAlgebra(K_MY,'OK_MY');
K_MZ = (P*transpose(H_MAG(3,:)))/(H_MAG(3,:)*P*transpose(H_MAG(3,:)) + rmag); % Kalman gain vector
[K_MZ,OK_MZ] = OptimiseAlgebra(K_MZ,'OK_MZ');

%%derive equations for fusion of magnetic declination measurement
dec_measurement = atan(mag_e/mag_n);
H_DEC = jacobian(dec_measurement,state_vector);
[H_DEC,OH_DEC] = OptimiseAlgebra(H_DEC,'OH_DEC');
K_DEC = (P*transpose(H_DEC))/(H_DEC*P*transpose(H_DEC) + rdec);
[K_DEC,OK_DEC] = OptimiseAlgebra(K_DEC,'OK_DEC');

%%derive equations for fusion of yaw (yaw321)
yaw321_measurement = atan(tbn(2,1)/tbn(1,1));
H_YAW321 = jacobian(yaw321_measurement,state_vector);
H_YAW321 = simplify(H_YAW321);
K_YAW321 = (P*transpose(H_YAW321))/(H_YAW321*P*transpose(H_YAW321) + ryaw);
K_YAW321 = simplify(K_YAW321);

%%derive equations for fusion of yaw (yaw312)
yaw312_measurement = atan(-tbn(1,2)/tbn(2,2));
H_YAW312 = jacobian(yaw312_measurement,state_vector);
H_YAW312 = simplify(H_YAW312);
K_YAW312 = (P*transpose(H_YAW312))/(H_YAW312*P*transpose(H_YAW312) + ryaw);
K_YAW312 = simplify(K_YAW312);

file_name = 'ScriptOutput.mat';
save(file_name);

OutputFormater(nstate);
ConvertCode();