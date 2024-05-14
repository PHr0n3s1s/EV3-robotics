/*
	Subroutines leading the robot to the item on each target position.
	(Go grabs the item, and brings it to the finish location)
*/

void target_A() {
    switch_to_right_lane(10);
    keep_moving_until_sonar_less_than(123);

    switch_to_left_lane(10);
    grab_item();
    switch_to_right_lane(10);

    finish_line();
    prepare_grabber();
}

void target_B() {
    nMotorEncoder[leftWheel] = 0;
    while ( (nMotorEncoder[leftWheel] < 950) || (SensorValue[ultrasonic] > 40) )
        follow_line();
    stop_moving();

    switch_to_right_lane(10);

    grab_item();
    switch_to_right_lane(10);

    keep_moving_until_sonar_less_than(11);
    switch_to_left_lane(10);

    finish_line();
    prepare_grabber();
}

void target_C() {
    keep_moving_until_sonar_less_than(6.5);
    switch_to_right_lane(10);

    moveN(1500);
    keep_moving_until_sonar_less_than(86);
    switch_to_right_lane(10);

    grab_item();
    switch_to_right_lane(10);

    keep_moving_until_sonar_less_than(59);
    switch_to_left_lane(10);

    keep_moving_until_sonar_less_than(10);
    switch_to_left_lane(10);

    finish_line();
    prepare_grabber();
}


