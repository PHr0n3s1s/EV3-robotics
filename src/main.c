/*
 * For better modularization and organization, the source-files have been splitted into multiple.
 * (The actual code being uploaded to the robot is placed into a single file)
 *
 * Title: Robotics EV3 Microcontroller RobotC challenge code
 * Date: 2024-4-2
 * License: GPL3
*/

#pragma config(Sensor, S1, color, sensorEV3_Color)
#pragma config(Sensor, S2, gyro,  sensorEV3_Gyro)
#pragma config(Sensor, S4, ultrasonic, sensorEV3_Ultrasonic)
#pragma config(Motor, motorB, rightWheel, tmotorEV3_Large,  PIDControl, encoder)
#pragma config(Motor, motorC, leftWheel,  tmotorEV3_Large,  PIDControl, encoder)
#pragma config(Motor, motorD, grabber,    tmotorEV3_Medium, PIDControl, encoder)


/* Global Constants: -------------------------------------------------- */

const int DEFAULT_SPEED = 25;
const int ARENA_LINE_COLOR = 10;


/* Main function: ----------------------------------------------------- */

task main() {
    begin();

    switch( scan_object_location() ) {
        case 'A':
            target_A();
            break;

        case 'B':
            target_B();
            break;

        case 'C':
            target_C();
            break;
  }
}


