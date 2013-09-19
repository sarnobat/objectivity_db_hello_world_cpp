/****************************************************************************
Copyright (c) 1995-2006, 2007 Objectivity, Inc.
All Rights Reserved   

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

The copyright notice above does not evidence any    
actual or intended publication of such source code.

*****************************************************************************/

// This file defines classes for representing dates and times.

#ifndef OO_TIME
#define OO_TIME "@(#)$Id$"

#include <oo.h>
#include <time.h>  // for time_t

class OO_STORAGE_SPECIFIER ooDateTimeOffset;

//-----------------------------------------------------------------------------
// For time & datetime comparison operators
// allow oocUnspecified to be compared with any Kind.
// This is to allow any Kind datetime to compare with datetime literal which 
// is created as unspecified kind. Currently the datetime literal does not 
// have a way to specify the Kind.

#define OO_CHECK_DATETIME_PRECONDITIONS \
   if (isNull() || right.isNull()) throw ooNullOperandException(); \
   if (kind() != ooTime::oocUnspecified && \
      right.kind() != ooTime::oocUnspecified && \
      kind() != right.kind()) \
   { \
         throw ooTimeKindMismatchException(); \
   }

//****************************************************************************
//
// The following contains the time-related class definitions from chapter 5
// of The ODMG-93 1.1 standard, lightly edited for implementation purposes.
//
//****************************************************************************

class OO_STORAGE_SPECIFIER d_Timestamp;
class OO_STORAGE_SPECIFIER d_Interval;

class OO_STORAGE_SPECIFIER d_Time {
  friend class d_Timestamp;
  friend class ooDateTimeOffset;
public:
  enum Time_Zone {
    GMT =   0,
    GMT12 =  12,
    GMT_12  = -12,
    GMT1  =   1,
    GMT_1 =  -1,
    GMT2  =   2,
    GMT_2 =  -2,
    GMT3  =   3,
    GMT_3 =  -3,
    GMT4  =   4,
    GMT_4 =  -4,
    GMT5  =   5,
    GMT_5 =  -5,
    GMT6  =   6,
    GMT_6 =  -6,
    GMT7  =   7,
    GMT_7 =  -7,
    GMT8  =   8,
    GMT_8 =  -8,
    GMT9  =   9,
    GMT_9 =  -9,
    GMT10 =  10,
    GMT_10  = -10,
    GMT11 =  11,
    GMT_11  = -11,
    USeastern =  GMT_5,
    UScentral =  GMT_6,
    USmountain = GMT_7,
    USpacific =  GMT_8
  };
  d_Time();
  d_Time(unsigned short hour, unsigned short minute, float second = 0.0);
  d_Time(unsigned short hour, unsigned short minute, float second, short tz_hour, short tz_minute);
  d_Time(const d_Time &);
  d_Time(const d_Timestamp &);
  d_Time& operator=(const d_Time &);
  d_Time& operator=(const d_Timestamp &);
  unsigned short  hour() const;
  unsigned short  minute() const;
  float second() const;
  short tz_hour() const;
  short tz_minute() const;
  d_Time& operator+=(const d_Interval &);
  d_Time& operator-=(const d_Interval &);
  static void set_default_Time_Zone(Time_Zone);
  static void set_default_Time_Zone_to_local();
  static d_Time current();
  friend OO_STORAGE_SPECIFIER d_Time operator+(const d_Time &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER d_Time operator+(const d_Interval &L, const d_Time &R);
  friend OO_STORAGE_SPECIFIER d_Interval operator-(const d_Time &L,const d_Time &R);
  friend OO_STORAGE_SPECIFIER d_Time operator-(const d_Time &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER int operator==(const d_Time &L, const d_Time &R);
  friend OO_STORAGE_SPECIFIER int operator!=(const d_Time &L, const d_Time &R);
  friend OO_STORAGE_SPECIFIER int operator<(const d_Time &L, const d_Time &R);
  friend OO_STORAGE_SPECIFIER int operator<=(const d_Time &L, const d_Time &R);
  friend OO_STORAGE_SPECIFIER int operator>(const d_Time &L, const d_Time &R);
  friend OO_STORAGE_SPECIFIER int operator>=(const d_Time &L, const d_Time &R);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Time &Ls, const d_Time &Le, const d_Time &Rs, const d_Time &Re);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Timestamp &Ls, const d_Timestamp &Le, const d_Time &Rs, const d_Time &Re);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Time &Ls, const d_Time &Le, const d_Timestamp &Rs, const d_Timestamp &Re);
