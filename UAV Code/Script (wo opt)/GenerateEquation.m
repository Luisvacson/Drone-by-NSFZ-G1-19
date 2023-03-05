clear all;

disp('Derivation start');

%%state vector

disp('Define state vector');

syms q1 q2 q3 q4 'real' %state quaternion
syms velocity_n velocity_e velocity_d 'real' %velocity in NED
syms postion_n postion_e postion_d 'real' %position in NED
syms omega_bias_x omega_bias_y omega_bias_z 'real' %omega bias in XYZ - rad/s
syms acc_bias_x acc_bias_y acc_bias_z 'real' %acc bias in XYZ - m/s^2
syms mag_n mag_e mag_d 'real' %earth magnetic field in NED - milligauss
syms mag_bias_x mag_bias_y mag_bias_z 'real' %body magnetic field in xyz - milligauss
syms baro_bias 'real'%baro bias - m

state_vector = [q1;q2;q3;q4;velocity_n;velocity_e;velocity_d;postion_n;postion_e;postion_d;omega_bias_x;omega_bias_y;omega_bias_z;acc_bias_x;acc_bias_y;acc_bias_z;mag_n;mag_e;mag_d;mag_bias_x;mag_bias_y;mag_bias_z;baro_bias];
nstate = numel(state_vector);

disp('Complete');

disp('Define process equation');

syms omega_x omega_y omega_z 'real' %omega measurement in XYZ - rad/s
syms acc_x acc_y acc_z 'real' %acc measurement in XYZ - m/s^2
syms da_prev_x da_prev_y da_prev_z 'real' %previous delta angle - rad
syms dv_prev_x dv_prev_y dv_prev_z 'real' %previous delta velocity - m/s
syms omega_noise_x omega_noise_y omega_noise_z 'real' %omega noise - rad/s
syms acc_noise_x acc_noise_y acc_noise_z 'real' %acc noise - m/s^2
syms mag_noise_n mag_noise_e mag_noise_d 'real' %mag noise - milligauss
syms omega_bias_noise_x omega_bias_noise_y omega_bias_noise_z 'real' %omega bias noise - rad/s
syms acc_bias_noise_x acc_bias_noise_y acc_bias_noise_z 'real' %acc bias noise - m/s^2
syms mag_bias_noise_x mag_bias_noise_y mag_bias_noise_z 'real' %mag bias noise - milligauss
syms baro_bias_noise %baro bias noise - m
syms dt 'real' %measurement time step - s
syms g_n g_e g_d 'real' %NED gravity - m/s^2
syms omega_cov_x omega_cov_y omega_cov_z acc_cov_x acc_cov_y acc_cov_z 'real'; %omega and acc measurement variances
syms omega_bias_cov_x omega_bias_cov_y omega_bias_cov_z acc_bias_cov_x acc_bias_cov_y acc_bias_cov_z 'real'; %omega and acc measurement variances
syms mag_noise_cov_n mag_noise_cov_e mag_noise_cov_d 'real' %mag noise variances- milligauss^2
syms mag_bias_noise_cov_x mag_bias_noise_cov_y mag_bias_noise_cov_z 'real' %mag bias noise variances - milligauss^2
syms baro_bias_noise_cov %variance for baro - m^2
syms rv_n rv_e rv_d 'real' %variances for NED velocity measurements - (m/s)^2
syms rp_n rp_e rp_d 'real' %variances for NED position measurements - m^2
syms rmag_x rmag_y rmag_z 'real' %variance for magnetic flux measurements - milligauss^2
syms rdec 'real' %variance for magnetic declination measurements - rad^2
syms ryaw 'real' %variance for yaw measurements - rad^2
syms rbaro 'real' %variance for baro measurements - m^2

omega_bias_new = [omega_bias_x;omega_bias_y;omega_bias_z] + [omega_bias_noise_x;omega_bias_noise_y;omega_bias_noise_z];
acc_bias_new = [acc_bias_x;acc_bias_y;acc_bias_z] + [acc_bias_noise_x;acc_bias_noise_y;acc_bias_noise_z];

da_bias = omega_bias_new*dt;
dv_bias = acc_bias_new*dt;

da_noise = [omega_noise_x;omega_noise_y;omega_noise_z]*dt;
dv_noise = [acc_noise_x;acc_noise_y;acc_noise_z]*dt;

da_measurement = [omega_x;omega_y;omega_z]*dt;
dv_measurement = [acc_x;acc_y;acc_z]*dt;

da_prev = [da_prev_x;da_prev_y;da_prev_z];
dv_prev = [dv_prev_x;dv_prev_y;dv_prev_z];

