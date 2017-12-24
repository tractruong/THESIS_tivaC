/*
 * Inverse.c
 *
 *  Created on: Nov 13, 2017
 *      Author: tungduongbk
 */

#include "../include.h"
#include "INVERSE.h"

float const baseRadius = 81;
float const platformRadius = 69;
float const hornLength = 22;
float const legLength = 170;
// alpha i
float alpha[6];
float xb[6], yb[6], zb[6];
float xp[6], yp[6], zp[6];
float q_x[6], q_y[6], q_z[6]; // position vector q[i]
float l_x[6], l_y[6], l_z[6]; // vector l[i]

void Inverse(float Roll, float Pitch, float Yaw) {
  int i =0;
  float baseAngles[] = {
    291, 7, 52, 128, 173, 249 };

  float platformAngles[] = {
    317.5, 343, 76.5, 103.5, 197, 222.5 };

  double beta[] = {
    -PI, 2 * PI / 3, -PI / 3, -2 * PI / 3, PI / 3, 0 };

  for (i = 0; i<6; i++) {
            xb[i] = baseRadius*cos(val*(baseAngles[i]));
            yb[i] = baseRadius*sin(val*(baseAngles[i]));
            zb[i] = 0;

            xp[i] = platformRadius*cos(val*(platformAngles[i]));
            yp[i] = platformRadius*sin(val*(platformAngles[i]));
            zp[i] = 0;

          float xqxb = xp[i] - xb[i];
          float yqyb = yp[i] - yb[i];
          float h0 = sqrt((legLength*legLength) + (hornLength*hornLength) - (xqxb*xqxb) - (yqyb*yqyb)) - zp[i];
            // rotation
            q_x[i] = cos(val*Yaw)*cos(val*Pitch)*xp[i] +
              (-sin(val*Yaw)*cos(val*Roll) + cos(val*Yaw)*sin(val*Pitch)*sin(val*Roll))*yp[i] +
              (sin(val*Yaw)*sin(val*Roll) + cos(val*Yaw)*sin(val*Pitch)*cos(val*Roll))*zp[i];

            q_y[i] = sin(val*Yaw)*cos(val*Pitch)*xp[i] +
              (cos(val*Yaw)*cos(val*Roll) + sin(val*Yaw)*sin(val*Pitch)*sin(val*Roll))*yp[i] +
              (-cos(val*Yaw)*sin(val*Roll) + sin(val*Yaw)*sin(val*Pitch)*cos(val*Roll))*zp[i];

            q_z[i] = -sin(val*Pitch)*xp[i] +
              cos(val*Pitch)*sin(val*Roll)*yp[i] +
              cos(val*Pitch)*cos(val*Roll)*zp[i];

            //translation
            q_x[i] = q_x[i]  + 0;
            q_y[i] = q_y[i]  + 0;
            q_z[i] = q_z[i]  + h0;

            l_x[i] = q_x[i] - xb[i];
            l_y[i] = q_y[i] - yb[i];
            l_z[i] = q_z[i] - zb[i];

            float L = ((l_x[i])*(l_x[i]) + (l_y[i])*(l_y[i]) + (l_z[i])*(l_z[i])) - (legLength*legLength) + (hornLength*hornLength);
            float M = 2 * hornLength*(q_z[i] - zb[i]);
            float N = 2 * hornLength*(cos(beta[i])*(q_x[i] - xb[i]) + sin(beta[i])*(q_y[i] - yb[i]));

            alpha[i] = asin(L / sqrt(M*M + N*N)) - atan2(N, M);
          }
    }

float GetAlpha(int i){
      float temp = 180*alpha[i]/PI;
      if(temp >= 70)
      {
        return 70;
      }
      else if(temp <= -70)
      {
        return -70;
      }
      else
      {
      return temp;
      }
   }