protected:
  uint32    time_after_midnight_in_milliseconds;
  int16   time_zone_delta_in_minutes;
  static  int16   default_time_zone_delta_in_minutes;
};


class OO_STORAGE_SPECIFIER d_Date {
public:
  enum Weekday {
    Sunday = 0, 
    Monday, 
    Tuesday,  
    Wednesday,
    Thursday,   
    Friday,   
    Saturday
  };
  enum Month {
    January = 1,  
    February,       
    March,    
    April,    
    May,    
    June,
    July, 
    August, 
    September,    
    October,  
    November,         
    December
  };
  d_Date();
  d_Date(unsigned short year, unsigned short day_of_year);
  d_Date(unsigned short year, unsigned short month, unsigned short day);
  d_Date(const d_Date &);
  d_Date(const d_Timestamp &);
  d_Date &  operator=(const d_Date &);
  d_Date &  operator=(const d_Timestamp &);
  unsigned short  year() const;
  d_Date::Month month() const;
  unsigned short  day() const;
  unsigned short  day_of_year() const;
  d_Date::Weekday day_of_week() const;
  d_Date::Month month_of_year() const;
  int is_leap_year() const;
  d_Date& next(d_Date::Weekday);
  d_Date& previous(d_Date::Weekday);
  d_Date& operator+=(const d_Interval &);
  d_Date& operator+=(int num_of_days);
  d_Date& operator++();
  d_Date operator++(int);
  d_Date& operator-=(const d_Interval &);
  d_Date& operator-=(int num_of_days);
  d_Date& operator--();
  d_Date operator--(int);
  int is_between(const d_Date &, const d_Date &) const;
  unsigned int days_in_year() const;
  unsigned int days_in_month() const;
  static d_Date current();
  static int is_leap_year(unsigned short year);
  static unsigned int  days_in_year(unsigned short year);
  static unsigned int  days_in_month(unsigned short year, unsigned short month);
  static int is_valid_date(unsigned short year, unsigned short month, unsigned short day);
  friend OO_STORAGE_SPECIFIER d_Date operator+(const d_Date &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER d_Date operator+(const d_Interval &L, const d_Date &R);
  friend OO_STORAGE_SPECIFIER d_Date operator-(const d_Date &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER int operator==(const d_Date &L, const d_Date &R);
  friend OO_STORAGE_SPECIFIER int operator!=(const d_Date &L, const d_Date &R);
  friend OO_STORAGE_SPECIFIER int operator<(const d_Date &L, const d_Date &R);
  friend OO_STORAGE_SPECIFIER int operator<=(const d_Date &L, const d_Date &R);
  friend OO_STORAGE_SPECIFIER int operator>(const d_Date &L, const d_Date &R);
  friend OO_STORAGE_SPECIFIER int operator>=(const d_Date &L, const d_Date &R);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Date &Ls, const d_Date &Le, const d_Date &Rs, const d_Date &Re);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Timestamp &Ls, const d_Timestamp &Le, const d_Date &Rs, const d_Date &Re);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Date &Ls, const d_Date &Le, const d_Timestamp &Rs, const d_Timestamp &Re);
protected:
  uint16 the_year;
  d_Date::Month the_month;
  uint8 the_day;
};

OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER d_Timestamp {
public:
  d_Timestamp();
  d_Timestamp(unsigned short year, unsigned short month = 1, unsigned short day = 1, unsigned short hour = 0, unsigned short minute = 0, float second = 0.0);
  d_Timestamp(const d_Date &);
  d_Timestamp(const d_Date &, const d_Time &);
  d_Timestamp(const d_Timestamp &);
  d_Timestamp & operator=(const d_Timestamp &);
  d_Timestamp & operator=(const d_Date &);
  const d_Date& date() const;
  const d_Time& time() const;
  unsigned short year() const;
  unsigned short month() const;
  unsigned short day() const;
  unsigned short hour() const;
  unsigned short minute() const;
  float second() const;
  short tz_hour() const;
  short tz_minute() const;
  d_Timestamp & operator+=(const d_Interval &);
  d_Timestamp & operator-=(const d_Interval &);
  static d_Timestamp current();
  friend OO_STORAGE_SPECIFIER d_Timestamp operator+(const d_Timestamp &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER d_Timestamp operator+(const d_Interval &L, const d_Timestamp &R);
  friend OO_STORAGE_SPECIFIER d_Timestamp operator-(const d_Timestamp &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER int operator==(const d_Timestamp &L, const d_Timestamp &R);
  friend OO_STORAGE_SPECIFIER int operator!=(const d_Timestamp &L, const d_Timestamp &R);
  friend OO_STORAGE_SPECIFIER int operator<(const d_Timestamp &L, const d_Timestamp &R);
  friend OO_STORAGE_SPECIFIER int operator<=(const d_Timestamp &L, const d_Timestamp &R);
  friend OO_STORAGE_SPECIFIER int operator>(const d_Timestamp &L, const d_Timestamp &R);
  friend OO_STORAGE_SPECIFIER int operator>=(const d_Timestamp &L, const d_Timestamp &R);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Timestamp &Ls, const d_Timestamp &Le, const d_Timestamp &Rs, const d_Timestamp &Re);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Timestamp &Ls, const d_Timestamp &Le, const d_Date &Rs, const d_Date &Re);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Date &Ls, const d_Date &Le, const d_Timestamp &Rs, const d_Timestamp &Re);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Timestamp &Ls, const d_Timestamp &Le, const d_Time &Rs, const d_Time &Re);
  friend OO_STORAGE_SPECIFIER int overlaps(const d_Time &Ls, const d_Time &Le, const d_Timestamp &Rs, const d_Timestamp &Re);
  friend class ooDateTimeOffset;

