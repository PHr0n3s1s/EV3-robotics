/* Helper subroutines for automating/simplifying repetive tasks */

void make_beep() {
    playTone(600, 20);
    while (bSoundActive)
        sleep(1);
}

void prepare_grabber() {
    motor[grabber] = -25;
    sleep(8100);
    motor[grabber] = 0;
}
void grab_item() {
    motor[grabber] = 25;
    sleep(8100);
    motor[grabber] = 0;
}


inline void follow_line() {
    if ( SensorValue[color] > ARENA_LINE_COLOR ) {
        motor[leftWheel]  = DEFAULT_SPEED;
        motor[rightWheel] = DEFAULT_SPEED - 10;
    }
    else {
        motor[leftWheel]  = DEFAULT_SPEED - 10;
        motor[rightWheel] = DEFAULT_SPEED;
    }
}


void switch_to_left_lane(int speed) {
    motor[leftWheel]  = -speed;
    motor[rightWheel] =  speed;

    resetGyro( gyro );
    while (
        SensorValue[gyro] > -80 ||
        SensorValue[color] > ARENA_LINE_COLOR
    );  // Do nothing - just keep checking ...

    stop_moving();
}
void switch_to_right_lane(int speed) {
    motor[leftWheel]  =  speed;
    motor[rightWheel] = -speed;

    resetGyro( gyro );
    while (
        SensorValue[gyro] < 80 ||
        SensorValue[color] > ARENA_LINE_COLOR
    );  // Do nothing - just keep checking ...

    stop_moving();
}


char encode_target_position(int gyro_degrees, int distance) {
    if (gyro_degrees >= -40 && distance < 60)
        return 'A';

    else if (gyro_degrees < -40 && distance < 60)
        return 'B';

    else
        return 'C';
}
char scan_object_location() {
    int gyroScan = 0,
        distance = 157;

    motor[leftWheel]  = -10;
    motor[rightWheel] =  10;

    resetGyro(gyro);
    while (
        SensorValue[gyro] > -80 ||
        SensorValue[color] > ARENA_LINE_COLOR
    ) {
        int measure = SensorValue[ultrasonic];

        if (measure < distance){
            distance = measure;
            gyroScan = SensorValue[gyro];
        }
    }
    stop_moving();

    return encode_target_position( gyroScan, distance );
}


