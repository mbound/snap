#ifndef SCHEDULELINUX_HH
#define SCHEDULELINUX_HH
#include <click/element.hh>
#include <click/task.hh>

/*
 * =c
 * ScheduleLinux
 * =s information
 * returns to Linux scheduler
 * =d
 *
 * Returns to Linux's scheduler every time it is scheduled by Click. Use
 * ScheduleInfo to specify how often this should happen.
 *
 * =a ScheduleInfo */

class ScheduleLinux : public Element { public:

  ScheduleLinux();
  ~ScheduleLinux();

  const char *class_name() const		{ return "ScheduleLinux"; }

  int initialize(ErrorHandler *);
  void add_handlers();

  bool run_task(Task *);

 private:

  Task _task;

};

#endif