tbn = Quat_to_Tbn([q1,q2,q3,q4]);

real_da = da_measurement - da_bias - da_noise + (1/12)*cross(da_prev,da_measurement - da_bias - da_noise);

real_dv = dv_measurement - dv_bias - dv_noise + 0.5*cross(real_da,dv_measurement - dv_bias - dv_noise) + (1/12)*(cross(da_prev,dv_measurement - dv_bias - dv_noise) + cross(dv_prev,real_da));

quat = [q1;q2;q3;q4];

dquat = [1;
    0.5*real_da(1);
    0.5*real_da(2);
    0.5*real_da(3);
    ];
quat_new = QuatMult(quat,dquat);

v_new = [velocity_n;velocity_e;velocity_d] + [g_n;g_e;g_d]*dt + tbn*real_dv;

p_new = [postion_n;postion_e;postion_d] + [velocity_n;velocity_e;velocity_d]*dt + 0.5*real_dv*dt;

mag_n_new = mag_n + mag_noise_n*dt;
mag_e_new = mag_e + mag_noise_e*dt;
mag_d_new = mag_d + mag_noise_d*dt;

mag_bias_x_new = mag_bias_x + mag_bias_noise_x*dt;
mag_bias_y_new = mag_bias_y + mag_bias_noise_y*dt;
mag_bias_z_new = mag_bias_z + mag_bias_noise_z*dt;

baro_bias_new = baro_bias + baro_bias_noise*dt;

process_equation = [quat_new;v_new;p_new;omega_bias_new;acc_bias_new;mag_n_new;mag_e_new;mag_d_new;mag_bias_x_new;mag_bias_y_new;mag_bias_z_new;baro_bias_new];

disp('Complete');

%%generate equations
disp('Derive the state transition matrix');

F = jacobian(process_equation,state_vector);

disp('Set noise to 0');

F = subs(F,{omega_noise_x,omega_noise_y,omega_noise_z,acc_noise_x,acc_noise_y,acc_noise_z,mag_noise_n,mag_noise_e,mag_noise_d,omega_bias_noise_x,omega_bias_noise_y,omega_bias_noise_z,acc_bias_noise_x,acc_bias_noise_y,acc_bias_noise_z,mag_bias_noise_x,mag_bias_noise_y,mag_bias_noise_z,baro_bias_noise},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});

disp('Optimise algebra');

[F,OF] = OptimiseAlgebra(F,'OF');

disp('Complete');

disp('Define the control vector');

dist_vector = [omega_noise_x;omega_noise_y;omega_noise_z;acc_noise_x;acc_noise_y;acc_noise_z;omega_bias_noise_x;omega_bias_noise_y;omega_bias_noise_z;acc_bias_noise_x;acc_bias_noise_y;acc_bias_noise_z;mag_noise_n;mag_noise_e;mag_noise_d;mag_bias_noise_x;mag_bias_noise_y;mag_bias_noise_z;baro_bias_noise];

disp('Complete');

disp('Derive the control influence matrix');

G = jacobian(process_equation,dist_vector);

disp('Set noise to 0');

G = subs(G,{omega_noise_x,omega_noise_y,omega_noise_z,acc_noise_x,acc_noise_y,acc_noise_z,mag_noise_n,mag_noise_e,mag_noise_d,omega_bias_noise_x,omega_bias_noise_y,omega_bias_noise_z,acc_bias_noise_x,acc_bias_noise_y,acc_bias_noise_z,mag_bias_noise_x,mag_bias_noise_y,mag_bias_noise_z,baro_bias_noise},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});

disp('Optimise algebra');

[G,OG] = OptimiseAlgebra(G,'OG');

disp('Complete');

disp('Derive the state error matrix');

noise = diag([omega_cov_x omega_cov_y omega_cov_z acc_cov_x acc_cov_y acc_cov_z  omega_bias_cov_x omega_bias_cov_y omega_bias_cov_z acc_bias_cov_x acc_bias_cov_y acc_bias_cov_z mag_noise_cov_n mag_noise_cov_e mag_noise_cov_d mag_bias_noise_cov_x mag_bias_noise_cov_y mag_bias_noise_cov_z baro_bias_noise_cov]);

disp('Complete');

disp('Calculate Q');

Q = G*noise*transpose(G);

disp('Optimise algebra');

[Q,OQ] = OptimiseAlgebra(Q,'OQ');

disp('Complete');

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

disp('Calculate PP');

PP = F*P*transpose(F) + Q;

%disp('Optimise algebra');

%[PP,OPP] = OptimiseAlgebra(PP,'OPP');

