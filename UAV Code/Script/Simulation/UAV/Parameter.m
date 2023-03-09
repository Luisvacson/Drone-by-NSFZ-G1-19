%%Motor
Motor_Init_RPM = 557.1420;
Motor_Cr = 737.24;
Motor_Wb = 161.87;
Motor_Tm = 0.0895;
Motor_Jm = 2.13e-4;

%%Rotor
Rotor_Ct = 1.051e-5;
Rotor_Cm = 1.789e-7;

%%Body
Body_Cd = 0.228;
Body_Mass = 1.5;
Body_R = 0.225;
Body_Jxx = 1.663e-2;
Body_Jyy = 1.663e-2;
Body_Jzz = 3.033e-2;
Body_J = [Body_Jxx,0,0;0,Body_Jyy,0;0,0,Body_Jzz];
Body_G = [0,0,9.8];

THR = (sqrt(Body_Mass*Body_G/4/Rotor_Ct)-Motor_Wb)/Motor_Cr;