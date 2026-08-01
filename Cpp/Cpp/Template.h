#pragma once

template<class T>
T Add(T value1, T value2)
{
	T addValue = value1 + value2;

	return addValue;
}

template<class T>
T Subtraction(T value1, T value2)
{
	T minusValue = value1 - value2;

	return minusValue;
}

template<class T>
T MultiPlication(T value1, T value2)
{
	T multiValue = value1 * value2;

	return multiValue;
}

template<class T>
T Divide(T value1, T value2)
{
	T divideValue = value1 / value2;

	return divideValue;
}