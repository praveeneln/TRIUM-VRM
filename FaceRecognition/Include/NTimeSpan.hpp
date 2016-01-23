#ifndef N_TIME_SPAN_HPP_INCLUDED
#define N_TIME_SPAN_HPP_INCLUDED

#include <NTypes.hpp>
#include <NError.hpp>
namespace Neurotec
{
#include <NTimeSpan.h>
}
#if defined(N_FRAMEWORK_MFC)
	#include <atltime.h>
	typedef CTimeSpan NTimeSpanType;
#elif defined(N_FRAMEWORK_WX)
	#include <wx/datetime.h>
	typedef wxTimeSpan NTimeSpanType;
#elif defined(N_FRAMEWORK_QT)
	#include <QTime>
	typedef QTime NTimeSpanType;
#endif

namespace Neurotec
{
#undef N_TIME_SPAN_TICKS_PER_MILLISECOND
#undef N_TIME_SPAN_TICKS_PER_SECOND
#undef N_TIME_SPAN_TICKS_PER_MINUTE
#undef N_TIME_SPAN_TICKS_PER_HOUR
#undef N_TIME_SPAN_TICKS_PER_DAY

const NLong N_TIME_SPAN_TICKS_PER_MILLISECOND =        10000LL;
const NLong N_TIME_SPAN_TICKS_PER_SECOND      =     10000000LL;
const NLong N_TIME_SPAN_TICKS_PER_MINUTE      =    600000000LL;
const NLong N_TIME_SPAN_TICKS_PER_HOUR        =  36000000000LL;
const NLong N_TIME_SPAN_TICKS_PER_DAY         = 864000000000LL;

class N_CLASS(NTimeSpan)
{
	N_DECLARE_COMPARABLE_BASIC_CLASS(NTimeSpan)

public:
	static bool IsTimeValid(NInt days, NInt hours, NInt minutes, NInt seconds, NInt milliseconds)
	{
		return NTimeSpanIsTimeValid(days, hours, minutes, seconds, milliseconds) != 0;
	}

	static N_CLASS(NTimeSpan) FromTicks(NLong value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromTicks(value, &v));
		return N_CLASS(NTimeSpan)(v);
	}

	static N_CLASS(NTimeSpan) FromDays(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromDays(value, &v));
		return N_CLASS(NTimeSpan)(v);
	}

	static N_CLASS(NTimeSpan) FromHours(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromHours(value, &v));
		return N_CLASS(NTimeSpan)(v);
	}

	static N_CLASS(NTimeSpan) FromMinutes(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromMinutes(value, &v));
		return N_CLASS(NTimeSpan)(v);
	}

	static N_CLASS(NTimeSpan) FromSeconds(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromSeconds(value, &v));
		return N_CLASS(NTimeSpan)(v);
	}

	static N_CLASS(NTimeSpan) FromMilliseconds(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromMilliseconds(value, &v));
		return N_CLASS(NTimeSpan)(v);
	}

	static NInt Compare(N_CLASS(NTimeSpan) value1, N_CLASS(NTimeSpan) value2)
	{
		NInt result;
		NCheck(NTimeSpanCompare(value1.value, value2.value, &result));
		return result;
	}

	N_CLASS(NTimeSpan)(NInt days, NInt hours, NInt minutes, NInt seconds, NInt milliseconds)
	{
		NCheck(NTimeSpanCreate(days, hours, minutes, seconds, milliseconds, &value));
	}

#if defined(N_FRAMEWORK_MFC)
	N_CLASS(NTimeSpan)(CTimeSpan value)
	{
		NLong theValue = (NLong)(value.GetTimeSpan());
		if (theValue < N_TIME_SPAN_MIN / N_TIME_SPAN_TICKS_PER_SECOND || N_TIME_SPAN_MAX / N_TIME_SPAN_TICKS_PER_SECOND < theValue) NThrowOverflowException();
		this->value = theValue * N_TIME_SPAN_TICKS_PER_SECOND;
	}
#elif defined(N_FRAMEWORK_WX)
	N_CLASS(NTimeSpan)(wxTimeSpan value)
	{
		NLong theValue = (NLong)value.GetMilliseconds().GetValue();
		if (theValue < N_TIME_SPAN_MIN / N_TIME_SPAN_TICKS_PER_MILLISECOND || N_TIME_SPAN_MAX / N_TIME_SPAN_TICKS_PER_MILLISECOND < theValue) NThrowOverflowException();
		this->value = theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND;
	}
#elif defined(N_FRAMEWORK_QT)
	N_CLASS(NTimeSpan)(QTime value)
	{
		this->value = QTime().msecsTo(value) * N_TIME_SPAN_TICKS_PER_MILLISECOND;
	}
