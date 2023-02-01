clear all;

%%state vector

syms q1 q2 q3 q4 'real' %state quaternion
syms vn ve vd 'real' %velocity in NED
syms pn pe pd 'real' %position in NED
syms da_bias_x da_bias_y da_bias_z 'real' %delta angle bias in XYZ - rad
syms dv_bias_x dv_bias_y dv_bias_z 'real' %delta velocity bias in XYZ - m/s
syms magn mage magd 'real' %earth magnetic field in NED - milligauss
syms mag_bias_x mag_bias_y mag_bias_z 'real' %body magnetic field in xyz - milligauss

state_vector = [q1;q2;q3;q4;vn;ve;vd;pn;pe;pd;da_bias_x;da_bias_y;da_bias_z;dv_bias_x;dv_bias_y;dv_bias_z;magn;mage;magd;mag_bias_x;mag_bias_y;mag_bias_z];
nstate = numel(stateVector);

syms da_measurement_x da_measurement_y da_measurement_z 'real' %delta angle measurement in XYZ - rad
syms dv_measurement_x dv_measurement_y dv_measurement_z 'real' %delta velocity measurement in XYZ - m/s
syms dt 'real' %measurement time step - s
syms gn ge gd 'real' %NED gravity - m/sec^2
syms omn ome omd 'real'; %earth rotation vector in local NED axes - rad/sec
syms daxcov daycov dazcov dvxcov dvycov dvzcov 'real'; %delta angle and delta velocity measurement variances
syms rvn rve rvd 'real' %variances for NED velocity measurements - (m/sec)^2
syms rpn rpe rpd 'real' %variances for NED position measurements - m^2
syms rmag 'real'  %variance for magnetic flux measurements - milligauss^2

da_bias = [da_bias_x;da_bias_y;da_bias_z];
dv_bias = [dv_bias_x;dv_bias_y;dv_bias_z];

da_measurement = [da_measurement_x,da_measurement_y,da_measurement_z];
dv_measurement = [dv_measurement_x,dv_measurement_y,dv_measurement_z];

tbn = Quat2Tbn([q1,q2,q3,q4]);

%Ignore coning compensation and earths rotation as these effect are
%negligible in terms of covariance growth compared to other efects for our
%grade of sensor
%deltaA = da - da_b + 1/12*cross(da_prev,da) - transpose(Cbn)*([omn; ome; omd])*dt;
da = da_measurement - da_bias;

%define the bias corrected delta v
%Ignore sculling as this effect is negligible in terms of covariance growth 
%compared to other effects for our grade of sensor
%deltaVelocity = dv - dv_b + 0.5*cross(da,dv) + 1/12*(cross(da_prev,dv) + cross(dv_prev,da));
dv = dv_measurement - dv_bias;

quat = [q0;q1;q2;q3];

%define the attitude update equations
%use a first order expansion of rotation to calculate the quaternion increment
%acceptable for propagation of covariances
dquat = [1;
    0.5*da(1);
    0.5*da(2);
    0.5*da(3);
    ];
quat_new = QuatMult(quat,dquat);

%define the velocity update equations
%vNew = [vn;ve;vd] + [gn;ge;gd]*dt + Tbn*deltaVelocity - cross(2*[omn; ome; omd],[vn;ve;vd])*dt;
v_new = [vn;ve;vd] + [gn;ge;gd]*dt + tbn*dv;

p_new = [pn;pe;pd] + [vn;ve;vd]*dt;

da_bias_new = [da_bias_x;da_bias_y;da_bias_z];
dv_bias_new = [dv_bias_x;dv_bias_y;dv_bias_z];

magn_new = magn;
mage_new = mage;
magd_new = magd;

mag_bias_x_new = mag_bias_x;
mag_bias_y_new = mag_bias_y;
mag_bias_z_new = mag_bias_z;

process_equation = [quat_new;v_new;p_new;da_bias_new,dv_bias_new;magn_new;mage_new;magd_new;mag_bias_x_new;mag_bias_y_new;mag_bias_z_new;];

%%generate equations

%derive the state transition matrix
F = jacobian(process_equation,state_vector);
[F,OF] = OptimiseAlgebra(F,'OF');

%Define the control (disturbance) vector. Error growth in the inertial
%solution is assumed to be driven by 'noise' in the delta angles and
%velocities, after bias effects have been removed. This is OK becasue we
%have sensor bias accounted for in the state equations.
dist_vector = [da,dv];

%derive the control(disturbance) influence matrix
G = jacobian(process_equation,dist_vector);
[G,OG] = OptimiseAlgebra(G,'OG');

%derive the state error matrix
%Note - this derivation of the covariance update equations does not include
%any general state noise - this will be added at the implementation stage
%by adding an approriately scaled diagonal process noise matrix to the 
%covariance matrix
noise = diag([daxcov daycov dazcov dvxcov dvycov dvzcov]);
Q = G*imuNoise*transpose(G);
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

H_VN = jacobian(vn,state_vector);
K_VN = (P*transpose(H_VN))/(H_VN*P*transpose(H_VN) + rvn);

H_VE = jacobian(ve,state_vector);
K_VE = (P*transpose(H_VE))/(H_VE*P*transpose(H_VE) + rve);

H_VD = jacobian(vd,state_vector);
K_VD = (P*transpose(H_VD))/(H_VD*P*transpose(H_VD) + rvd);

H_PN = jacobian(pn,state_vector);
K_PN = (P*transpose(H_PN))/(H_PN*P*transpose(H_PN) + rpn);

H_PE = jacobian(pe,state_vector);
K_PE = (P*transpose(H_PE))/(H_PE*P*transpose(H_PE) + rpe);

H_PD = jacobian(pd,state_vector);
K_PD = (P*transpose(H_PD))/(H_PD*P*transpose(H_PD) + rpd);

% combine into a single H and K matrix (note these matrices cannot be used
% for a single step fusion, so each row|column mst be used in a separate
% fusion step
H_VP  = [H_VN;H_VE;H_VD;H_PN;H_PE;H_PD];
clear    H_VN H_VE H_VD H_PN H_PE H_PD;
K_VP = [K_VN,K_VE,K_VD,K_PN,K_PE,K_PD];
clear   K_VN K_VE K_VD K_PN K_PE K_PD;
[K_VP,OK_VP] = OptimiseAlgebra(K_VP,'OK_VP');

%% derive equations for fusion of magnetic field measurement
mag_measurement = transpose(tbn)*[magn;mage;magd] + [mag_bias_x;mag_bias_y;mag_bias_z]; % predicted measurement
H_MAG = jacobian(mag_measurement,state_vector); % measurement Jacobian
[H_MAG,OH_MAG] = OptimiseAlgebra(H_MAG,'OH_MAG');

K_MX = (P*transpose(H_MAG(1,:)))/(H_MAG(1,:)*P*transpose(H_MAG(1,:)) + rmag); % Kalman gain vector
[K_MX,OK_MX]=OptimiseAlgebra(K_MX,'OK_MX');
K_MY = (P*transpose(H_MAG(2,:)))/(H_MAG(2,:)*P*transpose(H_MAG(2,:)) + rmag); % Kalman gain vector
[K_MY,OK_MY]=OptimiseAlgebra(K_MY,'OK_MY');
K_MZ = (P*transpose(H_MAG(3,:)))/(H_MAG(3,:)*P*transpose(H_MAG(3,:)) + rmag); % Kalman gain vector
[K_MZ,OK_MZ]=OptimiseAlgebra(K_MZ,'OK_MZ');

file_name = 'ScriptOutput.mat';
save(file_name);

















