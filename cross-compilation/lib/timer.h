#ifndef TIMER_H
#define TIMER_H

void timer_start(int time);
void timer_stop();
void timer_sleep(int time);

void buzzer_start(int periode);
void buzzer_end();
void buzzer(int periode, int time);

#endif