#endif

	bool IsValid() const
	{
		return NTimeSpanIsValid(value) != 0;
	}

	N_CLASS(NTimeSpan) Add(N_CLASS(NTimeSpan) value) const
	{
		NTimeSpan_ result;
		NCheck(NTimeSpanAdd(this->value, value.value, &result));
		return N_CLASS(NTimeSpan)(result);
	}

	N_CLASS(NTimeSpan) Subtract(N_CLASS(NTimeSpan) value) const
	{
		NTimeSpan_ result;
		NCheck(NTimeSpanSubtract(this->value, value.value, &result));
		return N_CLASS(NTimeSpan)(result);
	}

	NInt CompareTo(N_CLASS(NTimeSpan) value) const
	{
		NInt result;
		NCheck(NTimeSpanCompare(this->value, value.value, &result));
		return result;
	}

	N_CLASS(NTimeSpan) Negate() const
	{
		NTimeSpan_ result;
		NCheck(NTimeSpanNegate(this->value, &result));
		return N_CLASS(NTimeSpan)(result);
	}

	N_CLASS(NTimeSpan) Duration() const
	{
		NTimeSpan_ result;
		NCheck(NTimeSpanDuration(this->value, &result));
		return N_CLASS(NTimeSpan)(result);
	}

	void Decode(NInt * pDays, NInt * pHours, NInt * pMinutes, NInt * pSeconds, NInt * pMilliseconds) const
	{
		NCheck(NTimeSpanDecode(value, pDays, pHours, pMinutes, pSeconds, pMilliseconds));
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NTimeSpanToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	NLong GetTicks() const
	{
		NLong value;
		NCheck(NTimeSpanGetTicks(this->value, &value));
		return value;
	}

	NInt GetDays() const
	{
		NInt value;
		NCheck(NTimeSpanGetDays(this->value, &value));
		return value;
	}

	NInt GetHours() const
	{
		NInt value;
		NCheck(NTimeSpanGetHours(this->value, &value));
		return value;
	}

	NInt GetMinutes() const
	{
		NInt value;
		NCheck(NTimeSpanGetMinutes(this->value, &value));
		return value;
	}

	NInt GetSeconds() const
	{
		NInt value;
		NCheck(NTimeSpanGetSeconds(this->value, &value));
		return value;
	}

	NInt GetMilliseconds() const
	{
		NInt value;
		NCheck(NTimeSpanGetMilliseconds(this->value, &value));
		return value;
	}

	NDouble GetTotalDays() const
	{
		NDouble value;
		NCheck(NTimeSpanGetTotalDays(this->value, &value));
		return value;
	}

	NDouble GetTotalHours() const
	{
		NDouble value;
		NCheck(NTimeSpanGetTotalHours(this->value, &value));
		return value;
	}

	NDouble GetTotalMinutes() const
	{
		NDouble value;
		NCheck(NTimeSpanGetTotalMinutes(this->value, &value));
		return value;
	}

	NDouble GetTotalSeconds() const
	{
		NDouble value;
		NCheck(NTimeSpanGetTotalSeconds(this->value, &value));
		return value;
	}

	NDouble GetTotalMilliseconds() const
	{
		NDouble value;
		NCheck(NTimeSpanGetTotalMilliseconds(this->value, &value));
		return value;
	}

	N_CLASS(NTimeSpan) operator+(const N_CLASS(NTimeSpan) & value) const
	{
		return Add(value);
	}

	N_CLASS(NTimeSpan) operator-(const N_CLASS(NTimeSpan) & value) const
	{
		return Subtract(value);
	}

	N_CLASS(NTimeSpan) operator-() const
	{
		return Negate();
	}

	N_CLASS(NTimeSpan) operator+() const
	{
		return *this;
	}

#if defined(N_FRAMEWORK_MFC)
	operator CTimeSpan() const
	{
		NLong theValue = value / N_TIME_SPAN_TICKS_PER_SECOND;
		if (value >= 0 && value - theValue * N_TIME_SPAN_TICKS_PER_SECOND >= N_TIME_SPAN_TICKS_PER_SECOND / 2)
		{
			theValue++;
		}
		else if (value < 0 && value - theValue * N_TIME_SPAN_TICKS_PER_SECOND <= -N_TIME_SPAN_TICKS_PER_SECOND / 2)
		{
			theValue--;
		}
		return CTimeSpan((__time64_t)theValue);
	}
#elif defined(N_FRAMEWORK_WX)
	operator wxTimeSpan() const
	{
		NLong theValue = value / N_TIME_SPAN_TICKS_PER_MILLISECOND;
		if (theValue < N_INT_MIN || theValue > N_INT_MAX) NThrowOverflowException();
		if (value >= 0 && value - theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND >= N_TIME_SPAN_TICKS_PER_MILLISECOND / 2)
		{
			if (theValue == N_INT_MAX) NThrowOverflowException();
			theValue++;
		}
		else if (value < 0 && value - theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND <= -N_TIME_SPAN_TICKS_PER_MILLISECOND / 2)
		{
			if (theValue == N_INT_MIN) NThrowOverflowException();
			theValue--;
		}
		return wxTimeSpan::Milliseconds((long)theValue);
	}
#elif defined(N_FRAMEWORK_QT)
	operator QTime() const
	{
		NLong theValue = value / N_TIME_SPAN_TICKS_PER_MILLISECOND;
		if (theValue < -86400000 || theValue > 86400000) NThrowOverflowException();
		if (value >= 0 && value - theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND >= N_TIME_SPAN_TICKS_PER_MILLISECOND / 2)
		{
			if (theValue > 86400000) NThrowOverflowException();
			theValue++;
		}
		else if (value < 0 && value - theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND <= -N_TIME_SPAN_TICKS_PER_MILLISECOND / 2)
		{
			if (theValue < -86400000) NThrowOverflowException();
			theValue--;
		}
		return QTime().addMSecs((int)theValue);
	}
#endif
};
N_TYPEDEF_TYPE(NTimeSpan)

#undef N_TIME_SPAN_MIN
#undef N_TIME_SPAN_MAX
const N_CLASS(NTimeSpan) N_TIME_SPAN_MIN(N_LONG_MIN);
const N_CLASS(NTimeSpan) N_TIME_SPAN_MAX(N_LONG_MAX);
}

#endif // !N_TIME_SPAN_HPP_INCLUDED
