/* Subroutines which allow the robot to navigate the arena */

void keep_moving_forward(int speed) {
    motor[leftWheel] = motor[rightWheel] = speed;
}

void stop_moving() {
    motor[leftWheel] = motor[rightWheel] = 0;
}

void keep_moving_until_sonar_less_than(int cmDistance) {
    while (SensorValue[ultrasonic] > cmDistance)
        follow_line();
    stop_moving();
}

void moveN(int n) {
    nMotorEncoder[leftWheel] = 0;
    while ( nMotorEncoder[leftWheel] < n )
        follow_line();

    stop_moving();
}

void finish_line() {
    while (SensorValue[ultrasonic] > 66)
        follow_line();

    keep_moving_forward(25);
    while (SensorValue[ultrasonic] > 19);   // Solves the arena bump issue ...

    stop_moving();
}

void begin() {
    keep_moving_forward( 15 );

    // Wait until robot detects the arena line:
    while ( SensorValue[color] > ARENA_LINE_COLOR );    // Do nothing - just keep checking ...
    stop_moving();

    make_wide_turn();
    keep_moving_until_sonar_less_than(11);

    switch_to_left_lane(10);
    keep_moving_until_sonar_less_than(156);
}

void make_wide_turn() {
    resetGyro( gyro );
    int color_value = 0;

    do {
        color_value = SensorValue[color];

        if ( color_value <= ARENA_LINE_COLOR )	// If robot is in-line ...
            keep_moving_forward( 10 );
        else {
            motor[leftWheel]  = 10;
            motor[rightWheel] =  0;
        }
    }
    while ( !( (SensorValue[gyro] > 80) && (color_value <= ARENA_LINE_COLOR) ) );	// Should end when the turn has been completed, and the robot remains on line ...

    stop_moving();
}