protected:
  d_Date the_date;
  d_Time the_time;
};

class OO_STORAGE_SPECIFIER d_Interval {
  friend class d_Time;
  friend class d_Date;
  friend class d_Timestamp;
public:
  d_Interval(int days = 0, int hours = 0, int minutes = 0, float second = 0.0);
  d_Interval(const d_Interval &);
  d_Interval &  operator=(const d_Interval &);
  int day() const;
  int hour() const;
  int minute() const;
  float second() const;
  int is_zero() const;
  d_Interval& operator+=(const d_Interval &);
  d_Interval& operator-=(const d_Interval &);
  d_Interval& operator*=(int);
  d_Interval& operator/=(int);
  d_Interval operator-() const;
  friend OO_STORAGE_SPECIFIER d_Interval  operator+(const d_Interval &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER d_Interval  operator-(const d_Interval &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER d_Interval  operator*(const d_Interval &L, int R);
  friend OO_STORAGE_SPECIFIER d_Interval  operator*(int L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER d_Interval  operator/(const d_Interval &L, int R);
  friend OO_STORAGE_SPECIFIER int operator==(const d_Interval &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER int operator!=(const d_Interval &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER int operator<(const d_Interval &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER int operator<=(const d_Interval &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER int operator>(const d_Interval &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER int operator>=(const d_Interval &L, const d_Interval &R);
  friend OO_STORAGE_SPECIFIER d_Interval operator-(const d_Timestamp &hi, const d_Timestamp &lo);
protected:
  void normalize();
  int32 the_days;
  int32 the_milliseconds;
};

// End of ODMG classes



// This class is for compatibility with the .NET type System.DateTime
// where time is represented in 100-nanosecond ticks since the year 1 AD.
OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooDotNetDateTime {
protected:
  ooUInt64 ticks_and_kind;
public:
  enum Kind { Unspecified = 0, Utc = 1, Local = 2 };
  ooUInt64 ticks() const{ return ticks_and_kind >> 2; }
  Kind kind() const { return (Kind)((int)ticks_and_kind & 3); }
  void set_ticks(ooUInt64 ticks, Kind kind) {
    ticks_and_kind = (ticks << 2) | (int)kind;
  }
  // The following methods convert to and from the Unix time representation.
  void set_c_time(unsigned long seconds, unsigned microseconds = 0);
  unsigned long get_c_seconds() const;
  unsigned get_microseconds() const;
};

struct ooSQLdate;
struct ooSQLtime;
struct ooSQLtimestamp ;
class ooSQLnull_date;
class ooSQLnull_time;
class ooSQLnull_timestamp;
class oojDate;
class oojTime;
class oojTimestamp;

//****************************************************************************
//
// The following Objectivity classes are preferred over the ODMG classes.
//
//****************************************************************************


//-----------------------------------------------------------------------------
// An exception that represents an attempt to compare or perform arithmatic
// when the time kinds of the two operands do not match.
class ooTimeKindMismatchException : public ooException 
{
   public:

      ooTimeKindMismatchException() {}

      const char* what() const OO_WHAT_THROW_NONE
      {return "Time kinds do not match";}

};

//-----------------------------------------------------------------------------
// An exception that represents an attempt to compare or perform arithmatic
// when either or both operands are null.
class ooNullOperandException : public ooException 
{
   public:

      ooNullOperandException() {}

      const char* what() const OO_WHAT_THROW_NONE
      {return "Null operand";}

};

//-----------------------------------------------------------------------------
// An exception that represents an attempt to convert
class ooUnableToConvertDateTimeException : public ooSimpleException 
{
   public:
      ooUnableToConvertDateTimeException(const char* reason)
         : ooSimpleException(reason) {}
};

//-----------------------------------------------------------------------------
// An ooInterval object represents a time interval, or duration of time, 
// measured as a positive or negative number of days, hours, minutes, seconds,
// and fractions of a second. The largest unit of time used to measure
// duration is a day. Time intervals are measured in days for consistency
// because the number of days in larger units of time, such as months and
// years, varies.   This structure takes 8 bytes.
// Outside of assignment, an ooInterval instance is considered immutable and 
// operations that return an ooInterval value do so by value.
class OO_STORAGE_SPECIFIER ooInterval
{
   public:

      // Default constructor; creates a null interval.
      ooInterval() : mTicks(smNullTicksValue) {}

      // Constructor taking a number of ticks.
      ooInterval(int64 ticks) : mTicks(ticks << 1) {}

      // Constructors taking specific time amounts.
      ooInterval(int hours, int minutes, int seconds);
      ooInterval(int days, int hours, int minutes, int seconds);
      ooInterval(int days, int hours, int minutes, int seconds, 
         int milliseconds);

      // Constructor taking a d_Interval
      ooInterval(const d_Interval& source);

      // Conversion operation to d_Interval
      void convert(d_Interval& dest) const;

      // Returns true if this is a null time; false otherwise.
      bool isNull() const
      {return mTicks == smNullTicksValue;}

      // Returns the number of tikes used to represent the time span.
      int64 ticks() const
      {return mTicks >> 1;}

      // Returns the number of days.
      int days() const
      {return days(ticks());}

      // Returns the number of hours.
      int hours() const
      {return hours(ticks());}

      // Returns the number of minutes.
      int minutes() const
      {return minutes(ticks());}

      // Returns the number of seconds (0 to 59).
      int seconds() const
      {return seconds(ticks());}

      // Returns partial seconds as milliseconds (0 to 999).
      int milliseconds() const
      {return milliseconds(ticks());}

      // Returns partial seconds as microseconds (0 to 999999).
      int32 microseconds() const
      {return microseconds(ticks());}

      // Returns the total number of days as a float.
      float64 totalDays() const
      {return (float64)ticks() / TicksPerDay;}

      // Returns the total number of hours as a float.
      float64 totalHours() const
      {return (float64)ticks() / TicksPerHour;}

      // Returns the total number of minutes as a float.
      float64 totalMinutes() const
      {return (float64)ticks() / TicksPerMinute;}

      // Returns the total number of seconds as a float.
      float64 totalSeconds() const
      {return (float64)ticks() / TicksPerSecond;}

      // Returns the duration represented by the timespan.
      ooInterval duration() const;

      // Returns a timespan that is the negation of this one.
      ooInterval negate() const;

      // Addition operator.
      ooInterval operator+(const ooInterval& right) const;
      // Subtraction operator.
      ooInterval operator-(const ooInterval& right) const;

      // Comparison operators.
      bool operator==(const ooInterval& right) const;
      bool operator!=(const ooInterval& right) const;
      bool operator<(const ooInterval& right) const;
      bool operator<=(const ooInterval& right) const;
      bool operator>(const ooInterval& right) const;
      bool operator>=(const ooInterval& right) const;

      // Returns a timespan given a number of days.
      static ooInterval fromDays(float64 value);

      // Returns a timespan given a number of hours.
      static ooInterval fromHours(float64 value);

      // Returns a timespan given a number of minutes.
      static ooInterval fromMinutes(float64 value);

      // Returns a timespan given a number of seconds.
      static ooInterval fromSeconds(float64 value);

      // Returns a timespan given a number of milliseconds.
      static ooInterval fromMilliseconds(float64 value);

      // Min and max interval values.
                static const ooInterval MinValue;
                static const ooInterval Zero;
                static const ooInterval MaxValue;

      // Tick values
      static const int64 TicksPerDay;
      static const int64 TicksPerHour;
      static const int64 TicksPerMinute;
      static const int64 TicksPerSecond;
      static const int64 TicksPerMillisecond;
      static const int64 TicksPerMicrosecond;

      static const int64 MinTicksValue;
      static const int64 MaxTicksValue;

   private:

      static const int64 smNullTicksValue;

      int64 mTicks;

      static int64 calculateTicks
         (int days, int hours, int minutes, int seconds, int32 microseconds);

      static int days(int64 tks) 
      {return (int)(tks / TicksPerDay);}

      static int hours(int64 tks)
      {return (int)((tks % TicksPerDay) / TicksPerHour);}

      static int minutes(int64 tks) 
      {return (int)((tks % TicksPerHour) / TicksPerMinute);}

      static int seconds(int64 tks) 
      {return (int)((tks % TicksPerMinute) / TicksPerSecond);}

      static int milliseconds(int64 tks) 
      {return (int)((tks % TicksPerSecond) / TicksPerMillisecond);}

      static int32 microseconds(int64 tks) 
      {return (int)((tks % TicksPerSecond) / TicksPerMicrosecond);}

      static ooInterval from(float64 value, int64 tickMultiplicator);

      friend class ooDateTime;
};

//-----------------------------------------------------------------------------
// ooDate represents dates ranging from
// 1-1-0001 to 31-12-9999 Common Era.
// This structure takes 4 bytes.
// Outside of assignment, an ooDate instance is considered immutable and 
// operations that return an ooDate value do so by value.
class OO_STORAGE_SPECIFIER ooDate
{
   public:

      enum DayOfWeek 
         {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

      // Default constructor; creates a null date.
      ooDate();     

      // Constructor taking a specific date.
      ooDate(int year, int month, int day);     

      // Constructors taking various persistent date types
      ooDate(const d_Date& source);
      ooDate(const ooSQLdate& source);
      ooDate(const ooSQLnull_date& source);

      // Constructor taking a number of ticks
      ooDate(uint32 ticks) : mTicks(ticks << 1) {}

      // Conversion operations to various persistent date types
      void convert(d_Date& dest) const;
      void convert(ooSQLdate& dest) const;
      void convert(ooSQLnull_date& dest) const;

      // Assignment operator
      ooDate& operator=(const ooDate& other)
      {mTicks = other.mTicks; return *this;}

      // Methods that return date values.
      int year() const;
      int month() const;
      int day() const;
      DayOfWeek dayOfWeek() const
      {return (DayOfWeek) ((ticks() + 1) % 7);}
      int dayOfYear() const;

      // Returns true if this is a null date; false otherwise.
      bool isNull() const
      {return mTicks == smNullTicksValue;}

      uint32 ticks() const
      {return mTicks >> 1;}

      // Comparison operators.
      bool operator==(const ooDate& right) const;
      bool operator!=(const ooDate& right) const;
      bool operator<(const ooDate& right) const;
      bool operator<=(const ooDate& right) const;
      bool operator>(const ooDate& right) const;
      bool operator>=(const ooDate& right) const;

      // Arithmatic operators that return a date time.
      ooDate operator+(const ooInterval& right) const;
      ooDate operator-(const ooInterval& right) const;

      // Arithmatic operator that return an interval.
      ooInterval operator-(const ooDate& right) const;

      // Operations that return a date time representing some value added to 
      // this date time's value.
      ooDate addYears(int years) const;
      ooDate addMonths(int months) const;
      ooDate addDays(int days) const;

      // Returns an ooDate instance that represents today's date.
      static ooDate today();

      // General date information.
      static bool isLeapYear(int year);
      static int daysInMonth(int year, int month);

      // Min a max date values.
                static const ooDate MaxValue;
                static const ooDate MinValue;

      // Tick values
      static const uint32 TicksPerDay;

      static const uint32 MinTicksValue;
      static const uint32 MaxTicksValue;

   private:

      static const uint32 smDaysPer400Years;
      static const uint32 smDaysPer100Years;
      static const uint32 smDaysPer4Years;

      static const uint32 smDaysInMonth[];
      static const uint32 smDaysInMonthLY[];
      static const uint32 smDaysPreceedingMonth[];
      static const uint32 smDaysPreceedingMonthLY[];
      static const uint32 smNullTicksValue;

      uint32 mTicks;

      void init(int year, int month, int day);     

      static int getYear(uint32& days);
      static int getMonth(uint32& days);
      static int getDay(uint32& days);

      friend class ooDateTime;

};

//-----------------------------------------------------------------------------
// ooTime represents times ranging from 00:00:00 (12:00:00 AM) to 
// 23:59:99.9999 (11:59:99.9999 AM) with 100us resolution.
// This structure takes 4 bytes.
// Outside of assignment, an ooTime instance is considered immutable and 
// operations that return an ooTime value do so by value.
class OO_STORAGE_SPECIFIER ooTime
{
   public:

      enum Kind {oocUnspecified = 0, oocUtc = 1, oocLocal = 2};

      // Default constructor; creates a null time.
      ooTime();     

      // Constructor taking a number of ticks
      ooTime(uint32 ticks) { initChecked(ticks, oocUnspecified); }

      // Constructor taking a number of ticks and a kind.
      ooTime(uint32 ticks, Kind kind) { initChecked(ticks, kind); }

      // Constructors taking specific dates and times and an optional kind.
      ooTime(int hour, int minute, int second, Kind kind = oocLocal);     
      ooTime(int hour, int minute, int second, int millisecond, 
             Kind kind = oocLocal);     

#if !defined(OO_DDL_TRANSLATION) // ooRef in argument confuses DDL compiler
      // Constructors taking various persistent time types
      ooTime(const d_Time& source);
      ooTime(const ooSQLtime& source);
      ooTime(const ooSQLnull_time& source);
      ooTime(const oojTime& source);
      ooTime(const ooRef(oojTime)& sourceRef);

      // Conversion operations to various persistent time types
      void convert(d_Time& dest) const;
      void convert(ooSQLtime& dest) const;
      void convert(ooSQLnull_time& dest) const;
      void convert(ooRef(oojTime)& destref, ooHandle(ooObj)& parent) const;
      void convert(oojTime& dest) const;
#endif

      // Methods that return time values. 
      int hour() const
      {return ticks() / TicksPerHour;}
      int minute() const
      {return (ticks() % TicksPerHour) / TicksPerMinute;}
      int second() const
      {return (ticks() % TicksPerMinute) / TicksPerSecond;}
      int millisecond() const
      {return (ticks() % TicksPerSecond) / TicksPerMillisecond;}

      // Returns the number of ticks use to represent the date/time.
      uint32 ticks() const
      {return mTicks >> 2;}

      // Returns true if this is a null time; false otherwise.
      bool isNull() const
      {return mTicks == smNullTicksValue;}

      // Returns the kind of time (oocUnspecified, oocUtc, or oocLocal).
      Kind kind() const 
      {return (isNull())? oocUnspecified : (Kind)((uint32)mTicks & 3);}

      // Comparison operators.
      bool operator==(const ooTime& right) const;
      bool operator!=(const ooTime& right) const;
      bool operator<(const ooTime& right) const;
      bool operator<=(const ooTime& right) const;
      bool operator>(const ooTime& right) const;
      bool operator>=(const ooTime& right) const;

      // Arithmatic operators.
      ooTime operator+(const ooInterval& right) const;
      ooTime operator-(const ooInterval& right) const;

      // Note that it is assumed that the times are not more than
      // a day apart, as date information is not present.  
      // Furthermore, it is assumed that the time being subtracted
      // is prior to this time. If these issues are important then 
      // it is recommended that you use ooDateTime instead.
      ooInterval operator-(const ooTime& right) const;

      // Operations that return a time representing some value added to 
      // this time's value.
      ooTime addHours(float hours) const;
      ooTime addMinutes(float minutes) const;
      ooTime addSeconds(float seconds) const;
      ooTime addMilliseconds(float milliseconds) const;
      ooTime addTicks(int64 ticks) const;

      // Methods that return the current time.
      static ooTime now();
      static ooTime utcNow();

      // Min a max time values.
                static const ooTime MinValue;
                static const ooTime MaxValue;

      // Tick values
      static const uint32 TicksPerHour;
      static const uint32 TicksPerMinute;
      static const uint32 TicksPerSecond;
      static const uint32 TicksPerMillisecond;

      static const uint32 MinTicksValue;
      static const uint32 MaxTicksValue;

   private:

      static const uint32 smNullTicksValue;

      uint32 mTicks;

      static uint32 calculateTicks
         (int hours, int minutes, int seconds, int milliseconds);

      void init(uint32 tks, Kind kind)
      {mTicks = (tks << 2) | (uint32)kind;}

      void initChecked(uint32 tks, Kind kind);

      void initJavaTime(const oojTime& jTime);

};

//-----------------------------------------------------------------------------
// ooDateTime represents dates and time ranging from
// 1-1-0001 12:00:00 AM to 31-12-9999 23:59:00 Common Era with
// 100ns resolution.
// This structure takes 8 bytes.
// Outside of assignment, an ooDateTime instance is considered immutable and 
// operations that return an ooDateTime value do so by value.
class OO_STORAGE_SPECIFIER ooDateTime : public ooDotNetDateTime
{
   public:

      // Default constructor; creates a null date time.
      ooDateTime();     

      // Constructor taking a date.
      ooDateTime(const ooDate& date);     

      // Constructor taking a time.
      ooDateTime(const ooTime& time);     

      // Constructor taking a date and time.
      ooDateTime(const ooDate& date, const ooTime& time);     

      // Constructors taking specific dates and times and an optional kind.
      ooDateTime(int year, int month, int day);     
      ooDateTime(int year, int month, int day, int hour, 
         int minute, int second, ooTime::Kind kind = ooTime::oocLocal);     
      ooDateTime(int year, int month, int day, int hour, 
         int minute, int second, int millisecond, 
         ooTime::Kind kind = ooTime::oocLocal);     

      // Constructor taking a number of ticks and a kind.
      ooDateTime(int64 ticks, ooTime::Kind kind);     

#if !defined(OO_DDL_TRANSLATION) // ooRef in argument confuses DDL compiler
      // Constructors taking various persistent date time types
      ooDateTime(const ooDotNetDateTime& source);
      ooDateTime(const d_Timestamp& source);
      ooDateTime(const ooSQLtimestamp& source);
      ooDateTime(const ooSQLnull_timestamp& source);
      ooDateTime(const oojDate& source);
      ooDateTime(const oojTimestamp& source);
      ooDateTime(const ooRef(oojDate)& sourceref);
      ooDateTime(const ooRef(oojTimestamp)& sourceref);
      // The following takes a POSIX compliant time_t.
      ooDateTime(time_t posixTime, int32 microsecond);

      // Conversion operations to various persistent date time types
      void convert(d_Timestamp& dest) const;
      void convert(ooSQLtimestamp& dest) const;
      void convert(ooSQLnull_timestamp& dest) const;
      void convert(ooDotNetDateTime& dest) const;
      void convert(ooRef(oojDate)& destref, ooHandle(ooObj)& parent) const;
      void convert(oojDate& dest) const;
      void convert(ooRef(oojTimestamp)& destref, ooHandle(ooObj)& parent) const;
      void convert(oojTimestamp& dest) const;
#endif
      // The following takes a POSIX compliant time_t.
      void convert(time_t& posixTime, long& microsecond);

      // Returns true if this is a null date time; false otherwise.
      bool isNull() const
      {return ticks_and_kind == smNullTicksValue;}

      // Returns the kind of time (oocUnspecified, oocUtc, or oocLocal).
      ooTime::Kind kind() const 
      {return (isNull())? ooTime::oocUnspecified : 
       (ooTime::Kind)((int)ticks_and_kind & 3);}

      // Returns the number of ticks use to represent the date/time.
      // inherited from ooDotNetDateTime
      // uint64 ticks() const {return ticks_and_kind >> 2;}

      // Methods that return date values.
      ooDate date() const
      {return ooDate(year(), month(), day());}
      int year() const;
      int month() const;
      int day() const;
      ooDate::DayOfWeek dayOfWeek() const
      {return (ooDate::DayOfWeek) ((ooInterval::days(ticks()) + 1) % 7);}
      int dayOfYear() const;

      // Methods that return time values. 
      ooTime timeOfDay() const;
      int hour() const
      {return ooInterval::hours(ticks());}
      int minute() const
      {return ooInterval::minutes(ticks());}
      int second() const
      {return ooInterval::seconds(ticks());}
      int millisecond() const
      {return ooInterval::milliseconds(ticks());}

      // Comparison operators.
      bool operator==(const ooDateTime& right) const;
      bool operator!=(const ooDateTime& right) const;
      bool operator<(const ooDateTime& right) const;
      bool operator<=(const ooDateTime& right) const;
      bool operator>(const ooDateTime& right) const;
      bool operator>=(const ooDateTime& right) const;

      // Operations that return a date time representing some value added to 
      // this date time's value.
      ooDateTime addYears(int years) const;
      ooDateTime addMonths(int months) const;
      ooDateTime addDays(float64 days) const;
      ooDateTime addHours(float64 hours) const;
      ooDateTime addMinutes(float64 minutes) const;
      ooDateTime addSeconds(float64 seconds) const;
      ooDateTime addMilliseconds(float64 milliseconds) const;
      ooDateTime addTicks(int64 ticks) const;

      // Arithmatic operators that return a date time.
      ooDateTime operator+(const ooInterval& right) const;
      ooDateTime operator-(const ooInterval& right) const;

      // Arithmatic operator that return an interval.
      ooInterval operator-(const ooDateTime& right) const;

      // Methods that return the current time.
      static ooDateTime now();
      static ooDateTime utcNow();
      static ooDate today();

      // Min a max date time values.
                static const ooDateTime MaxValue;
                static const ooDateTime MinValue;

      // Tick values
      static const uint64 TicksPerDay;
      static const uint64 TicksPerHour;
      static const uint64 TicksPerMinute;
      static const uint64 TicksPerSecond;
      static const uint64 TicksPerMillisecond;
      static const uint64 TicksPerMicrosecond;

      static const uint64 MaxTicksValue;
      static const uint64 MinTicksValue;

   private:

      static const uint64 smUnixEpochTicks;
      static const uint64 smNullTicksValue;

      static void getLocalTimeZone(int& hours, int& minutes);

   protected:
      void init(int year, int month, int day, int hour, 
                int minute, int second, int millisecond, 
                ooTime::Kind kind);     
      void init(uint64 ticks, ooTime::Kind kind);     
   private:
      void initJavaDateTime(int64 milliseconds, int32 nanoseconds);     
      void init(oojDate& source);
      void init(oojTimestamp& source);

      friend class ooTime;
};

// Class ooDateTimeOffset represents a date, time, and time zone, where
// the time zone is represented as the difference of local time from UTC.
// Positive offsets are minutes east of Greenwich, while negative offsets
// are minutes west.
class OO_STORAGE_SPECIFIER ooDateTimeOffset : public ooDateTime
{
private:
  ooInt16 offset_minutes_east;
public:
  ooDateTimeOffset() : offset_minutes_east(0) { }
  ooDateTimeOffset(const ooDateTime& dt);
  ooDateTimeOffset(const ooDateTime& dt, const ooInterval& offset);
  ooDateTimeOffset(const ooDateTime& dt, int offset_minutes)
    : ooDateTime(dt), offset_minutes_east((ooInt16)offset_minutes) { }
  ooDateTimeOffset(int year, int month, int day, int hour, 
                   int minute, int second = 0, int millisecond = 0);
  ooDateTimeOffset(int64 ticks, const ooInterval& offset);
  ooDateTimeOffset(int64 ticks, int offset_minutes)
    : ooDateTime(ticks, ooTime::oocLocal),
      offset_minutes_east((ooInt16)offset_minutes) { }

  ooDateTimeOffset(const d_Timestamp& source);

  int offsetMinutes() const { return offset_minutes_east; }
  ooInterval offsetInterval() const
    { return ooInterval(0, offset_minutes_east, 0); }
  static ooDateTimeOffset now();
  static ooDateTimeOffset utcNow();

  void convert(d_Timestamp& dest) const;

  bool operator==(const ooDateTimeOffset& right) const;
  bool operator!=(const ooDateTimeOffset& right) const;
  bool operator<(const ooDateTimeOffset& right) const;
  bool operator<=(const ooDateTimeOffset& right) const;
  bool operator>(const ooDateTimeOffset& right) const;
  bool operator>=(const ooDateTimeOffset& right) const;

  ooDateTimeOffset addYears(int years) const;
  ooDateTimeOffset addMonths(int months) const;
  ooDateTimeOffset addDays(float64 days) const;
  ooDateTimeOffset addHours(float64 hours) const;
  ooDateTimeOffset addMinutes(float64 minutes) const;
  ooDateTimeOffset addSeconds(float64 seconds) const;
  ooDateTimeOffset addMilliseconds(float64 milliseconds) const;
  ooDateTimeOffset addTicks(int64 ticks) const;

  ooDateTimeOffset operator+(const ooInterval& right) const;
  ooDateTimeOffset operator-(const ooInterval& right) const;

  ooInterval operator-(const ooDateTimeOffset& right) const;
private:
  uint64 normalizedTicks() const;
};

#if defined(OO_DDL_TRANSLATION)
#pragma ooassign d_Time           ooc_d_TimeTypeN
#pragma ooassign d_Date           ooc_d_DateTypeN
#pragma ooassign d_Timestamp      ooc_d_TimestampTypeN
#pragma ooassign d_Interval       ooc_d_IntervalTypeN
#pragma ooassign ooDotNetDateTime oocDotNetDateTimeTypeN
#pragma ooassign ooDateTime       oocDateTimeTypeN
#pragma ooassign ooDateTimeOffset oocDateTimeOffsetTypeN
#pragma ooassign ooDate           oocDateTypeN
#pragma ooassign ooTime           oocTimeTypeN
#pragma ooassign ooInterval       oocIntervalTypeN
#endif

#endif