%disp('Complete');

%%derive equations for sequential fusion
disp('Derive equations for sequential fusion');

H_VN = jacobian(velocity_n,state_vector);
K_VN = (P*transpose(H_VN))/(H_VN*P*transpose(H_VN) + rv_n);

H_VE = jacobian(velocity_e,state_vector);
K_VE = (P*transpose(H_VE))/(H_VE*P*transpose(H_VE) + rv_e);

H_VD = jacobian(velocity_d,state_vector);
K_VD = (P*transpose(H_VD))/(H_VD*P*transpose(H_VD) + rv_d);

H_PN = jacobian(postion_n,state_vector);
K_PN = (P*transpose(H_PN))/(H_PN*P*transpose(H_PN) + rp_n);

H_PE = jacobian(postion_e,state_vector);
K_PE = (P*transpose(H_PE))/(H_PE*P*transpose(H_PE) + rp_e);

H_PD = jacobian(postion_d,state_vector);
K_PD = (P*transpose(H_PD))/(H_PD*P*transpose(H_PD) + rp_d);

%combine into a single H and K matrix
H_VP  = [H_VN;H_VE;H_VD;H_PN;H_PE;H_PD];
clear    H_VN H_VE H_VD H_PN H_PE H_PD;
K_VP = [K_VN,K_VE,K_VD,K_PN,K_PE,K_PD];
clear   K_VN K_VE K_VD K_PN K_PE K_PD;
[K_VP,OK_VP] = OptimiseAlgebra(K_VP,'OK_VP');

%derive equations for fusion of magnetic field measurement
mag_measurement = transpose(tbn)*[mag_n;mag_e;mag_d] + [mag_bias_x;mag_bias_y;mag_bias_z]; % predicted measurement
H_MAG = jacobian(mag_measurement,state_vector); % measurement Jacobian
[H_MAG,OH_MAG] = OptimiseAlgebra(H_MAG,'OH_MAG');

K_MX = (P*transpose(H_MAG(1,:)))/(H_MAG(1,:)*P*transpose(H_MAG(1,:)) + rmag_x); % Kalman gain vector
[K_MX,OK_MX] = OptimiseAlgebra(K_MX,'OK_MX');
K_MY = (P*transpose(H_MAG(2,:)))/(H_MAG(2,:)*P*transpose(H_MAG(2,:)) + rmag_y); % Kalman gain vector
[K_MY,OK_MY] = OptimiseAlgebra(K_MY,'OK_MY');
K_MZ = (P*transpose(H_MAG(3,:)))/(H_MAG(3,:)*P*transpose(H_MAG(3,:)) + rmag_z); % Kalman gain vector
[K_MZ,OK_MZ] = OptimiseAlgebra(K_MZ,'OK_MZ');

%derive equations for fusion of magnetic declination measurement
dec_measurement = atan(mag_e/mag_n);
H_DEC = jacobian(dec_measurement,state_vector);
[H_DEC,OH_DEC] = OptimiseAlgebra(H_DEC,'OH_DEC');
K_DEC = (P*transpose(H_DEC))/(H_DEC*P*transpose(H_DEC) + rdec);
[K_DEC,OK_DEC] = OptimiseAlgebra(K_DEC,'OK_DEC');

%derive equations for fusion of yaw (yaw321)
yaw321_measurement = atan(tbn(2,1)/tbn(1,1));
H_YAW321 = jacobian(yaw321_measurement,state_vector);
H_YAW321 = simplify(H_YAW321);
K_YAW321 = (P*transpose(H_YAW321))/(H_YAW321*P*transpose(H_YAW321) + ryaw);
K_YAW321 = simplify(K_YAW321);

%derive equations for fusion of yaw (yaw312)
yaw312_measurement = atan(-tbn(1,2)/tbn(2,2));
H_YAW312 = jacobian(yaw312_measurement,state_vector);
H_YAW312 = simplify(H_YAW312);
K_YAW312 = (P*transpose(H_YAW312))/(H_YAW312*P*transpose(H_YAW312) + ryaw);
K_YAW312 = simplify(K_YAW312);

%derive equations for fusion of baro
baro_measurement = baro_bias - postion_d;
H_BARO = jacobian(baro_measurement,state_vector);
K_BARO = (P*transpose(H_BARO))/(H_BARO*P*transpose(H_BARO) + rbaro);
[K_BARO,OK_BARO] = OptimiseAlgebra(K_BARO,'OK_BARO');

disp('Complete')

file_name = 'ScriptOutput.mat';
save(file_name);

OutputFormater(nstate);
ConvertCode();

disp('Derivation complete');