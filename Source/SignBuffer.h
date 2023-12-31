#pragma once
class SignBuffer
{
public:
	SignBuffer() : SignBuffer(100) {};
	SignBuffer(const unsigned int newLength);

	bool WriteSignToBuffer(const bool sign);
	double GetPitch(const double sampleRate);

private:
	static const unsigned int threshold;

	bool* signs;
	unsigned int length;
	unsigned int maxUsableIndex;
	unsigned int writePointer;
	double currentPeriod = 0.0f;

	double CalculatePeriod();
	unsigned int ModifiedAutocorrelation(const unsigned int lag);
	bool GetSignAtOffsetIndex(const unsigned int index);
};

